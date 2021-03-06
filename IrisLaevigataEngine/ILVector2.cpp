#include "ILVector2.h"

ILVECTOR2::ILVECTOR2(void)
{
	this->x = 0.0F;
	this->y = 0.0F;
}
ILVECTOR2::ILVECTOR2(const double &X, const double &Y)
{
	this->x = X;
	this->y = Y;
}
ILVECTOR2 ILVECTOR2::operator+(const ILVECTOR2 &right)const
{
	return ILVECTOR2(this->x + right.x, this->y + right.y);
}
ILVECTOR2 ILVECTOR2::operator-(const ILVECTOR2 &right)const
{
	return ILVECTOR2(this->x - right.x, this->y - right.y);
}
ILVECTOR2 ILVECTOR2::operator-()
{
	return ILVECTOR2(-this->x, -this->y);
}
double ILVECTOR2::Dot(const ILVECTOR2 &value)const
{
	return this->x * value.x + this->y * this->y;
}
ILVECTOR ILVECTOR2::Cross(const ILVECTOR2 &value)const
{
	return ILVECTOR(0, 0, this->x * value.y - this->y * value.x);
}
double ILVECTOR2::CrossDouble(const ILVECTOR2 &value)const
{
	return this->x * value.y - this->y * value.x;
}
double ILVECTOR2::Norm()const
{
	return IL::ILMath::Sqrt(this->x * this->x + this->y * this->y);
}
