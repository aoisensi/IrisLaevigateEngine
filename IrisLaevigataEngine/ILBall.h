#ifndef H_ILBALL
#define H_ILBALL

#include "ILVector.h"

class ILBALL
{
public:
	ILVECTOR vector;
	double radius;
	ILBALL(void);
	ILBALL(const ILVECTOR &Vector, const double &Radius);
};

#endif