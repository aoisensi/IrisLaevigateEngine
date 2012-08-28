#include <Windows.h>

typedef struct
{
	BYTE*   addr;       // ビットマップ色情報の先頭アドレス
	HBITMAP hbitmap;    // ビットマップハンドル
	int     width;      // ビットマップの横幅
	int     height;     // ビットマップの縦幅
	LONG    linesize;   // ビットマップ横一行のバイト数

} Bitmap;

BOOL IsBitmapValid(const Bitmap* lpBitmap);
BOOL BitmapCreate(Bitmap* lpBitmap, int cx, int cy);
void BitmapDestroy(Bitmap* lpBitmap);