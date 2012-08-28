/*
  CreateDIBSectionによる汎用ビットマップ

           2005/ 3/24 宍戸　輝光
*/
#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInstance;
HWND g_hwMain;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow) {

	MSG  msg;
	WNDCLASS wndclass;

	/* プロセスのハンドルを保存 */
	g_hInstance = hInstance;

	/* アプリケーションのウインドウクラス設定 */
	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = hInstance;
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName  = NULL;
	wndclass.lpszClassName = _T("DIBSEC");

	/* ウインドウクラス登録 */
	RegisterClass(&wndclass);

	/* ウインドウ作成 */
	g_hwMain = CreateWindow(_T("DIBSEC"), NULL, 
	            WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
                CW_USEDEFAULT, CW_USEDEFAULT, 400, 320, 
	            NULL, NULL, hInstance, NULL);

	/* ウインドウを表示 */
	ShowWindow(g_hwMain, iCmdShow);
	UpdateWindow(g_hwMain);

	/* メッセージループ */
	while (GetMessage(&msg, NULL, 0, 0)) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	HDC hdc;
	PAINTSTRUCT ps;

	static HBITMAP hbmpBMP, hbmpOld;
	static HDC hdcBMP;

	static BITMAPINFO biBMP;

	static LPDWORD lpdwPixel;

	int i, j;
	int iX, iY;

	TCHAR aszTmp[64];

	switch (iMsg) {

	case WM_CREATE:

		ZeroMemory(&biBMP, sizeof(biBMP));

		/* 256*256ピクセル、32ビットDIB用BITMAPINFO設定 */
		biBMP.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		biBMP.bmiHeader.biBitCount = 32;
		biBMP.bmiHeader.biPlanes = 1;
		biBMP.bmiHeader.biWidth = 256;
		biBMP.bmiHeader.biHeight = -256;

		/* DIBSection作成 */
		hbmpBMP = CreateDIBSection(NULL, &biBMP, DIB_RGB_COLORS, (void **)(&lpdwPixel), NULL, 0);

		/* ウインドウのHDC取得 */
		hdc = GetDC(hwnd);

		/* DIBSection用メモリデバイスコンテキスト作成 */
		hdcBMP = CreateCompatibleDC(hdc);

		/* ウインドウのHDC解放 */
		ReleaseDC(hwnd, hdc);

		/* DIBSectionのHBITMAPをメモリデバイスコンテキストに選択 */
		hbmpOld = (HBITMAP)SelectObject(hdcBMP, hbmpBMP);

		/* DIBSectionにグラデーション描画 */
		for (i = 0;i < 256;i++) {
			for (j = 0;j < 32;j++) {

				/* DIBピクセル列に直接アクセス */
				lpdwPixel[i + j * 256] = (i << 16);
				lpdwPixel[i + (j + 32) * 256] = (i << 8);
				lpdwPixel[i + (j + 64) * 256] = i;
				lpdwPixel[i + (j + 96) * 256] = (i << 16) | (i << 8) | i;


			}
		}

		return 0;

	case WM_MOUSEMOVE:

		/* マウスカーソル座標取得 */
		iX = LOWORD(lParam);
		iY = HIWORD(lParam);

		if (iX > 255 || iY > 255) {
			return 0;
		}

		/* マウスカーソル位置のピクセルRGBをピクセル列&GDIから取得し、文字列化 */
		_stprintf(aszTmp, _T("(%d, %d) - Buf:%08x GDI:%08x"), iX, iY, lpdwPixel[iX + iY * 256], GetPixel(hdcBMP, iX, iY));

		/* ピクセルのRGBをタイトルバーに表示 */
		SetWindowText(hwnd, aszTmp);

		return 0;

	case WM_PAINT:

		hdc = BeginPaint(hwnd,&ps);

		/* DIBSectionを表示 */
		BitBlt(hdc, 0, 0, 256, 256, hdcBMP, 0, 0, SRCCOPY);

		EndPaint(hwnd, &ps);

		return 0;

	case WM_DESTROY:

		PostQuitMessage(0);

		/* DIBSectionをメモリデバイスコンテキストの選択から外す */
		SelectObject(hdcBMP, hbmpOld);

		/* DIBSectionを削除 */
		DeleteObject(hbmpBMP);

		/* メモリデバイスコンテキストを削除 */
		DeleteDC(hdcBMP);

		return 0;

	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

