#include "ILTSurface.h"

ILTSURFACE::ILTSURFACE(ILSURFACE Surface, double Light, ILCOLOR Color, int Contour)
{
	surface = Surface;
	light = Light;
	color = Color;
	contour = Contour;
}

ILTSURFACE::ILTSURFACE()
{
	surface = ILSURFACE();
	light = M_PI;
	color = ILCOLOR();
	contour = 1;
}