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
		if(maxx < 0 || maxy < 0 || minx > Bitmap.x || miny > Bitmap.y)
		{
			continue;
		}
		minx = (0 > minx)? 0:minx;
		maxx = (Bitmap.x < maxx)? Bitmap.x : maxx;
		miny = (0 > miny)? 0:miny;
		maxy = (Bitmap.y < maxy)? Bitmap.y : maxy;
		ILVECTOR2 a = ILVECTOR2(ax, ay);
		ILVECTOR2 b = ILVECTOR2(bx, by);
		ILVECTOR2 c = ILVECTOR2(cx, cy);
		ILVECTOR2 ab = b - a;
		ILVECTOR2 bc = c - b;
		ILVECTOR2 ca = a - c;
		for(int j=0;j<Bitmap.x;++j)
		{
			for(int k=0;k<Bitmap.y;++k)
			{
				ILVECTOR2 p = ILVECTOR2(j,k);
				ILVECTOR2 ap = p - a;
				ILVECTOR2 bp = p - b;
				ILVECTOR2 cp = p - c;
				double A = ab.CrossDouble(ap) * ILMath::RBIZTZ(ab.CrossDouble(-ca));
				if(A<0.0F || A>1.0F)
				{
					continue;
				}
				double B = bc.CrossDouble(bp) * ILMath::RBIZTZ(bc.CrossDouble(-ab));
				if(B<0.0F || B>1.0F)
				{
					continue;
				}
				double C = ca.CrossDouble(cp) * ILMath::RBIZTZ(ca.CrossDouble(-bc));
				if(C<0.0F || C>1.0F)
				{
					continue;
				}
				double* buffer = &zbuffer[j][k];
				if(*buffer > Camera.min)
				{
					double R = ILMath::RBIZTZ(A*B*C);
					double Z = A*R + B*R + C*R;
					if(*buffer > Z)
					{
						*buffer = Z;
						Bitmap.PSet(j,k,VSurface.color);
					}
				}
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
	X = (int)(Result.x * IL::ILMath::RBIZTZ(Result.z) * IL::ILMath::RBIZTZ(IL::ILMath::Tan(Camera.fovx)) * Width * 0.5 + Width * 0.5);
	Y = (int)(Result.y * IL::ILMath::RBIZTZ(Result.z) * IL::ILMath::RBIZTZ(IL::ILMath::Tan(Camera.fovy)) * Height * 0.5 + Height * 0.5);
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

double IL::ILZBuffer::DistPointVector(const ILVECTOR2 &Line, const ILVECTOR2 &Point)
{
	return Line.CrossDouble(Point) * IL::ILMath::RBIZTZ(Line.Norm());
}

