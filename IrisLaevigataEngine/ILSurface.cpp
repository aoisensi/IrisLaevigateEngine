#include "ILSurface.h"

ILSURFACE::ILSURFACE()
{
	a = ILVECTOR();
	b = ILVECTOR();
	c = ILVECTOR();
}
ILSURFACE::ILSURFACE(const ILVECTOR &A, const ILVECTOR &B, const ILVECTOR &C)
{
	a = A;
	b = B;
	c = C;
}
ILSURFACE::ILSURFACE(const double &ax, const double &ay, const double &az, const double &bx, const double &by, const double &bz, const double &cx, const double &cy, const double &cz)
{
	a = ILVECTOR(ax,ay,az);
	b = ILVECTOR(bx,by,bz);
	c = ILVECTOR(cx,cy,cz);
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
