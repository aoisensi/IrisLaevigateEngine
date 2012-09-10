#include "ILTSpace.h"

ILTSPACE::ILTSPACE(const int &SurfaceC)
{
	surface = new ILTSURFACE[SurfaceC];
	numberofsurface = 0;
}

void ILTSPACE::dispose()
{
	if(surface != 0)
	{
		delete[] surface;
		surface = 0;
	}
	return;
}

void ILTSPACE::AddSurface(const ILTSURFACE &Surface)
{
	surface[numberofsurface] = Surface;
	++numberofsurface;
	return;
}

ILTSURFACE ILTSPACE::Surface(const int &n)const
{
	return surface[n];
}