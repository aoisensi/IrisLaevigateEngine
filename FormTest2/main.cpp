/*
  CreateDIBSection�ɂ��ėp�r�b�g�}�b�v

           2005/ 3/24 ���ˁ@�P��
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

	/* �v���Z�X�̃n���h����ۑ� */
	g_hInstance = hInstance;

	/* �A�v���P�[�V�����̃E�C���h�E�N���X�ݒ� */
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

	/* �E�C���h�E�N���X�o�^ */
	RegisterClass(&wndclass);

	/* �E�C���h�E�쐬 */
	g_hwMain = CreateWindow(_T("DIBSEC"), NULL, 
	            WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
                CW_USEDEFAULT, CW_USEDEFAULT, 400, 320, 
	            NULL, NULL, hInstance, NULL);

	/* �E�C���h�E��\�� */
	ShowWindow(g_hwMain, iCmdShow);
	UpdateWindow(g_hwMain);

	/* ���b�Z�[�W���[�v */
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

		/* 256*256�s�N�Z���A32�r�b�gDIB�pBITMAPINFO�ݒ� */
		biBMP.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		biBMP.bmiHeader.biBitCount = 32;
		biBMP.bmiHeader.biPlanes = 1;
		biBMP.bmiHeader.biWidth = 256;
		biBMP.bmiHeader.biHeight = -256;

		/* DIBSection�쐬 */
		hbmpBMP = CreateDIBSection(NULL, &biBMP, DIB_RGB_COLORS, (void **)(&lpdwPixel), NULL, 0);

		/* �E�C���h�E��HDC�擾 */
		hdc = GetDC(hwnd);

		/* DIBSection�p�������f�o�C�X�R���e�L�X�g�쐬 */
		hdcBMP = CreateCompatibleDC(hdc);

		/* �E�C���h�E��HDC��� */
		ReleaseDC(hwnd, hdc);

		/* DIBSection��HBITMAP���������f�o�C�X�R���e�L�X�g�ɑI�� */
		hbmpOld = (HBITMAP)SelectObject(hdcBMP, hbmpBMP);

		/* DIBSection�ɃO���f�[�V�����`�� */
		for (i = 0;i < 256;i++) {
			for (j = 0;j < 32;j++) {

				/* DIB�s�N�Z����ɒ��ڃA�N�Z�X */
				lpdwPixel[i + j * 256] = (i << 16);
				lpdwPixel[i + (j + 32) * 256] = (i << 8);
				lpdwPixel[i + (j + 64) * 256] = i;
				lpdwPixel[i + (j + 96) * 256] = (i << 16) | (i << 8) | i;


			}
		}

		return 0;

	case WM_MOUSEMOVE:

		/* �}�E�X�J�[�\�����W�擾 */
		iX = LOWORD(lParam);
		iY = HIWORD(lParam);

		if (iX > 255 || iY > 255) {
			return 0;
		}

		/* �}�E�X�J�[�\���ʒu�̃s�N�Z��RGB���s�N�Z����&GDI����擾���A������ */
		_stprintf(aszTmp, _T("(%d, %d) - Buf:%08x GDI:%08x"), iX, iY, lpdwPixel[iX + iY * 256], GetPixel(hdcBMP, iX, iY));

		/* �s�N�Z����RGB���^�C�g���o�[�ɕ\�� */
		SetWindowText(hwnd, aszTmp);

		return 0;

	case WM_PAINT:

		hdc = BeginPaint(hwnd,&ps);

		/* DIBSection��\�� */
		BitBlt(hdc, 0, 0, 256, 256, hdcBMP, 0, 0, SRCCOPY);

		EndPaint(hwnd, &ps);

		return 0;

	case WM_DESTROY:

		PostQuitMessage(0);

		/* DIBSection���������f�o�C�X�R���e�L�X�g�̑I������O�� */
		SelectObject(hdcBMP, hbmpOld);

		/* DIBSection���폜 */
		DeleteObject(hbmpBMP);

		/* �������f�o�C�X�R���e�L�X�g���폜 */
		DeleteDC(hdcBMP);

		return 0;

	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

