#ifndef H_ILTSPACE
#define H_ILTSPACE

#include "ILTSurface.h"

class ILTSPACE
{
public:
	ILTSURFACE *surface;
	int numberofsurface;
	ILTSPACE::ILTSPACE(const int &SurfaceC);
	void dispose();
	void AddSurface(const ILTSURFACE &Surface);
	ILTSURFACE Surface(const int &n)const;
};

#endif