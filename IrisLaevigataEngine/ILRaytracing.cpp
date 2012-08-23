#include "ILRaytracing.h"

void ILRaytracing::CreatRayInit(const double &Min, const double &Max, const ILDIRECTION &Dir,const ILANGLE &Width, const ILANGLE &Height, const ILVECTOR &Origin, const ILANGLE &Z)
{
	min = Min;
	max = Max - Min;
	dir = Dir;
	width = Width;
	height = Height;
	origin = Origin;
	z = Z;
}

ILSEGMENT ILRaytracing::CreateRay(const double x,const double y)const
{
	ILSEGMENT result;
	ILDIRECTION Dir = ILDIRECTION(width.angle * x + dir.xz.angle, height.angle * y + dir.y.angle);
	Dir = ILDIRECTION(Dir.xz*IL::ILMath::Cos(z) - Dir.y*IL::ILMath::Sin(z), Dir.xz*IL::ILMath::Sin(z) + Dir.y*IL::ILMath::Cos(z));
	result.origin = ILVECTOR(dir,min) + origin;
	result.vector = ILVECTOR(dir,max) + origin;
	return result;
}

void ILRaytracing::Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap)
{
	CreatRayInit(Camera.min,Camera.max,Camera.);
	for (int i=0;i<Bitmap.x;++i)
	{
		for(int j=0;j<Bitmap.y;++j)
		{

		}
	}
}