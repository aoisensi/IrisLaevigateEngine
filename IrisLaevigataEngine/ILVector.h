#ifndef H_ILVECTOR
#define H_ILVECTOR

#include "ILMath.h"
#include "ILDirection.h"

class ILDIRECTION;

class ILVECTOR
{
public:
	double x;
	double y;
	double z;

	ILVECTOR(void);
	ILVECTOR(const double &X,const double &Y,const double &Z);
	ILVECTOR Add(const ILVECTOR &obj)const;
	ILVECTOR Sub(const ILVECTOR &obj)const;
	ILVECTOR Mul(const double &obj)const;
	ILVECTOR operator+(const ILVECTOR& right)const;
	ILVECTOR operator-(const ILVECTOR& right)const;
	ILVECTOR operator*(const double& right)const;
	ILVECTOR operator/(const double& right)const;
	double Inner(const ILVECTOR &value);
	ILVECTOR Cross(const ILVECTOR &value);
	ILVECTOR Center(const ILVECTOR &value);
	double Norm(void);
	ILDIRECTION Direction(void);
};

#endif