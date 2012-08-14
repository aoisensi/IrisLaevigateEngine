
#ifndef H_ILANGLE
#define H_ILANGLE

class ILANGLE
{
public:
	double angle;
	ILANGLE()
	{
		angle = 0;
	}
	ILANGLE(double Angle)
	{
		angle = Angle / 180.0f;
	}
	ILANGLE operator+()
	{
		return ILANGLE(angle);
	}
	ILANGLE operator-()
	{
		return ILANGLE(-angle);
	}
	ILANGLE operator+(ILANGLE value)
	{
		return ILANGLE(angle + value.angle);
	}
	ILANGLE operator-(ILANGLE value)
	{
		return ILANGLE(angle - value.angle);
	}
	ILANGLE operator*(double value)
	{
		return ILANGLE(angle * value);
	}
	ILANGLE operator/(double value)
	{
		return ILANGLE(angle / value);
	}
};

#endif