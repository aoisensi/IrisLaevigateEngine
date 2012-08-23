#include "ILCamera.h"

ILCAMERA::ILCAMERA(const double &Min, const double &Max, const ILFLAT Flat, const ILVECTOR Vector, const ILANGLE FovX, const ILANGLE FovY)
{
	min = Min;
	max = Max;
	flat = Flat;
	vector = Vector;
	fovx = FovX;
	fovy = FovY;
}