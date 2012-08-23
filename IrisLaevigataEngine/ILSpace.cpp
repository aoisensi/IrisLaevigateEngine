#include "ILSpace.h"

ILSPACE::ILSPACE(const int &SurfaceC)
{
	surface = new ILSURFACE[SurfaceC];
}

void ILSPACE::dispose()
{
	delete[] surface;
	surface = 0;
}

void ILSPACE::AddSurface(ILSURFACE &Surface)
{
	surface[surfacen] = Surface;
	++surfacen;
}

ILSURFACE ILSPACE::Surface(int n)
{
	return surface[n];
}