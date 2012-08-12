#pragma once

#include "ILAngle.h"
#include "ILMath.h"
#include "ILVector.h"

class ILDIRECTION
{
public:
	ILANGLE xz;
	ILANGLE y;
	ILDIRECTION()
	{
		xz = ILANGLE();
		y = ILANGLE();
	}
	ILDIRECTION(double XZ,double Y)
	{
		xz = ILANGLE(XZ);
		y = ILANGLE(Y);
	}
	ILDIRECTION(ILANGLE XZ,ILANGLE Y)
	{
		xz = XZ;
		y = Y;
	}
	ILVECTOR Vector()
	{
		ILVECTOR result;
		result.x = IL::ILMath::Cos(xz) * IL::ILMath::Cos(y);
		result.y = IL::ILMath::Sin(y);
		result.z = IL::ILMath::Sin(xz) * IL::ILMath::Cos(y);
		return result;
	}
	ILVECTOR Vector(double Norm)
	{
		ILVECTOR result;
		result.x = IL::ILMath::Cos(xz) * IL::ILMath::Cos(y) * Norm;
		result.y = IL::ILMath::Sin(y) * Norm;
		result.z = IL::ILMath::Sin(xz) * IL::ILMath::Cos(y) * Norm;
		return result;
	}
};