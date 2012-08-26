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
		ILDIRECTION Dir = ILDIRECTION(width.angle * x, height.angle * y);
		Dir = ILDIRECTION(Dir.xz*IL::ILMath::Cos(rotation.z) - Dir.y*IL::ILMath::Sin(rotation.z), Dir.xz*IL::ILMath::Sin(rotation.z) + Dir.y*IL::ILMath::Cos(rotation.z));
		Dir = ILDIRECTION(Dir.xz + rotation.x, Dir.y + rotation.y);
		result.origin = ILVECTOR(ILDIRECTION(Dir.xz,Dir.y),min) + origin;
		result.vector = ILVECTOR(ILDIRECTION(Dir.xz,Dir.y),max);
		return result;
	}

	void ILRaytracing::Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap)
	{
		CreatRayInit(Camera.min,Camera.max,Camera.rotation,Camera.fovx,Camera.fovy,Camera.vector);
		for (int i=0;i<Bitmap.x;++i)
		{
			for(int j=0;j<Bitmap.y;++j)
			{
				ILSEGMENT Ray = CreateRay(2.0F*i/Bitmap.x-1.0F, 2.0F*j/Bitmap.y-1.0F);
				double m = max;
				int s = 0;
				for(int k=0;k<Space.surfacen;++k)
				{
					ILVECTOR Result;
					double T,U,V;
					if(RayCheck(Ray, Space.surface[k],T,U,V))
					{
						double o = T;
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

	bool ILRaytracing::RayCheck(const ILSEGMENT &Segment,const ILSURFACE &Surface, double &T, double &U, double &V)
	{
		//http://ft-lab.ne.jp/cgi-bin/wiki.cgi?page=%B8%F2%BA%B9%C8%BD%C4%EA_3DCG
		ILVECTOR e1 = Surface.b - Surface.a;
		ILVECTOR e2 = Surface.c - Surface.a;
		ILVECTOR pvec = e2.Cross(Segment.vector);
		ILVECTOR tvec, qvec;
		double t,u,v;
		double det = e1.Inner(pvec);
		if(det < 1e-3)
		{
			tvec = Segment.origin - Surface.a;
			u = tvec.Inner(pvec);
			if(u<0.0F || u>det)
			{
				return false;
			}
			qvec = tvec.Cross(Surface.b);
			v = qvec.Inner(Segment.vector);
			if (v < 0.0 || u + v > det)
			{
				return false;
			}
		}
		else if (det < -(1e-3))
		{
			tvec = Segment.origin - Surface.a;
			u = tvec.Inner(pvec);
			if(u>0.0F || u<det)
			{
				return false;
			}
			qvec = tvec.Cross(Surface.b);
			v = qvec.Inner(Segment.vector);
			if (v > 0.0 || u + v < det)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		double inv_det = 1.0f / det;

		t = e2.Inner(qvec);
		T = inv_det * t;
		U = inv_det * u;
		V = inv_det * v;

		return true;
	}
}