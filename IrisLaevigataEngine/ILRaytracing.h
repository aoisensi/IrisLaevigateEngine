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
		ILANGLE width;
		ILANGLE height;
		ILVECTOR origin;
		void CreatRayInit(const double &Min, const double &Max, const ILROTATION Rotation, const ILANGLE &Width, const ILANGLE &Height, const ILVECTOR &Origin);
		ILSEGMENT CreateRay(const double &x,const double &y)const;
		void Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap);
		bool RayCheck(const ILSEGMENT &Segment,const ILSURFACE &Surface, double &T, double &U, double &V);
	};
}