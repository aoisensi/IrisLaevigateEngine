#ifndef H_ILLINE
#define H_ILLINE

#include "ILVector.h"
#include "ILSegment.h"
#include "ILDirection.h"

class ILSEGMENT;

class ILLINE
{
public:
	ILVECTOR pass;
	ILDIRECTION dir;
	ILLINE(void);
	ILLINE(const double &X, const double &Y, const double &Z, const double &DXZ, const double &DY);
	ILLINE(const ILVECTOR &Pass, const ILDIRECTION &Dir);
	ILLINE(const ILSEGMENT &Segment);
};

#endif