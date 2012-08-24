#include "ILMath.h"

namespace IL
{
	double ILMath::Sin(const ILANGLE &o)
	{
		return sin(M_DEGREE * o.angle);
	}

	double ILMath::Cos(const ILANGLE &o)
	{
		return cos(M_DEGREE * o.angle);
	}

	ILANGLE ILMath::Atan(const double &o)
	{
		return ILANGLE(atan(o) * M_1_DEGREE);
	}
	ILANGLE ILMath::Atan2(const double &y,const double &x)
	{
		return ILANGLE(atan2(y,x) * M_1_DEGREE);
	}

	double ILMath::Sqrt(const double &o)
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

	long double ILMath::Abs(const long double &o)
	{
		return abs(o);
	}
}