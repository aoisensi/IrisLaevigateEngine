#define _CRT_NON_CONFORMING_SWPRINTFS 1 // VisualC++2005 での警告抑制
#define _CRT_SECURE_NO_DEPRECATE 1      // VisualC++2005 での警告抑制

#include <Windows.h>
#include <tchar.h>
#include <time.h>
#include "IrisLaevigataEngine.h"

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
BOOL SetClientSize(HWND hWnd, int width, int height);
void Show(LPVOID LPhDC);
void Rendering(LPVOID hWnd);

const int AA = 1;
const int bmpx = 320;
const int bmpy = 240;

static bool endflag = false;

static ILBITMAP Bitmap = ILBITMAP(bmpx, bmpy);
static ILBITMAP Picture = ILBITMAP(bmpx, bmpy);
static IL::Rendering::Toon render = IL::Rendering::Toon(Picture);
static ILTSPACE Space = ILTSPACE(1000);

static ILCAMERA Camera = ILCAMERA(0.01F,100000.0F,ILROTATION(0,0,0), ILVECTOR(0,150.0F,-1000.0F), ILANGLE(M_DEGREE * 45), ILANGLE(M_DEGREE * 45*4/3));


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
		return 1;
	}

	HWND hWnd = CreateWindow( _T("ilformtest"), _T("WindowName"), WS_VISIBLE | WS_SYSMENU , 100, 100, 100, 100, NULL, NULL, hInst, NULL );
	
	if(!SetClientSize(hWnd,bmpx,bmpy))
	{
		return 1;
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
	static HANDLE hRender;

	TCHAR str[256];

	switch(msg)
	{
	case WM_CREATE:
		{
			DWORD dwParam;
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
			hRender = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Rendering, hWnd, 0, &dwParam);
			
			Space.AddSurface(ILTSURFACE(ILSURFACE(-100,0,0,0,100,0,100,0,0),0,ILCOLOR(255,0,0),1));
			Space.AddSurface(ILTSURFACE(ILSURFACE(-100,0,0,100,0,0,0,100,0),0,ILCOLOR(255,0,0),1));

			/*
			const double uwaa = 100;
			const double uwaaa = 50;
			const int www = 5;
			for(int i=-www;i<www;++i)
			{
				for(int j=-www;j<www;++j)
				{
					ILVECTOR a, b, c, d;
					a = ILVECTOR(uwaa*IL::ILMath::Cos(i/www*M_PI) + uwaaa*IL::ILMath::Cos(i/www*M_PI)*IL::ILMath::Cos(j/www*M_PI), uwaaa*IL::ILMath::Sin(j/www), uwaa*IL::ILMath::Sin(i/www*M_PI) + uwaaa*IL::ILMath::Sin(i/www*M_PI)*IL::ILMath::Sin(j/www*M_PI));
					b = ILVECTOR(uwaa*IL::ILMath::Cos((i+1)/www*M_PI) + uwaaa*IL::ILMath::Cos((i+1)/www*M_PI)*IL::ILMath::Cos(j/www*M_PI), uwaaa*IL::ILMath::Sin(j/www), uwaa*IL::ILMath::Sin((i+1)/www*M_PI) + uwaaa*IL::ILMath::Sin((i+1)/www*M_PI)*IL::ILMath::Sin(j/www*M_PI));
					c = ILVECTOR(uwaa*IL::ILMath::Cos(i/www*M_PI) + uwaaa*IL::ILMath::Cos(i/www*M_PI)*IL::ILMath::Cos((j+1)/www*M_PI), uwaaa*IL::ILMath::Sin((j+1)/www), uwaa*IL::ILMath::Sin(i/www*M_PI) + uwaaa*IL::ILMath::Sin(i/www*M_PI)*IL::ILMath::Sin((j+1)/www*M_PI));
					d = ILVECTOR(uwaa*IL::ILMath::Cos((i+1)/www*M_PI) + uwaaa*IL::ILMath::Cos((i+1)/www*M_PI)*IL::ILMath::Cos((j+1)/www*M_PI), uwaaa*IL::ILMath::Sin((j+1)/www), uwaa*IL::ILMath::Sin((i+1)/www*M_PI) + uwaaa*IL::ILMath::Sin((i+1)/www*M_PI)*IL::ILMath::Sin((j+1)/www*M_PI));
					Space.AddSurface(ILTSURFACE(ILSURFACE(a,b,c),1.0F,ILCOLOR(255,0,0),1));
					Space.AddSurface(ILTSURFACE(ILSURFACE(b,c,d),1.0F,ILCOLOR(255,0,0),1));
				}
			}
			*/

			return 0;
		}
	case  WM_CLOSE:
		{
			endflag = true;
			WaitForSingleObject(hRender, INFINITE);
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
					if(GetAsyncKeyState(VK_LEFT))
					{
						Camera.rotation.y = ILANGLE(Camera.rotation.y.angle + M_PI/100);
					}
					if(GetAsyncKeyState(VK_UP))
					{
						Camera.rotation.x = ILANGLE(Camera.rotation.x.angle - M_PI/100);
					}
					if(GetAsyncKeyState(VK_RIGHT))
					{
						Camera.rotation.y = ILANGLE(Camera.rotation.y.angle - M_PI/100);
					}
					if(GetAsyncKeyState(VK_DOWN))
					{
						Camera.rotation.x = ILANGLE(Camera.rotation.x.angle + M_PI/100);
					}
					_stprintf(str, _T("%f,%f"), Camera.rotation.x.Frequency(), Camera.rotation.y.Frequency());
					SetWindowText((HWND)hWnd, str);
				}
			}
			return 0;
		}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
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
	while(!endflag)
	{
		Bitmap.Fill(ILCOLOR(0,0,255));
		render.Rendering(Space, Camera);
		Bitmap = Picture;
	}
	ExitThread(TRUE);
	return;
}
