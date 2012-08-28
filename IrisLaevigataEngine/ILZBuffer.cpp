#include "ILZBuffer.h"

void IL::ILZBuffer::Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap)
{
	this->x = Bitmap.x;
	zbuffer = new double*[Bitmap.x];
	for(int i=0;i<Bitmap.x;++i)
	{
		zbuffer[i] = new double[Bitmap.y];
		for(int j=0;j<Bitmap.y;++j)
		{
			zbuffer[i][j] = Camera.max;
			Bitmap.PSet(i,j,Camera.backgroundcolor);
		}
	}
	for(int i=0;i<Space.numberofsurface;++i)
	{
		int ax, ay, bx, by, cx, cy;
		double az, bz, cz;
		int minx, maxx, miny, maxy;
		ILVSURFACE VSurface = Space.Surface(i);
		ILSURFACE Surface = VSurface.surface;
		Projection(Surface.a, Camera, Bitmap.x, Bitmap.y, ax, ay, az);
		Projection(Surface.b, Camera, Bitmap.x, Bitmap.y, bx, by, bz);
		Projection(Surface.c, Camera, Bitmap.x, Bitmap.y, cx, cy, cz);
		minx = (ax < bx)?((ax < cx)?ax : cx):((bx < cx)?bx : cx);
		maxx = (ax > bx)?((ax > cx)?ax : cx):((bx > cx)?bx : cx);
		miny = (ay < by)?((ay < cy)?ay : cy):((by < cy)?by : cy);
		maxy = (ay > by)?((ay > cy)?ay : cy):((by > cy)?by : cy);
		ILVECTOR2 a = ILVECTOR2(ax, ay);
		ILVECTOR2 b = ILVECTOR2(bx, by);
		ILVECTOR2 c = ILVECTOR2(cx, cy);
		ILVECTOR2 ab = b - a;
		ILVECTOR2 bc = c - b;
		ILVECTOR2 ca = a - c;
		for(int j=minx;j<maxx;++j)
		{
			if(j<0 || j>=Bitmap.x)
			{
				continue;
			}
			for(int k=miny;k<maxy;++k)
			{
				if(k<0 || k>=Bitmap.y)
				{
					continue;
				}
				ILVECTOR2 p = ILVECTOR2(j,k);
				double A = (bc.Dot(-ab) / bc.Dot(p - b));
				if(A < 1.0F && A > 0.0F)
				{
					break;
				}
				double B = (ca.Dot(-bc) / ca.Dot(p - c));
				if(B < 1.0F && B > 0.0F)
				{
					break;
				}
				double C = (ab.Dot(-ca) / ab.Dot(p - a));
				if(C < 1.0F && C > 0.0F)
				{
					break;
				}
				double All = 1/(A*B*C);
				double Z = A*All*az + B*All*bz + C*All*cz;
				if(Z < Camera.min)
				{
					break;
				}
				if(zbuffer[j][k] < Z)
				{
					break;
				}
				zbuffer[j][k] = Z;
				Bitmap.PSet(j,k,VSurface.color);
			}
		}
	}
}

void IL::ILZBuffer::dispouse()
{
	for(int i=0;i<this->x;++i)
	{
		delete[] zbuffer[i];
		zbuffer[i] = 0;
	}
	delete zbuffer;
	zbuffer = 0;
}

void IL::ILZBuffer::Projection(const ILVECTOR &Vector, const ILCAMERA &Camera, const int &Width, const int &Height, int &X, int &Y, double &Z)
{
	ILVECTOR Result = Vector - Camera.vector;
	Rotate2D(Result.x, Result.z, Camera.rotation.y);
	Rotate2D(Result.z, Result.y, Camera.rotation.x);
	Rotate2D(Result.x, Result.y, Camera.rotation.z);
	X = (int)(Result.x / Result.z / IL::ILMath::Tan(Camera.fovx) * Width * 0.5 + Width * 0.5);
	Y = (int)(Result.y / Result.z / IL::ILMath::Tan(Camera.fovy) * Height * 0.5 + Height * 0.5);
	Z = Result.z;
	return;
}

void IL::ILZBuffer::Rotate2D(double &X, double &Y, const ILANGLE &Angle)
{
	double bx = X;
	double by = Y;
	X = bx * IL::ILMath::Cos(Angle) - by * IL::ILMath::Sin(Angle);
	Y = bx * IL::ILMath::Sin(Angle) + by * IL::ILMath::Cos(Angle);
	return;
}