#ifndef H_ILMATH
#define H_ILMATH

#include <cmath>
#include "ILAngle.h"

#define M_PI 3.14159265358979323846
#define M_DEGREE 0.017453292519943295769
#define M_1_DEGREE 57.295779513082320876798

namespace IL
{
	class ILMath
	{
	public:
		static double Sin(ILANGLE o)
		{
			return sin(M_DEGREE * o.angle);
		}

		static double Cos(ILANGLE o)
		{
			return cos(M_DEGREE * o.angle);
		}

		static ILANGLE Atan(double o)
		{
			return ILANGLE(atan(o) * M_1_DEGREE);
		}
		static ILANGLE Atan2(double y,double x)
		{
			return ILANGLE(atan2(y,x) * M_1_DEGREE);
		}

		static double Sqrt(double o)
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
	};
}

#endif