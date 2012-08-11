//x - a = (y - b)/c = (z - d)/e

#pragma once

#include "ILVector.h"
#include "ILSegment.h"

class ILLINE
{
public:
	double a, b, c, d, e;
	ILLINE()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		e = 0;
	}
	ILLINE(double A, double B, double C, double D, double E)
	{
		a = A;
		b = B;
		c = C;
		d = D;
		e = E;
	}
	ILLINE(ILVECTOR Pass,ILVECTOR Dirc)
	{
		a = Pass.x;
		b = Pass.y;
		c = Pass.z;
		d = Dirc.y / Dirc.x;
		e = Dirc.z / Dirc.x;
	}
	ILLINE(ILSEGMENT Segment)
	{
		a = Segment.origin.x;
		b = Segment.origin.y;
		c = Segment.origin.z;
		d = Segment.vector.y/Segment.vector.x;
		e = Segment.vector.z/Segment.vector.x;
	}
};