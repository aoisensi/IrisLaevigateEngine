#ifndef H_ILROTATION
#define H_ILROTATION

#include "ILAngle.h"
#include "ILDirection.h"

class ILROTATION
{
public:
	ILANGLE x,y,z;
	ILROTATION();
	ILROTATION(const ILANGLE &X, const ILANGLE &Y, const ILANGLE &Z);
	ILROTATION(const double &X, const double &Y, const double &Z);
	ILDIRECTION Direction(void)const;
};

#endif