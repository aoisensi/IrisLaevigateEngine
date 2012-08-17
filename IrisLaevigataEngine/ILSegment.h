#ifndef H_ILSEGMENT
#define H_ILSEGMENT

#include "ILVector.h"
#include "ILLine.h"

class ILLINE;

class ILSEGMENT
{
public:
	ILVECTOR origin;
	ILVECTOR vector;
	ILSEGMENT(void);
	ILSEGMENT(const ILVECTOR &Origin, const ILVECTOR &Vector);
	ILSEGMENT(const double & OriginX, const double &OriginY,const double &OriginZ,const double &VectorX, const double &VectorY, const double &VectorZ);
	ILLINE Line(void);
};

#endif