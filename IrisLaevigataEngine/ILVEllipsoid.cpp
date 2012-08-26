#include "ILVEllipsoid.h"

ILVELLIPSOID::ILVELLIPSOID()
{
	ellipsoid = ILELLIPSOID();
	color = ILCOLOR();
}

ILVELLIPSOID::ILVELLIPSOID(const ILELLIPSOID &Ellipsoid, const ILCOLOR &Color)
{
	ellipsoid = Ellipsoid;
	color = Color;
}