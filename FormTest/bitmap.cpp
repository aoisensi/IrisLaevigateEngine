
#include "bitmap.h"

//http://www.purika.sakura.ne.jp/program/pro_004bitmap.shtml

// �r�b�g�}�b�v�L���Ȃ�^

BOOL IsBitmapValid(const Bitmap* lpBitmap)
{
	return (lpBitmap->hbitmap != NULL);
}

// �r�b�g�}�b�v����

BOOL BitmapCreate(Bitmap* lpBitmap, int cx, int cy)
{
	BYTE* ptr;
	HBITMAP hbm;
	BITMAPINFO bmi;                 // �r�b�g�}�b�v�̏����ݒ�����̍\���̂ɓo�^����

	if (IsBitmapValid(lpBitmap))    // �����I�ɔj������ĂȂ���ΐ������Ȃ�
		return (FALSE);

	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biBitCount = 24;  // 1pixel������̃o�C�g��(0,1,4,8,16,24,32)
	bmi.bmiHeader.biPlanes = 1;     // ���܂̂Ƃ����1�����w��ł��Ȃ�
	bmi.bmiHeader.biWidth = cx;     // �r�b�g�}�b�v�̉���
	bmi.bmiHeader.biHeight = cy;    // �r�b�g�}�b�v�̏c��(�g�b�v�_�E���^��cy�𕉒l�ɂ���)

	if ((hbm = CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, (void**)&ptr, NULL, 0)) == NULL)
		return (FALSE);

	lpBitmap->addr = ptr;           // �A�h���X�擾
	lpBitmap->hbitmap = hbm;        // �n���h���擾
	lpBitmap->width = cx;
	lpBitmap->height = cy;
	lpBitmap->linesize = (cx * 3 + 3) & ~3L;
	return (TRUE);                  // linesize=�r�b�g�}�b�v������1�{�̃o�C�g��
}

// �r�b�g�}�b�v�j��

void BitmapDestroy(Bitmap* lpBitmap)
{
	DeleteObject(lpBitmap->hbitmap);
	lpBitmap->hbitmap = NULL;
}