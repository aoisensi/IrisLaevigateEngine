#ifndef H_ILDIRECTION
#define H_ILDIRECTION

#include "ILVector.h"
#include "ILAngle.h"
#include "ILMath.h"

class ILVECTOR;

class ILDIRECTION
{
public:
	ILANGLE xz;
	ILANGLE y;
	ILDIRECTION(void);
	ILDIRECTION(const double &XZ,const double &Y);
	ILDIRECTION(const ILANGLE &XZ,const ILANGLE &Y);
	ILVECTOR Vector(void);
	ILVECTOR Vector(const double &Norm);
};

#endif
