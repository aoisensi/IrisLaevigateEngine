
#include "bitmap.h"

//http://www.purika.sakura.ne.jp/program/pro_004bitmap.shtml

// ビットマップ有効なら真

BOOL IsBitmapValid(const Bitmap* lpBitmap)
{
	return (lpBitmap->hbitmap != NULL);
}

// ビットマップ生成

BOOL BitmapCreate(Bitmap* lpBitmap, int cx, int cy)
{
	BYTE* ptr;
	HBITMAP hbm;
	BITMAPINFO bmi;                 // ビットマップの初期設定をこの構造体に登録する

	if (IsBitmapValid(lpBitmap))    // 明示的に破棄されてなければ生成しない
		return (FALSE);

	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biBitCount = 24;  // 1pixel当たりのバイト数(0,1,4,8,16,24,32)
	bmi.bmiHeader.biPlanes = 1;     // いまのところは1しか指定できない
	bmi.bmiHeader.biWidth = cx;     // ビットマップの横幅
	bmi.bmiHeader.biHeight = cy;    // ビットマップの縦幅(トップダウン型はcyを負値にする)

	if ((hbm = CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, (void**)&ptr, NULL, 0)) == NULL)
		return (FALSE);

	lpBitmap->addr = ptr;           // アドレス取得
	lpBitmap->hbitmap = hbm;        // ハンドル取得
	lpBitmap->width = cx;
	lpBitmap->height = cy;
	lpBitmap->linesize = (cx * 3 + 3) & ~3L;
	return (TRUE);                  // linesize=ビットマップ走査線1本のバイト数
}

// ビットマップ破棄

void BitmapDestroy(Bitmap* lpBitmap)
{
	DeleteObject(lpBitmap->hbitmap);
	lpBitmap->hbitmap = NULL;
}