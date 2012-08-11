#pragma once

#include <cmath>

#define M_PI 3.14159265358979323846
#define M_DEGREE 0.017453292519943295769
#define M_1_DEGREE 57.295779513082320876798

namespace IL
{
	class ILMath
	{
	public:
		static double Sin(double o)
		{
			return sin(M_DEGREE * o);
		}

		static double Cos(double o)
		{
			return cos(M_DEGREE * o);
		}

		static double Atan(double o)
		{
			return atan(o) * M_1_DEGREE;
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