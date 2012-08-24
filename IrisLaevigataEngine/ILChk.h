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
		ILVECTOR result;
		bool SurByVecB(const ILSURFACE &Surface, const ILVECTOR &Vector);
		bool SegByFlat(const ILSEGMENT &Segment, const ILFLAT &Flat);
		bool SegByFlatB(const ILSEGMENT &Segment, const ILFLAT &Flat);
		bool SegBySur(const ILSEGMENT &Segment, const ILSURFACE &Surface);
	};
}

#endif