#include "ILBitmap.h"

ILBITMAP::ILBITMAP(const int &X, const int &Y)
{
	x = X;
	y = Y;
	dot = new ILCOLOR*[x];
	for (int i=0;i<x;++i)
	{
		dot[i] = new ILCOLOR[y];
	}
}

ILCOLOR ILBITMAP::PGet(const int &X, const int &Y)
{
	return dot[X][Y];
}

void ILBITMAP::PSet(const int &X, const int &Y, const ILCOLOR Color)
{
	dot[X][Y] = Color;
	return;
}

void ILBITMAP::dispose()
{
	if(dot != 0)
	{
		for (int i = 0;i<x;++i)
		{
			delete[] dot[i];
		}
		delete[] dot;
		dot = 0;
	}
	return;
}