#ifndef H_ILSPACE
#define H_ILSPACE

#include "ILSurface.h"
#include "ILEllipsoid.h"

class ILSPACE
{
public:
	ILSURFACE *surface;
	
	int surfacen;
	
	ILSPACE(const int &SurfaceC);
	
	void dispose(void);
	void AddSurface(ILSURFACE &Surface);
	ILSURFACE Surface(int n);
};

#endif 