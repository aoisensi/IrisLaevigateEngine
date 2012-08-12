#pragma once

#include "ILVector.h"
#include "ILSegment.h"
#include "ILDirection.h"

class ILLINE
{
public:
	ILVECTOR pass;
	ILDIRECTION dir;
	ILLINE()
	{
		pass = ILVECTOR();
		dir = ILDIRECTION();
	}
	ILLINE(double X, double Y, double Z, double DXZ, double DY)
	{
		pass = ILVECTOR(X,Y,Z);
		dir = ILDIRECTION(DXZ,DY);
	}
	ILLINE(ILVECTOR Pass,ILDIRECTION Dir)
	{
		pass = Pass;
		dir = Dir;
	}
	ILLINE(ILSEGMENT Segment)
	{
		pass = Segment.origin;

	}
};