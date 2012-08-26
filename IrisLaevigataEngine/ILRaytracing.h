#include "ILSegment.h"
#include "ILAngle.h"
#include "ILRotation.h"
#include "ILCamera.h"
#include "ILSpace.h"
#include "ILBitmap.h"

namespace IL
{
	class ILRaytracing
	{
	public:
		double min;
		double max;
		ILROTATION rotation;
		ILANGLE fovx;
		ILANGLE fovy;
		int width, height;
		ILVECTOR origin;
		int antialiasing;
		void CreatRayInit(const double &Min, const double &Max, const ILROTATION Rotation, const ILANGLE &FovX, const ILANGLE &FovY, const ILVECTOR &Origin, const int &Width, const int &Height);
		ILSEGMENT CreateRay(const int &x,const int &y)const;
		void Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap);
		bool ChkBall(const ILBALL &Ball, const ILSEGMENT &Segment, ILVECTOR &Distance);
	};
}