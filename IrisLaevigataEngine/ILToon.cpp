#include "ILToon.h"
namespace IL
{
	namespace Rendering
	{
		Toon::Toon(ILBITMAP &Bitmap)
		{
			buffer.Initialize(Bitmap.x, Bitmap.y);
			bitmap = &Bitmap;
		}
		void Toon::Rendering(const ILTSPACE &Space, const ILCAMERA &Camera)
		{
			int bmpx = bitmap->x;
			int bmpy = bitmap->y;
			for(int i=0;i<Space.numberofsurface;++i)
			{
				ILTSURFACE TSurface = Space.Surface(i);
				double ax,bx,cx,ay,by,cy,az,bz,cz;
				int maxx, maxy,minx, miny;
				Projection(TSurface.surface.a, Camera, bmpx, bmpy, ax, ay, az);
				Projection(TSurface.surface.b, Camera, bmpx, bmpy, bx, by, bz);
				Projection(TSurface.surface.c, Camera, bmpx, bmpy, cx, cy, cz);
				ILVECTOR2 A = ILVECTOR2(ax,ay);
				ILVECTOR2 B = ILVECTOR2(bx,by);
				ILVECTOR2 C = ILVECTOR2(cx,cy);
				maxx = (int)MaxIn3(ax, bx, cx);
				maxy = (int)MaxIn3(ay, by, cy);
				minx = (int)MinIn3(ax, bx, cx);
				miny = (int)MinIn3(ay, by, cy);
				maxx = maxx < bmpx ? maxx : bmpx;
				maxy = maxy < bmpy ? maxy : bmpy;
				minx = minx > 0 ? minx : 0;
				miny = miny > 0 ? miny : 0;
				for(int j=minx;j<maxx;++j)
				{
					for(int k=miny;k<maxy;++k)
					{
						if(IsPointInTriangle(A,B,C,ILVECTOR2(j,k)))
						{
							bitmap->PSet(j,k,TSurface.color);
						}
					}
				}
			}
		}
		void Toon::Projection(const ILVECTOR &Vector, const ILCAMERA &Camera, const int &Width, const int &Height, double &X, double &Y, double &Z)
		{
			ILVECTOR Result = Vector - Camera.vector;
			Rotate2D(Result.x, Result.z, Camera.rotation.y);
			Rotate2D(Result.z, Result.y, Camera.rotation.x);
			Rotate2D(Result.x, Result.y, Camera.rotation.z);
			X = (Result.x / Result.z / IL::ILMath::Tan(Camera.fovx)) * Width * 0.5 + Width * 0.5;
			Y = (Result.y / Result.z / IL::ILMath::Tan(Camera.fovy)) * Height * 0.5 + Height * 0.5;
			Z = Result.z;
			return;
		}
		void Toon::Rotate2D(double &X, double &Y, const ILANGLE &Angle)
		{
			double bx = X;
			double by = Y;
			X = bx * IL::ILMath::Cos(Angle) - by * IL::ILMath::Sin(Angle);
			Y = bx * IL::ILMath::Sin(Angle) + by * IL::ILMath::Cos(Angle);
			return;
		}
		bool Toon::IsPointInTriangle(const ILVECTOR2 &A, const ILVECTOR2 &B, const ILVECTOR2 &C, const ILVECTOR2 &P)
		{
			if((P-A).CrossDouble(B-A) > 0.0F)
			{
				if((P-B).CrossDouble(C-B) > 0.0F)
				{
					if((P-C).CrossDouble(A-C) > 0.0F)
					{
						return true;
					}
				}
			}
			return false;
		}
		double Toon::MaxIn3(const double &A, const double &B, const double &C)
		{
			return A>B ? (A>C ? A : C) : (B>C ? B : C); 
		}
		double Toon::MinIn3(const double &A, const double &B, const double &C)
		{
			return A<B ? (A<C ? A : C) : (B<C ? B : C); 
		}
	}
}