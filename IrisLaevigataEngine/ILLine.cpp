#include "ILLine.h"

ILLINE::ILLINE()
{
	pass = ILVECTOR();
	dir = ILDIRECTION();
}
ILLINE::ILLINE(const double &X, const double &Y, const double &Z, const double &DXZ, const double &DY)
{
	pass = ILVECTOR(X,Y,Z);
	dir = ILDIRECTION(DXZ,DY);
}
ILLINE::ILLINE(const ILVECTOR &Pass,const ILDIRECTION &Dir)
{
	pass = Pass;
	dir = Dir;
}
ILLINE::ILLINE(const ILSEGMENT &Segment)
{
	pass = Segment.origin;
}