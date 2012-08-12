#pragma once

#include "ILVector.h"
#include "ILFlat.h"

class ILSURFACE
{
public:
	ILVECTOR a, b, c;
	ILSURFACE()
	{
		a = ILVECTOR();
		b = ILVECTOR();
		c = ILVECTOR();
	}
	ILSURFACE(ILVECTOR A, ILVECTOR B, ILVECTOR C)
	{
		a = A;
		b = B;
		c = C;
	}
	ILSURFACE(double ax,double ay,double az,double bx,double by,double bz,double cx,double cy,double cz)
	{
		a = ILVECTOR(ax,ay,az);
		b = ILVECTOR(bx,by,bz);
		c = ILVECTOR(cx,cy,cz);
	}
	ILFLAT Flat()
	{
		ILFLAT result;
		ILVECTOR cross = (b-a).Cross(c-a);
		result.a = cross.x;
		result.b = cross.y;
		result.c = cross.z;
		result.d = -(cross.x * this->a.x + cross.y * this->a.y + cross.z * this->a.z);
		return result;
	}

};