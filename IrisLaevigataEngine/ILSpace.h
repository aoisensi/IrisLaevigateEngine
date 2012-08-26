#ifndef H_ILSPACE
#define H_ILSPACE

#include "ILVSurface.h"
#include "ILVEllipsoid.h"
#include "ILVBall.h"

class ILSPACE
{
public:
	ILVSURFACE *surface;
	ILVELLIPSOID *ellipsoid;
	ILVBALL *ball;
	int numberofsurface;
	int numberofellipsoid;
	int numberofball;
	
	ILSPACE(const int &SurfaceC, const int &EllipsoidC, const int &BallC);

	void dispose(void);
	void AddSurface(const ILVSURFACE &Surface);
	void AddEllipsoid(const ILVELLIPSOID &Ellipsoid);
	void AddBall(const ILVBALL &Ball);

	ILVSURFACE Surface(const int &n)const;
	ILVELLIPSOID Ellipsoid(const int &n)const;
	ILVBALL Ball(const int &n)const;
};

#endif 