#include "ILChk.h"
#include <iostream>
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

	bool ILChk::SegByFlat(const ILSEGMENT &Segment, const ILFLAT &Flat, ILVECTOR &Result)
	{
		if ( SegByFlatB(Segment, Flat) )
		{
			double d1 = IL::ILDist::FlatByVector(Flat, Segment.vector);
			double d2 = IL::ILDist::FlatByVector(Flat, Segment.Unorigin());
			Result = Segment.vector / (d1 + d2) * d1 + Segment.origin;
			return true;
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

	bool ILChk::SegBySur(const ILSEGMENT &Segment, const ILSURFACE &Surface, ILVECTOR &Result)
	{
		ILVECTOR v;
		if(SegByFlat(Segment,Surface.Flat(),v))
		{
			if ( SurByVecB(Surface, v) )
			{
				Result = v;
				return true;
			}
		}
		return false;
	}
}