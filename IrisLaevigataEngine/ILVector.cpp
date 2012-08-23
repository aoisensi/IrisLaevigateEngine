#include "ILVector.h"

ILVECTOR::ILVECTOR()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

ILVECTOR::ILVECTOR(const double &X,const double &Y,const double &Z)
{
	x = X;
	y = Y;
	z = Z;
}

ILVECTOR::ILVECTOR(const ILDIRECTION &Direction, const double &Norm)
{
	this->x = Norm * IL::ILMath::Cos(Direction.xz) * IL::ILMath::Cos(Direction.y);
}

ILVECTOR ILVECTOR::Add(const ILVECTOR &obj)const
{
	return ILVECTOR(x+obj.x, y+obj.y, z+obj.z);
}

ILVECTOR ILVECTOR::Sub(const ILVECTOR &obj)const
{
	return ILVECTOR(x-obj.x, y-obj.y, z-obj.z);
}

ILVECTOR ILVECTOR::Mul(const double &obj)const
{
	return ILVECTOR(x*obj, y*obj, z*obj);
}

ILVECTOR ILVECTOR::operator+(const ILVECTOR& right)const
{
	return ILVECTOR(x+right.x, y+right.y, z+right.z);
}

ILVECTOR ILVECTOR::operator-(const ILVECTOR& right)const
{
	return ILVECTOR(x-right.x, y-right.y, z-right.z);
}

ILVECTOR ILVECTOR::operator*(const double& right)const
{
	return ILVECTOR(x*right, y*right, z*right);
}

ILVECTOR ILVECTOR::operator/(const double& right)const
{
	double value = 1 / right;
	return ILVECTOR(x*value, y*value, z*value);
}

double ILVECTOR::Inner(const ILVECTOR &value)
{
	return ( x * value.x + y * value.y + z * value.z );
}

ILVECTOR ILVECTOR::Cross(const ILVECTOR &value)
{
	return ILVECTOR(this->y * value.z - value.y * this->z,
		this->z * value.x - value.z * this->x,
		this->x * value.y - value.x * this->y);
}

ILVECTOR ILVECTOR::Center(const ILVECTOR &value)
{
	ILVECTOR tmp;
	tmp.x = ( x + value.x ) * 0.5f;
	tmp.y = ( y + value.y ) * 0.5f;
	tmp.z = ( z + value.z ) * 0.5f;
	return tmp;
}

double ILVECTOR::Norm()
{
	return ( IL::ILMath::Sqrt( x * x + y * y + z * z ) );
}

ILDIRECTION ILVECTOR::Direction()
{
	ILDIRECTION result;
	result.xz = IL::ILMath::Atan2(z,x);
	result.y = IL::ILMath::Atan2(y,IL::ILMath::Sqrt(x*x + z*z));
	return result;
}
