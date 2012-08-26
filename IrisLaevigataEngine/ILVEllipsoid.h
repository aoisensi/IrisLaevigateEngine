#ifndef H_ILVELLIPSOID
#define H_ILVELLIPSOID

#include "ILEllipsoid.h"
#include "ILColor.h"

class ILVELLIPSOID
{
public:
	ILELLIPSOID ellipsoid;
	ILCOLOR color;
	ILVELLIPSOID(void);
	ILVELLIPSOID(const ILELLIPSOID &Ellipsoid, const ILCOLOR &Color);
};

#endif