#pragma once

#include "ILVector.h"
#include "ILLine.h"

class ILSEGMENT
{
public:
	ILVECTOR origin;
	ILVECTOR vector;
	ILSEGMENT()
	{
		origin = ILVECTOR();
		vector = ILVECTOR();
	}
	ILSEGMENT(ILVECTOR Origin,ILVECTOR Vector)
	{
		origin = Origin;
		vector = Vector;
	}
	ILSEGMENT(double OriginX,double OriginY,double OriginZ,double VectorX,double VectorY,double VectorZ)
	{
		origin = ILVECTOR(OriginX,OriginY,OriginZ);
		vector = ILVECTOR(VectorX,VectorY,VectorZ);
	}
	/*
	ILLINE Line()
	{
		return ILLINE(origin.x, origin.y, origin.z, vector.y/vector.x, vector.z/vector.x);
	}
	*/
};