#ifndef H_ILVECTOR2
#define H_ILVECTOR2

class ILVECTOR2
{
public:
	double x;
	double y;
	ILVECTOR2(void);
	ILVECTOR2(const double &X, const double &Y);
	ILVECTOR2 operator+(const ILVECTOR2 &right)const;
	ILVECTOR2 operator-(const ILVECTOR2 &right)const;
	ILVECTOR2 operator-(void);
	double Dot(const ILVECTOR2 &value)const;

};

#endif