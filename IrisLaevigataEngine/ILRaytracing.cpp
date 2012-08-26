#include "ILRaytracing.h"
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

namespace IL
{
	void ILRaytracing::CreatRayInit(const double &Min, const double &Max, const ILROTATION Rotation, const ILANGLE &FovX, const ILANGLE &FovY, const ILVECTOR &Origin, const int &Width, const int &Height)
	{
		min = Min;
		max = Max - Min;
		rotation = ILROTATION(Rotation.x.angle,Rotation.y.angle-90,Rotation.z.angle);
		fovx = FovX;
		fovy = FovY;
		origin = Origin;
		height = Height-1;
		width = Width-1;
	}

	ILSEGMENT ILRaytracing::CreateRay(const int &x,const int &y)const
	{
		ILSEGMENT result;
		ILDIRECTION Dir = ILDIRECTION((2.0F * x / width - 1.0F) * fovx.angle, (2.0F * y / height - 1.0F) * fovy.angle);
		Dir = ILDIRECTION(Dir.xz.angle * IL::ILMath::Cos(rotation.z) - Dir.y.angle * IL::ILMath::Sin(rotation.z), Dir.xz.angle * IL::ILMath::Sin(rotation.z) + Dir.y.angle * IL::ILMath::Cos(rotation.z));
		Dir = ILDIRECTION(ILANGLE(Dir.xz + rotation.y), ILANGLE(Dir.y + rotation.x));
		result.origin = ILVECTOR(ILDIRECTION(Dir.xz,Dir.y),min) + origin;
		result.vector = ILVECTOR(ILDIRECTION(Dir.xz,Dir.y),max);
		return result;
	}

	void ILRaytracing::Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap)
	{
		CreatRayInit(Camera.min,Camera.max,Camera.rotation,Camera.fovx,Camera.fovy,Camera.vector,Bitmap.x,Bitmap.y);
		for (int i=0;i<Bitmap.y;++i)
		{
			for(int j=0;j<Bitmap.x;++j)
			{
				ILCOLOR BitColor = Camera.backgroundcolor;
				ILSEGMENT Ray = CreateRay(j,i);
				double m = max;
				for(int k=0;k<Space.numberofsurface;++k)
				{
					//tmp
				}
				for(int k=0;k<Space.numberofellipsoid;++k)
				{
					//tmp
				}
				for(int k=0;k<Space.numberofball;++k)
				{
					double Distance;
					if(ChkBall(Space.Ball(k).ball, Ray, Distance))
					{
						if(m > Distance)
						{
							m = Distance;
							BitColor = Space.Ball(k).color;
						}
					}
				}
				Bitmap.PSet(j,i,BitColor);
			}
		}
	}

	bool ILRaytracing::ChkBall(const ILBALL &Ball, const ILSEGMENT &Segment, double &Distance)
	{
		//http://marupeke296.com/COL_3D_No1_PointToLine.html
		ILVECTOR vP = Ball.vector - Segment.origin;
		double t = Segment.vector.Normalize().Dot(vP) / Segment.vector.Norm();
		ILVECTOR PsH = Segment.vector * t;
		ILVECTOR h = PsH - vP;
		double norm = h.Norm();
		if(norm < Ball.radius)
		{
			Distance = PsH.Norm() - IL::ILMath::Sqrt(Ball.radius*Ball.radius - norm*norm);
			return true;
		}
		return false;
	}
}