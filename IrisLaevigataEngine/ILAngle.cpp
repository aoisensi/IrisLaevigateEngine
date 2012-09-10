#include "ILAngle.h"


ILANGLE::ILANGLE()
{
	angle = 0;
}
ILANGLE::ILANGLE(const double &Angle)
{
	this->angle = Exceeds(Angle);
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
double ILANGLE::Exceeds(const double &value)
{
	return value - (((int)(value * M_1_PI))*M_PI*2);
}
double ILANGLE::Frequency()
{
	return this->angle * M_1_DEGREE;
}

