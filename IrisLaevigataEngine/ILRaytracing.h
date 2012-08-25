#include "ILSegment.h"
#include "ILAngle.h"
#include "ILRotation.h"
#include "ILCamera.h"
#include "ILSpace.h"
#include "ILBitmap.h"
#include "ILChk.h"

namespace IL
{
	class ILRaytracing
	{
	private:
		double min;
		double max;
		ILROTATION rotation;
		ILANGLE width;
		ILANGLE height;
		ILVECTOR origin;
		void CreatRayInit(const double &Min, const double &Max, const ILROTATION Rotation, const ILANGLE &Width, const ILANGLE &Height, const ILVECTOR &Origin);
		ILSEGMENT CreateRay(const double &x,const double &y)const;
	public:
		void Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap);
	};
}