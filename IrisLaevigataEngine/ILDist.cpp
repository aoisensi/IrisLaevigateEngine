#include "ILDist.h"

namespace IL
{
	double ILDist::FlatByVector(const ILFLAT &Flat, const ILVECTOR &Vector)
	{
		return IL::ILMath::Abs(Flat.a * Vector.x + Flat.b * Vector.y + Flat.c * Vector.z + Flat.d) / IL::ILMath::Sqrt(Flat.a * Flat.a + Flat.b * Flat.b + Flat.c * Flat.c);
	}
}