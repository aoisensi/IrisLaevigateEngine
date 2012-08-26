#ifndef H_ILVBALL
#define H_ILVBALL

#include "ILBall.h"
#include "ILColor.h"

class ILVBALL
{
public:
	ILBALL ball;
	ILCOLOR color;
	ILVBALL(void);
	ILVBALL(const ILBALL &Ball, const ILCOLOR &Color);
};

#endif