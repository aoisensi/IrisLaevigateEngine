#ifndef H_ILBITMAP
#define H_ILBITMAP

#include "ILColor.h"

class ILBITMAP
{
public:
	int x;
	int y;
private:
	ILCOLOR **dot;
public:
	ILBITMAP(const int &X, const int &Y);
	ILCOLOR PGet(const int &X, const int &Y);
	void PSet(const int &X, const int &Y, const ILCOLOR Color);
	void dispose();
};

#endif