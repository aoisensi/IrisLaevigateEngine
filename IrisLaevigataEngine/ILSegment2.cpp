#include "ILSegment2.h"

ILSEGMENT2::ILSEGMENT2(void)
{
	a = ILVECTOR2();
	b = ILVECTOR2();
}
ILSEGMENT2::ILSEGMENT2(const ILVECTOR2 &A,const ILVECTOR2 &B)
{
	a = A;
	b = B;
}