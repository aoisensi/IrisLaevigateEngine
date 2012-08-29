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
		static double Sin(const ILANGLE &o);

		static double Cos(const ILANGLE &o);

		static double Tan(const ILANGLE &o);

		static ILANGLE Atan(const double &o);

		static ILANGLE Atan2(const double &y,const double &x);

		static double Sqrt(const double &o);

		static double Abs(const double &o);

		static double RBIZTZ(const double &o);
	};
}

#endif