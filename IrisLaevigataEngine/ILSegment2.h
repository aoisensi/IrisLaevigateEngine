#ifndef H_ILSEGMENT2
#define H_ILSEGMENT2

#include "ILVector2.h"

class ILSEGMENT2
{
public:
	ILVECTOR2 a,b;
	ILSEGMENT2(void);
	ILSEGMENT2(const ILVECTOR2 &A,const ILVECTOR2 &B);
};

#endif