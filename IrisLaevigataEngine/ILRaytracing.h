#include "ILSegment.h"
#include "ILAngle.h"
#include "ILDirection.h"
#include "ILCamera.h"
#include "ILSpace.h"
#include "ILBitmap.h"

class ILRaytracing
{
private:
	double min;
	double max;
	ILDIRECTION dir;
	ILANGLE width;
	ILANGLE height;
	ILVECTOR origin;
	ILANGLE z;
	void CreatRayInit(const double &Min, const double &Max, const ILDIRECTION &Dir,const ILANGLE &Width, const ILANGLE &Height, const ILVECTOR &Origin, const ILANGLE &Z);
	ILSEGMENT CreateRay(const double x,const double y)const;
public:
	void Rendering(const ILSPACE &Space, const ILCAMERA &Camera, ILBITMAP &Bitmap);
};