#include "ILVSurface.h"

ILVSURFACE::ILVSURFACE()
{
	surface = ILSURFACE();
	color = ILCOLOR();
}

ILVSURFACE::ILVSURFACE(const ILSURFACE &Surface, const ILCOLOR &Color)
{
	surface = Surface;
	color = Color;
}