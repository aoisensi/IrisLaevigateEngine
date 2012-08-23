#include "ILColor.h"

ILCOLOR::ILCOLOR(const unsigned __int8 &R,const unsigned __int8 &G, const unsigned __int8 &B)
{
	r = R;
	g = G;
	b = B;
}

ILCOLOR::ILCOLOR()
{
	r = 0;
	g = 0;
	b = 0;
}