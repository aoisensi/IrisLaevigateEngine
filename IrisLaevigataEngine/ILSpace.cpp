#include "ILSpace.h"

ILSPACE::ILSPACE(const int &SurfaceC)
{
	surface = new ILSURFACE[SurfaceC];//èâä˙âªÇÃÇ¬Ç‡ÇË
	surfacen = 0;
}

void ILSPACE::dispose()
{
	if(surface != 0)
	{
		delete[] surface;
		surface = 0;
	}
	return;
}

void ILSPACE::AddSurface(ILSURFACE &Surface)
{
	surface[surfacen] = Surface;
	++surfacen;
	return;
}

ILSURFACE ILSPACE::Surface(int n)
{
	return surface[n];
}