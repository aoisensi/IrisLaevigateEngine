#ifndef H_ILVSURFACE
#define H_ILVSURFACE

#include "ILSurface.h"
#include "ILColor.h"

class ILVSURFACE
{
public:
	ILSURFACE surface;
	ILCOLOR color;
	ILVSURFACE(void);
	ILVSURFACE(const ILSURFACE &Surface, const ILCOLOR &Color);
};

#endif