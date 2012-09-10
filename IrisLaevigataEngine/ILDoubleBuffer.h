#ifndef H_ILDOUBLEBUFFER
#define H_ILDOUBLEBUFFER

class ILDOUBLEBUFFER
{
private:
	double** buffer;
public:
	void Initialize(const int &X, const int &Y);
	void Set(const int &X, const int &Y, const double &Value);
	double Get(const int &X, const int &Y);
	int X(void);
	int Y(void);
	void dispose(void);
	void AllSet(const double &Value);
	double** Pointer(void);

};

#endif