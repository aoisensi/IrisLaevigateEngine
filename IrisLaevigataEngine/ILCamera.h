#ifndef H_ILCAMERA
#define H_ILCAMERA

#include "ILRotation.h"
#include "ILVector.h"
#include "ILAngle.h"
#include "ILColor.h"

class ILCAMERA
{
public:
	double min;
	double max;
	ILROTATION rotation;
	ILVECTOR vector;
	ILANGLE fovx;
	ILANGLE fovy;
	ILCAMERA(const double &Min, const double &Max, const ILROTATION &Rotation, const ILVECTOR &Vector, const ILANGLE &FovX, const ILANGLE &FovY);
};

#endif