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
	HDC hDC;
	PAINTSTRUCT ps;

	static HBITMAP hbmpBMP, hbmpOld;
	static HDC hdcBMP;

	static BITMAPINFO biBMP;

	static LPDWORD lpdwPixel;

	DWORD dwParam;

	switch( msg )
	{
	case WM_CREATE:
		{
			render.CreateBuffer(bmpx, bmpy);
			Space.AddSurface(ILVSURFACE(ILSURFACE(10,0,-50,-100,0,-50,10,100,50),ILCOLOR(255,0,0)));
			Space.AddSurface(ILVSURFACE(ILSURFACE(100,0,50,-10,0,50,-10,100,-50),ILCOLOR(0,255,0)));
			SetTimer(hWnd, 1, 30, NULL);
			SetTimer(hWnd, 2, 100, NULL);
			return 0;
		}

	case WM_TIMER:
		{
			switch(wParam)
			{
			case 1:
				{
					ZeroMemory(&biBMP, sizeof(biBMP));

					biBMP.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
					biBMP.bmiHeader.biBitCount = 32;
					biBMP.bmiHeader.biPlanes = 1;
					biBMP.bmiHeader.biWidth = bmpx;
					biBMP.bmiHeader.biHeight = bmpy;

					hbmpBMP = CreateDIBSection(NULL, &biBMP, DIB_RGB_COLORS, (void **)(&lpdwPixel), NULL, 0);

					hDC = GetDC(hWnd);

					hdcBMP = CreateCompatibleDC(hDC);

					ReleaseDC(hWnd, hDC);

					hbmpOld = (HBITMAP)SelectObject(hdcBMP, hbmpBMP);
					DeleteObject(hbmpOld);


					for (int i = 0;i < bmpx;i++)
					{
						for (int j = 0;j < bmpy;j++)
						{
							ILCOLOR bit = Bitmap.PGet(i,j);
							lpdwPixel[(i) + (bmpy - j - 1) * bmpx] = bit.b * 0x00000001 + bit.g * 0x00000100 + bit.r * 0x00010000;
						}
					}
					InvalidateRect(hWnd, NULL, FALSE);
				}
			case 2:
				{
					if(WAIT_TIMEOUT != WaitForSingleObject(hWnd, 0))
					{
						CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Rendering, hWnd, 0, &dwParam);
					}
				}
			}

			return 0;
		}
	case WM_PAINT:
		{
			hDC = BeginPaint(hWnd,&ps);

			/* DIBSectionを表示 */
			BitBlt(hDC, 0, 0, bmpx, bmpy, hdcBMP, 0, 0, SRCCOPY);

			EndPaint(hWnd, &ps);

			DeleteDC(hdcBMP);
			DeleteObject(hbmpBMP);

			return 0;
		}
	case WM_DESTROY:
		{
			KillTimer(hWnd, 1);
			KillTimer(hWnd, 2);
			PostQuitMessage( 0 );  
			/* DIBSectionをメモリデバイスコンテキストの選択から外す */
			SelectObject(hdcBMP, hbmpOld);

			/* DIBSectionを削除 */
			DeleteObject(hbmpBMP);

			/* メモリデバイスコンテキストを削除 */
			DeleteDC(hdcBMP);
			Bitmap.dispose();
			Space.dispose();
			render.dispouse();
			return 0;
		}
	}
	return( DefWindowProc( hWnd, msg, wParam, lParam) );  
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
