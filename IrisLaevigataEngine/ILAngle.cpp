#include "ILAngle.h"


ILANGLE::ILANGLE()
{
	angle = 0;
}
ILANGLE::ILANGLE(const double &Angle)
{
	angle = Angle;
}
ILANGLE ILANGLE::operator+()
{
	return ILANGLE(angle);
}
ILANGLE ILANGLE::operator-()
{
	return ILANGLE(-angle);
}
ILANGLE ILANGLE::operator+(const ILANGLE &value)
{
	return ILANGLE(angle + value.angle);
}
ILANGLE ILANGLE::operator-(const ILANGLE &value)
{
	return ILANGLE(angle - value.angle);
}
ILANGLE ILANGLE::operator*(const double &value)
{
	return ILANGLE(angle * value);
}
ILANGLE ILANGLE::operator/(const double &value)
{
	return ILANGLE(angle / value);
}
