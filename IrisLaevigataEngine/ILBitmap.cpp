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
			dot[i] = 0;
		}
		delete[] dot;
		dot = 0;
	}
	return;
}

void ILBITMAP::Reduction(const int &n, ILBITMAP &output)
{
	for(int i=0 ; i<output.x ; ++i)
	{
		for(int j=0 ; j<output.y ; ++j)
		{
			int ar = 0;
			int ag = 0;
			int ab = 0;
			for(int k=0 ; k<n ; ++k)
			{
				for(int l=0 ; l<n ; ++l)
				{
					ILCOLOR bit = this->PGet(i*n+k, j*n+l);
					ar += bit.r;
					ag += bit.g;
					ab += bit.b;
				}
			}
			ILCOLOR dot = ILCOLOR(ar/n/n, ag/n/n, ab/n/n);
			output.PSet(i,j,dot);
		}
	}
}