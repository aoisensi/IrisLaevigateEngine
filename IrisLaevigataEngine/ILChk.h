#ifndef H_ILCHK
#define H_ILCHK

#include "ILSurface.h"
#include "ILSegment.h"
#include "ILFlat.h"
#include "ILVector.h"
#include "ILDist.h"

namespace IL
{
	class ILChk
	{
	public:
		static ILVECTOR result;
		static bool SurByVecB(const ILSURFACE &Surface, const ILVECTOR &Vector);
		static bool SegByFlat(const ILSEGMENT &Segment, const ILFLAT &Flat);
		static bool SegByFlatB(const ILSEGMENT &Segment, const ILFLAT &Flat);
		static bool SegBySur(const ILSEGMENT &Segment, const ILSURFACE &Surface);
	};
}

#endif