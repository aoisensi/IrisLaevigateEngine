
#ifndef H_ILANGLE
#define H_ILANGLE

class ILANGLE
{
public:
	double angle;
	ILANGLE(void);
	ILANGLE(const double &Angle);
	ILANGLE operator+(void);
	ILANGLE operator-(void);
	ILANGLE operator+(const ILANGLE &value);
	ILANGLE operator-(const ILANGLE &value);
	ILANGLE operator*(const double &value);
	ILANGLE operator/(const double &value);
};

#endif