#ifndef H_ILDIST
#define H_ILDIST

#include "ILFlat.h"
#include "ILVector.h"

namespace IL
{
	class ILDist
	{
	public:
		//http://yosshy.sansu.org/distance1.htm
		static double FlatByVector(const ILFLAT &Flat, const ILVECTOR &Vector);
		
	};
}

#endif