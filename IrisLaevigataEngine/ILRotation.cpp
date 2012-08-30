#include "ILRotation.h"

ILROTATION::ILROTATION()
{
	x = ILANGLE();
	y = ILANGLE();
	z = ILANGLE();
}
ILROTATION::ILROTATION(const ILANGLE &X, const ILANGLE &Y, const ILANGLE &Z)
{
	x = X;
	y = Y;
	z = Z;
}
ILROTATION::ILROTATION(const double &X, const double &Y, const double &Z)
{
	x = ILANGLE(X);
	y = ILANGLE(Y);
	z = ILANGLE(Z);
}
ILDIRECTION ILROTATION::Direction()const
{
	return ILDIRECTION(this->y,this->x);
}