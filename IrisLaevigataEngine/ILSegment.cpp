#include "ILSegment.h"

ILSEGMENT::ILSEGMENT()
{
	origin = ILVECTOR();
	vector = ILVECTOR();
}
ILSEGMENT::ILSEGMENT(const ILVECTOR &Origin, const ILVECTOR &Vector)
{
	origin = Origin;
	vector = Vector;
}
ILSEGMENT::ILSEGMENT(const double &OriginX, const double &OriginY, const double &OriginZ, const double &VectorX, const double &VectorY, const double &VectorZ)
{
	origin = ILVECTOR(OriginX,OriginY,OriginZ);
	vector = ILVECTOR(VectorX,VectorY,VectorZ);
}
ILLINE ILSEGMENT::Line()
{
	return ILLINE(origin.x, origin.y, origin.z, vector.y/vector.x, vector.z/vector.x);
}
ILVECTOR ILSEGMENT::Unorigin(void)const
{
	return origin + vector;
}