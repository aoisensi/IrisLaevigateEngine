#ifndef H_ILTSURFACE
#define H_ILTSURFACE

#include "ILSurface.h"

class ILTSURFACE
{
public:
	ILSURFACE surface;
	double light;
	ILCOLOR color;
	int contour; //0は入れない
	ILTSURFACE(ILSURFACE Surface, double Light, ILCOLOR Color, int Countour);
	ILTSURFACE(void);
};

#endif