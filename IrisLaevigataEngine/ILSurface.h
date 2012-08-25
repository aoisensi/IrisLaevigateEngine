#ifndef H_ILSURFACE
#define H_ILSURFACE

#include "ILVector.h"
#include "ILFlat.h"
#include "ILColor.h"

class ILFLAT;

class ILSURFACE
{
public:
	ILVECTOR a, b, c;
	ILCOLOR color;
	ILSURFACE(void);
	ILSURFACE(const ILVECTOR &A, const ILVECTOR &B, const ILVECTOR &C, const ILCOLOR &Color);
	ILSURFACE(const double &ax, const double &ay, const double &az, const double &bx, const double &by, const double &bz, const double &cx, const double &cy, const double &cz, const ILCOLOR &Color);
	ILFLAT Flat(void)const;
};

#endif