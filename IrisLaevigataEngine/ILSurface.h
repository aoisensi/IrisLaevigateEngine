#ifndef H_ILSURFACE
#define H_ILSURFACE

#include "ILVector.h"
#include "ILFlat.h"

class ILFLAT;

class ILSURFACE
{
public:
	ILVECTOR a, b, c;
	ILSURFACE(void);
	ILSURFACE(const ILVECTOR &A, const ILVECTOR &B, const ILVECTOR &C);
	ILSURFACE(const double &ax, const double &ay, const double &az, const double &bx, const double &by, const double &bz, const double &cx, const double &cy, const double &cz);
	ILFLAT Flat(void);
};

#endif