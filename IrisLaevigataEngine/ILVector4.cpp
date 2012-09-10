#include "ILVector4.h"

ILVECTOR4::ILVECTOR4(void)
{
	this->x = 0.0F;
	this->y = 0.0F;
	this->z = 0.0F;
	this->w = 0.0F;
}
ILVECTOR4::ILVECTOR4(double X,double Y, double Z, double W)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
	this->w = W;
}