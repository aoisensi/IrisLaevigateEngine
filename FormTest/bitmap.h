#include <Windows.h>

typedef struct
{
	BYTE*   addr;       // �r�b�g�}�b�v�F���̐擪�A�h���X
	HBITMAP hbitmap;    // �r�b�g�}�b�v�n���h��
	int     width;      // �r�b�g�}�b�v�̉���
	int     height;     // �r�b�g�}�b�v�̏c��
	LONG    linesize;   // �r�b�g�}�b�v����s�̃o�C�g��

} Bitmap;

BOOL IsBitmapValid(const Bitmap* lpBitmap);
BOOL BitmapCreate(Bitmap* lpBitmap, int cx, int cy);
void BitmapDestroy(Bitmap* lpBitmap);