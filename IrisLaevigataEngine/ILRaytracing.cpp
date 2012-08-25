#include "ILRaytracing.h"

namespace IL
{
	void ILRaytracing::CreatRayInit(const double &Min, const double &Max, const ILROTATION Rotation, const ILANGLE &Width, const ILANGLE &Height, const ILVECTOR &Origin)
	{
		min = Min;
		max = Max - Min;
		rotation = Rotation;
		width = Width;
		height = Height;
		origin = Origin;
	}

	ILSEGMENT ILRaytracing::CreateRay(const double &x,const double &y)const
	{
		ILSEGMENT result;
		ILDIRECTION Dir = ILDIRECTION(width.angle * x + rotation.x.angle, height.angle * y + rotation.y.angle);
		Dir = ILDIRECTION(Dir.xz*IL::ILMath::Cos(rotation.z) - Dir.y*IL::ILMath::Sin(rotation.z), Dir.xz*IL::ILMath::Sin(rotation.z) + Dir.y*IL::ILMath::Cos(rotation.z));
		result.origin = ILVECTOR(ILDIRECTION(rotation.x,rotation.y),min) + origin;
		result.vector = ILVECTOR(ILDIRECTION(rotation.x,rotation.y),max) + origin;
		return result;
	}

	void ILRaytracing::Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap)
	{
		CreatRayInit(Camera.min,Camera.max,Camera.rotation,Camera.fovx,Camera.fovy,Camera.vector);
		for (int i=0;i<Bitmap.x;++i)
		{
			for(int j=0;j<Bitmap.y;++j)
			{
				ILSEGMENT Ray = CreateRay(i/Bitmap.x*2-1,j/Bitmap.y*2-1);
				double m = max;
				int s = 0;
				for(int k=0;k<Space.surfacen;++k)
				{
					ILVECTOR Result;
					if(IL::ILChk::SegBySur(Ray, Space.surface[k],Result))
					{
						double o = (Result - Ray.origin).Norm();
						if(m > o)
						{
							m = o;
							s = k;
						}
					}
				}
				if(m == max)
				{
					Bitmap.PSet(i,j,Camera.backgroundcolor);
				}
				else
				{
					Bitmap.PSet(i,j,Space.surface[s].color);
				}
			}
		}
	}
}