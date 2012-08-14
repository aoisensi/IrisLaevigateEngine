//a x + b y + c z + d = 0

#ifndef H_ILFLAT
#define H_ILFLAT

#include "ILSurface.h"


class ILFLAT
{
public:
	double a, b, c, d;
	ILFLAT()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
	ILFLAT(double A,double B, double C,double D)
	{
		a = A;
		b = B;
		c = C;
		d = D;
	}
	ILFLAT(ILSURFACE Surface)
	{
		ILVECTOR cross = (Surface.b-Surface.a).Cross(Surface.c-Surface.a);
		a = cross.x;
		b = cross.y;
		c = cross.z;
		d = -(cross.x * Surface.a.x + cross.y * Surface.a.y + cross.z * Surface.a.z);
	}
};

#endif