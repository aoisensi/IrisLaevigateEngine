#include "ILDirection.h"

ILDIRECTION::ILDIRECTION()
{
	xz = ILANGLE();
	y = ILANGLE();
}
ILDIRECTION::ILDIRECTION(const double &XZ,const double &Y)
{
	xz = ILANGLE(XZ);
	y = ILANGLE(Y);
}
ILDIRECTION::ILDIRECTION(const ILANGLE &XZ,const ILANGLE &Y)
{
	xz = XZ;
	y = Y;
}
ILVECTOR ILDIRECTION::Vector()
{
	ILVECTOR result;
	result.x = IL::ILMath::Cos(xz) * IL::ILMath::Cos(y);
	result.y = IL::ILMath::Sin(y);
	result.z = IL::ILMath::Sin(xz) * IL::ILMath::Cos(y);
	return result;
}
ILVECTOR ILDIRECTION::Vector(const double &Norm)
{
	ILVECTOR result;
	result.x = IL::ILMath::Cos(xz) * IL::ILMath::Cos(y) * Norm;
	result.y = IL::ILMath::Sin(y) * Norm;
	result.z = IL::ILMath::Sin(xz) * IL::ILMath::Cos(y) * Norm;
	return result;
}