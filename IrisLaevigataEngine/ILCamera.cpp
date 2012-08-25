#include "ILCamera.h"

ILCAMERA::ILCAMERA(const double &Min, const double &Max, const ILROTATION &Rotation, const ILVECTOR &Vector, const ILANGLE &FovX, const ILANGLE &FovY, const ILCOLOR &Color)
{
	min = Min;
	max = Max;
	rotation = Rotation;
	vector = Vector;
	fovx = FovX;
	fovy = FovY;
	backgroundcolor = Color;
}