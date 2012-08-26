#include <Windows.h>
#include <tchar.h>
#include "IrisLaevigataEngine.h"

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
BOOL SetClientSize(HWND hWnd, int width, int height);

const int AA = 4;
const int bmpx = 640;
const int bmpy = 480;
ILBITMAP bmp = ILBITMAP(bmpx*AA,bmpy*AA);
ILBITMAP picture = ILBITMAP(bmpx,bmpy);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPInst, LPSTR lpCmd, int nCmd)
{

	ILSPACE MainSpace(0,0,16);
	ILCOLOR Black = ILCOLOR(0,0,0);
	MainSpace.AddBall(ILVBALL(ILBALL(ILVECTOR(100,10,20),300),ILCOLOR(255,0,0)));
	MainSpace.AddBall(ILVBALL(ILBALL(ILVECTOR(-100,20,-20),300),ILCOLOR(0,255,0)));
	ILCAMERA Camera = ILCAMERA(1,1000,ILROTATION(0,0,0),ILVECTOR(0,0,-800),ILANGLE(45),ILANGLE(45/4*3),ILCOLOR(0,0,255));
	IL::ILRaytracing* Rendering = new IL::ILRaytracing();
	Rendering->Rendering(MainSpace,Camera,bmp);
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
	switch( msg )  
	{  
	case WM_DESTROY:
		PostQuitMessage( 0 );  
		return 0;
	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint( hWnd, &ps );
		for(int i = 0;i<picture.x;++i)
		{
			for(int j = 0;j<picture.y;++j)
			{
				ILCOLOR bit = picture.PGet(i,j);
				SetPixelV(hDC,i,j,RGB(bit.r,bit.g,bit.b));
			}
		}
		return 0;
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