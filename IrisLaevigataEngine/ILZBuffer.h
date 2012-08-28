#include "ILSpace.h"
#include "ILCamera.h"
#include "ILBitmap.h"
#include "ILVector2.h"

namespace IL
{
	class ILZBuffer
	{
	public:
		double **zbuffer;
		int x;
		void Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap);
		void dispouse(void);
		void Projection(const ILVECTOR &Vector, const ILCAMERA &Camera, const int &Width, const int &Height, int &X, int &Y, double &Z);
		void Rotate2D(double &X, double &Y, const ILANGLE &Angle);
	};
}