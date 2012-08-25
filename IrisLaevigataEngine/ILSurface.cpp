#include "ILSurface.h"

ILSURFACE::ILSURFACE()
{
	a = ILVECTOR();
	b = ILVECTOR();
	c = ILVECTOR();
	color = ILCOLOR();
}
ILSURFACE::ILSURFACE(const ILVECTOR &A, const ILVECTOR &B, const ILVECTOR &C, const ILCOLOR &Color)
{
	a = A;
	b = B;
	c = C;
	color = Color;
}
ILSURFACE::ILSURFACE(const double &ax, const double &ay, const double &az, const double &bx, const double &by, const double &bz, const double &cx, const double &cy, const double &cz, const ILCOLOR &Color)
{
	a = ILVECTOR(ax,ay,az);
	b = ILVECTOR(bx,by,bz);
	c = ILVECTOR(cx,cy,cz);
	color = Color;
}

ILFLAT ILSURFACE::Flat()const
{
	ILFLAT result;
	ILVECTOR cross = (b.Sub(a)).Cross(c.Sub(a));
	result.a = cross.x;
	result.b = cross.y;
	result.c = cross.z;
	result.d = -(cross.x * this->a.x + cross.y * this->a.y + cross.z * this->a.z);
	return result;
}
