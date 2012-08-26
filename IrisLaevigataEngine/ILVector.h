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
	ILVECTOR(const ILDIRECTION &Direction, const double &Norm);
	ILVECTOR Add(const ILVECTOR &obj)const;
	ILVECTOR Sub(const ILVECTOR &obj)const;
	ILVECTOR Mul(const double &obj)const;
	bool Equal(const ILVECTOR &obj, const double &Error)const;
	ILVECTOR operator+(const ILVECTOR& right)const;
	ILVECTOR operator-(const ILVECTOR& right)const;
	ILVECTOR operator*(const double& right)const;
	ILVECTOR operator/(const double& right)const;
	double Dot(const ILVECTOR &value)const;
	ILVECTOR Cross(const ILVECTOR &value)const;
	ILVECTOR Center(const ILVECTOR &value);
	double Norm(void)const;
	ILDIRECTION Direction(void);
	ILVECTOR Normalize(void)const;
};

#endif