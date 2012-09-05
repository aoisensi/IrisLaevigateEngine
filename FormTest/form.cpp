#define _CRT_NON_CONFORMING_SWPRINTFS 1 // VisualC++2005 での警告抑制
#define _CRT_SECURE_NO_DEPRECATE 1      // VisualC++2005 での警告抑制

#include <Windows.h>
#include <tchar.h>
#include <time.h>
#include "IrisLaevigataEngine.h"

using namespace IL;

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
BOOL SetClientSize(HWND hWnd, int width, int height);
void Show(LPVOID LPhDC);
void Rendering(LPVOID hWnd);

const int AA = 1;
const int bmpx = 320;
const int bmpy = 240;
const double rolspd = 1; 

static ILZBuffer render;
static double camdist = 500;
static ILROTATION camdir = ILROTATION();
static ILBITMAP Bitmap = ILBITMAP(bmpx, bmpy);
static ILSPACE Space = ILSPACE(256, 0, 0);
static int keydata = 0;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPInst, LPSTR lpCmd, int nCmd)
{

	WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = MsgProc;
		wc.cbClsExtra = 0L;
		wc.cbWndExtra = 0L;
		wc.hInstance = hInst;
		wc.hIcon = NULL;
		wc.hCursor = NULL;
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = _T("ilformtest");
		wc.hIconSm = NULL;

	if(!RegisterClassEx( &wc ))
	{
		return 0;
	}

	HWND hWnd = CreateWindow( _T("ilformtest"), _T("WindowName"), WS_VISIBLE | WS_SYSMENU , 100, 100, 100, 100, NULL, NULL, hInst, NULL );
	
	if(!SetClientSize(hWnd,bmpx,bmpy))
	{
		return 0;
	}



	ShowWindow( hWnd, SW_SHOWDEFAULT);

	//msgloop

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while(msg.message != WM_QUIT)
	{
		if( PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	UnregisterClass(_T("ilformtest"), hInst);
	return 0;
}

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )  
{
	static BITMAPINFO   bmpinfo;    // ビットマップ情報
	static LPDWORD      lpPixel;    // ピクセル配列
	static HBITMAP      hBitmap;    // ビットマップ
	static HDC          hMemDC;     // オフスクリーン

	switch(msg)
	{
	case WM_CREATE:
		{
			HDC hDC;
			bmpinfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			bmpinfo.bmiHeader.biWidth = +bmpx;
			bmpinfo.bmiHeader.biHeight = -bmpy;
			bmpinfo.bmiHeader.biPlanes = 1;
			bmpinfo.bmiHeader.biBitCount = 32;
			bmpinfo.bmiHeader.biCompression = BI_RGB;

			hDC = GetDC(hWnd);
			hMemDC = CreateCompatibleDC(hDC);
			hBitmap = CreateDIBSection(NULL, &bmpinfo, DIB_RGB_COLORS, (LPVOID*)&lpPixel, NULL, 0);
			SelectObject(hMemDC, hBitmap);
			ReleaseDC(hWnd,hDC);

			SetTimer(hWnd, 1, 30, NULL);
			return 0;
		}
	case  WM_CLOSE:
		{
			DeleteDC(hMemDC);
			DeleteObject(hBitmap);
			DestroyWindow(hWnd);
			return 0;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hDC;
			hDC = BeginPaint(hWnd, &ps);
			BitBlt(hDC, 0, 0, bmpx, bmpy, hMemDC, 0, 0, SRCCOPY);
			EndPaint(hWnd, &ps);
			return 0;
		}
	case WM_TIMER:
		{
			switch(wParam)
			{
			case (1):
				{
					for(int i=0;i<bmpx;++i)
					{
						for(int j=0;j<bmpy;++j)
						{
							ILCOLOR bit = Bitmap.PGet(i,j);
							lpPixel[(i) + j * bmpx] = bit.b * 0x00000001 + bit.g * 0x00000100 + bit.r * 0x00010000;
						}
					}
					InvalidateRect(hWnd, NULL, FALSE);
				}
			}
			return 0;
		}
	}
	return 0;
}

BOOL SetClientSize(HWND hWnd, int width, int height)
{
	RECT rw, rc;
	::GetWindowRect(hWnd, &rw);
	::GetClientRect(hWnd, &rc);

	int new_width = (rw.right - rw.left) - (rc.right - rc.left) + width;
	int new_height = (rw.bottom - rw.top) - (rc.bottom - rc.top) + height;

	return ::SetWindowPos(hWnd, NULL, 0, 0, new_width, new_height, SWP_NOMOVE | SWP_NOZORDER);
}

void Rendering(LPVOID hWnd)
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		camdir.y = ILANGLE(camdir.y.angle + rolspd);
	}
	if(GetAsyncKeyState(VK_UP))
	{
		camdir.x = ILANGLE(camdir.x.angle + rolspd);
	}
	if(GetAsyncKeyState(VK_RIGHT))
	{
		camdir.y = ILANGLE(camdir.y.angle - rolspd);
	}
	if(GetAsyncKeyState(VK_DOWN))
	{
		camdir.x = ILANGLE(camdir.x.angle - rolspd);
	}
	TCHAR str[256];
	_stprintf(str,_T("x:%d y:%d"),camdir.y.angle,camdir.x.angle);
	SetWindowText((HWND)hWnd,str);
	render.Rendering(Space, ILCAMERA(10,10000,camdir,-ILVECTOR(camdir.Direction(),camdist),ILANGLE(45),ILANGLE(45/4*3),ILCOLOR(0,0,255)),Bitmap);
	ExitThread(TRUE);
	return;
}
