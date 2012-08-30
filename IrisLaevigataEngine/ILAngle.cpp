#include "ILAngle.h"


ILANGLE::ILANGLE()
{
	angle = 0;
}
ILANGLE::ILANGLE(const double &Angle)
{
	angle = fmod(Angle, 180);
}
ILANGLE ILANGLE::operator+()
{
	return ILANGLE(angle);
}
ILANGLE ILANGLE::operator-()
{
	return ILANGLE(-angle);
}
void ILANGLE::operator+=(const ILANGLE &value)
{
	this->angle = fmod(this->angle + value.angle ,180);
}
void ILANGLE::operator-=(const ILANGLE &value)
{
	this->angle = fmod(this->angle - value.angle ,180);
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
