//a x + b y + c z + d = 0

#ifndef H_ILFLAT
#define H_ILFLAT

#include "ILSurface.h"
#include "ILVector.h"

class ILSURFACE;

class ILFLAT
{
public:
	double a;
	double b;
	double c;
	double d;
	ILFLAT(void);
	ILFLAT(const double &A,const double &B,const double &C,const double &D);
	ILFLAT(const ILSURFACE &Surface);
	ILVECTOR Normal(void)const;
	ILVECTOR Pass(void)const;
};

#endif