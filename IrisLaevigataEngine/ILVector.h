#pragma once

#include "ILMath.h"
#include "ILDirection.h"

class ILVECTOR
{
public:
	double x;
	double y;
	double z;

	ILVECTOR()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	ILVECTOR(double X, double Y, double Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	ILVECTOR operator-()
	{
		ILVECTOR tmp;
		tmp.x = -x;
		tmp.y = -y;
		tmp.z = -z;
		return tmp;
	}

	ILVECTOR operator+(ILVECTOR right)
	{
		ILVECTOR tmp;
		tmp.x = x+right.x;
		tmp.y = y+right.y;
		tmp.z = z+right.z;
		return tmp;
	}

	ILVECTOR operator-(ILVECTOR value)
	{
		ILVECTOR tmp;
		tmp.x = x - value.x;
		tmp.y = y - value.y;
		tmp.z = z - value.z;
		return tmp;
	}

	double Inner(ILVECTOR value)
	{
		return ( x * value.x + y * value.y + z * value.z );
	}

	ILVECTOR Cross(ILVECTOR value)
	{
		return ILVECTOR(this->y * value.z - value.y * this->z,
						this->z * value.x - value.z * this->x,
						this->x * value.y - value.x * this->y);
	}

	ILVECTOR Center(ILVECTOR value)
	{
		ILVECTOR tmp;
		tmp.x = ( x + value.x ) * 0.5f;
		tmp.y = ( y + value.y ) * 0.5f;
		tmp.z = ( z + value.z ) * 0.5f;
		return tmp;
	}

	double Norm()
	{
		return ( IL::ILMath::Sqrt( x * x + y * y + z * z ) );
	}
	
	ILDIRECTION Direction()
	{
		ILDIRECTION result;
		result.xz = IL::ILMath::Atan2(z,x);
		result.y = IL::ILMath::Atan2(y,IL::ILMath::Sqrt(x*x + z*z));
		return result;
	}
};