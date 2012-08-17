#include "ILFlat.h"

class ILSURFACE;

ILFLAT::ILFLAT()
{
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}
ILFLAT::ILFLAT(const double &A,const double &B,const double &C,const double &D)
{
	a = A;
	b = B;
	c = C;
	d = D;
}
ILFLAT::ILFLAT(const ILSURFACE &Surface)
{
	ILVECTOR cross = (Surface.b-Surface.a).Cross(Surface.c-Surface.a);
	a = cross.x;
	b = cross.y;
	c = cross.z;
	d = -(cross.x * Surface.a.x + cross.y * Surface.a.y + cross.z * Surface.a.z);
}