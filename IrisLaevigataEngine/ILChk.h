#include "ILSurface.h"
#include "ILSegment.h"
#include "ILFlat.h"
#include "ILVector.h"

namespace IL
{
	class ILChk
	{
	public:
		ILVECTOR result;
		bool SurByVecB(const ILSURFACE &Surface, const ILVECTOR &Vector);
		bool SegByFlatB(const ILSEGMENT &Segment, const ILFLAT &Flat);
	};
}