#include "ILVBall.h"

ILVBALL::ILVBALL()
{
	ball = ILBALL();
	color = ILCOLOR();
}

ILVBALL::ILVBALL(const ILBALL &Ball, const ILCOLOR &Color)
{
	ball = Ball;
	color = Color;
}