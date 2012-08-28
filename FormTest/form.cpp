#define _CRT_NON_CONFORMING_SWPRINTFS 1 // VisualC++2005 での警告抑制
#define _CRT_SECURE_NO_DEPRECATE 1      // VisualC++2005 での警告抑制

#include <Windows.h>
#include <tchar.h>
#include <time.h>
#include "IrisLaevigataEngine.h"
#include "bitmap.h"

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
BOOL SetClientSize(HWND hWnd, int width, int height);
void Show(LPVOID LPhDC);


const int AA = 1;
const int bmpx = 640;
const int bmpy = 480;
ILBITMAP bmp = ILBITMAP(bmpx*AA,bmpy*AA);
ILBITMAP picture = ILBITMAP(bmpx,bmpy);
IL::ILRaytracing Render;
ILSPACE MainSpace(16,0,16);
ILCAMERA Camera = ILCAMERA(1,1000,ILROTATION(0,0,0),ILVECTOR(0,0,-800),ILANGLE(45),ILANGLE(45/4*3),ILCOLOR(0,0,255));
int starttime;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPInst, LPSTR lpCmd, int nCmd)
{
	MainSpace.AddBall(ILVBALL(ILBALL(ILVECTOR(100,10,20),300),ILCOLOR(255,0,0)));
	MainSpace.AddBall(ILVBALL(ILBALL(ILVECTOR(-100,20,-20),300),ILCOLOR(0,255,0)));
	MainSpace.AddSurface(ILVSURFACE(ILSURFACE(0,-20,-1000,1000,-20,0,-1000,-20,0),ILCOLOR(128,128,128)));
	Render.Rendering(MainSpace,Camera,bmp);
	bmp.Reduction(AA,picture);
	bmp.dispose();
	MainSpace.dispose();

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
	picture.dispose();
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

	switch( msg )
	{
	case WM_CREATE:
		{
			SetTimer(hWnd, 1, 30, NULL);
			return 0;
		}

	case WM_TIMER:
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
			
			for (int i = 0;i < bmpx;i++)
			{
				for (int j = 0;j < bmpy;j++)
				{

					ILCOLOR bit = picture.PGet(i,j);
					lpdwPixel[(i) + (bmpy - j - 1) * bmpx] = bit.b * 0x00000001 + bit.g * 0x00000100 + bit.r * 0x00010000;

				}
			}
			

			InvalidateRect(hWnd, NULL, FALSE);

			return 0;
		}
	case WM_PAINT:
		{
			hDC = BeginPaint(hWnd,&ps);

			/* DIBSectionを表示 */
			BitBlt(hDC, 0, 0, bmpx, bmpy, hdcBMP, 0, 0, SRCCOPY);

			EndPaint(hWnd, &ps);

			return 0;
		}
	case WM_DESTROY:
		{
			PostQuitMessage( 0 );  
			/* DIBSectionをメモリデバイスコンテキストの選択から外す */
			SelectObject(hdcBMP, hbmpOld);

			/* DIBSectionを削除 */
			DeleteObject(hbmpBMP);

			/* メモリデバイスコンテキストを削除 */
			DeleteDC(hdcBMP);
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
