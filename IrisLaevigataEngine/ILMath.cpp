#include "ILMath.h"

double IL::ILMath::Sin(const ILANGLE &o)
{
	return sin(o.angle);
}

double IL::ILMath::Cos(const ILANGLE &o)
{
	return cos(o.angle);
}

double IL::ILMath::Tan(const ILANGLE &o)
{
	return tan(o.angle);
}

ILANGLE IL::ILMath::Atan(const double &o)
{
	return ILANGLE(atan(o));
}
ILANGLE IL::ILMath::Atan2(const double &y,const double &x)
{
	return ILANGLE(atan2(y,x));
}

double IL::ILMath::Sqrt(const double &o)
{
	double s = o;
	double t;
	if(o == 0)
	{
		return 0;
	}
	do
	{
		t = s;
		s = (t + o / t) / 2;
	}
	while(s < t);
	return t;
}

double IL::ILMath::Abs(const double &o)
{
	return o < 0 ? -o : o;
}

double IL::ILMath::RBIZTZ(const double &o)//ReciprocalButIfZeroThenZero
{
	return (o == 0.0F)?0.0F:1/o;
}
