
#ifndef H_ILANGLE
#define H_ILANGLE

#include "ILMath.h"

class ILMath;

class ILANGLE
{
public:
	double angle;
	ILANGLE(void);
	ILANGLE(const double &Angle);
	ILANGLE operator+(void);
	ILANGLE operator-(void);
	ILANGLE operator+(const ILANGLE &value);
	ILANGLE operator-(const ILANGLE &value);
	void operator+=(const ILANGLE &value);
	void operator-=(const ILANGLE &value);
	ILANGLE operator*(const double &value);
	ILANGLE operator/(const double &value);
	double Exceeds(const double &value);
};

#endif