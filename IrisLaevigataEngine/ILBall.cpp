#include "ILBall.h"

ILBALL::ILBALL()
{
	vector = ILVECTOR();
	radius = 0.0F;
}

ILBALL::ILBALL(const ILVECTOR &Vector, const double &Radius)
{
	vector = Vector;
	radius = Radius;
}