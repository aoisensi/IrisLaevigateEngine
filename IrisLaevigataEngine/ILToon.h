#include "ILSegment.h"
#include "ILAngle.h"
#include "ILRotation.h"
#include "ILCamera.h"
#include "ILTSpace.h"
#include "ILBitmap.h"
#include "ILDoubleBuffer.h"
#include "ILVector2.h"

namespace IL
{
	namespace Rendering
	{
		class Toon
		{
		private:
			ILBITMAP* bitmap;
			ILDOUBLEBUFFER buffer;
		public:
			Toon(ILBITMAP &Bitmap);
			void Rendering(const ILTSPACE &Space, const ILCAMERA &Camera);
			void Projection(const ILVECTOR &Vector, const ILCAMERA &Camera, const int &Width, const int &Height, double &X, double &Y, double &Z);
			void Rotate2D(double &X, double &Y, const ILANGLE &Angle);
			bool IsPointInTriangle(const ILVECTOR2 &A, const ILVECTOR2 &B, const ILVECTOR2 &C, const ILVECTOR2 &P);
			double MaxIn3(const double &A, const double &B, const double &C);
			double MinIn3(const double &A, const double &B, const double &C);
		};
	}
}