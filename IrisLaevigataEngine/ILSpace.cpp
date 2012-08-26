#include "ILSpace.h"

ILSPACE::ILSPACE(const int &SurfaceC, const int &EllipsoidC, const int &BallC)
{
	surface = new ILVSURFACE[SurfaceC];
	ellipsoid = new ILVELLIPSOID[EllipsoidC];
	ball = new ILVBALL[BallC];
	numberofsurface = 0;
	numberofellipsoid = 0;
	numberofball = 0;
}

void ILSPACE::dispose()
{
	if(surface != 0)
	{
		delete[] surface;
		surface = 0;
	}
	if(ellipsoid != 0)
	{
		delete[] ellipsoid;
		numberofellipsoid = 0;
	}
	if(ball != 0)
	{
		delete[] ball;
		numberofball = 0;
	}
	return;
}

void ILSPACE::AddSurface(const ILVSURFACE &Surface)
{
	surface[numberofsurface] = Surface;
	++numberofsurface;
	return;
}

void ILSPACE::AddEllipsoid(const ILVELLIPSOID &Ellipsoid)
{
	ellipsoid[numberofellipsoid] = Ellipsoid;
	++numberofellipsoid;
	return;
}

void ILSPACE::AddBall(const ILVBALL &Ball)
{
	ball[numberofball] = Ball;
	++numberofball;
}

ILVSURFACE ILSPACE::Surface(const int &n)const
{
	return surface[n];
}

ILVELLIPSOID ILSPACE::Ellipsoid(const int &n)const
{
	return ellipsoid[n];
}

ILVBALL ILSPACE::Ball(const int &n)const
{
	return ball[n];
}