#ifndef H_ILTSURFACE
#define H_ILTSURFACE

#include "ILSurface.h"

class ILTSURFACE
{
public:
	ILSURFACE surface;
	double light;
	ILCOLOR color;
	int contour; //0�͓���Ȃ�
	ILTSURFACE(ILSURFACE Surface, double Light, ILCOLOR Color, int Countour);
	ILTSURFACE(void);
};

#endif