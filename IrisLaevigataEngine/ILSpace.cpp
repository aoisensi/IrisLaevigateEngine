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