#ifndef H_ILCAMERA
#define H_ILCAMERA

#include "ILFlat.h"
#include "ILVector.h"
#include "ILAngle.h"

class ILCAMERA
{
public:
	double min;
	double max;
	ILFLAT flat;
	ILVECTOR vector;
	ILANGLE fovx;
	ILANGLE fovy;
	ILCAMERA(const double &Min, const double &Max, const ILFLAT Flat, const ILVECTOR Vector, const ILANGLE FovX, const ILANGLE FovY);
};

#endif