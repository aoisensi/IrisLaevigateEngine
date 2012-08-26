#ifndef H_ILELLIPSOID
#define H_ILELLIPSOID

#include "ILVector.h"
#include "ILDirection.h"

class ILELLIPSOID
{
public:
	double a,b,c;
	ILVECTOR vec;
	ILDIRECTION dir;
	ILELLIPSOID(void);
	ILELLIPSOID(const double &a,const double &b,const double &c,const ILVECTOR &Vector,const ILDIRECTION &Direction);
};

#endif