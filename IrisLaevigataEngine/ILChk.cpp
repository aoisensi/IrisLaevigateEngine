#include "ILChk.h"

namespace IL
{
	const double error = 0.1F;
	bool ILChk::SurByVecB(const ILSURFACE &Surface, const ILVECTOR &Vector)
	{
		ILVECTOR v1 = ((Surface.b - Surface.a).Cross(Vector)).Normal();
		ILVECTOR v2 = ((Surface.b - Surface.a).Cross(Vector)).Normal();
		ILVECTOR v3 = ((Surface.b - Surface.a).Cross(Vector)).Normal();
		ILVECTOR n = Surface.Flat().Pass();
		if(n.Equal(v1,error))
		{
			if (n.Equal(v2,error))
			{
				if (n.Equal(v3,error))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool ILChk::SegByFlatB(const ILSEGMENT &Segment, const ILFLAT &Flat)
	{
		ILVECTOR FlatPass = Flat.Pass();
		ILVECTOR v1 = Segment.origin - FlatPass;
		ILVECTOR v2 = Segment.Unorigin() - FlatPass;
		ILVECTOR n = Flat.Pass();
		return ( v1.Inner(n) * v2.Inner(n) <= 0 );
	}
}