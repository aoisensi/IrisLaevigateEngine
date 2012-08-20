#include "ILEllipsoid.h"

ILELLIPSOID::ILELLIPSOID(const double &A,const double &B,const double &C,const ILVECTOR &Vector,const ILDIRECTION &Direction)
{
	a = A;
	b = B;
	c = C;
	vec = Vector;
	dir = Direction;
}