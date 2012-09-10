#include "ILDoubleBuffer.h"

void ILDOUBLEBUFFER::Initialize(const int &X, const int &Y)
{
	buffer = new double*[X];
	for(int i=0;i<X;++i)
	{
		buffer[i] = new double[Y];
	}
}
void ILDOUBLEBUFFER::Set(const int &X, const int &Y, const double &Value)
{
	buffer[X][Y] = Value;
}
double ILDOUBLEBUFFER::Get(const int &X, const int &Y)
{
	return buffer[X][Y];
}
int ILDOUBLEBUFFER::X(void)
{
	return sizeof(buffer) / sizeof (double);
}
int ILDOUBLEBUFFER::Y(void)
{
	if(this->X() == 0)
	{
		return 0;
	}
	return sizeof(buffer[0]) / sizeof (double);
}
void ILDOUBLEBUFFER::dispose(void)
{
	for(int i=0;i<this->X();++i)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
}
void ILDOUBLEBUFFER::AllSet(const double &Value)
{
	for(int i=0;i<this->X();++i)
	{
		for(int j=0;j<this->Y();++j)
		{
			this->buffer[i][j] = Value;
		}
	}
}
double** ILDOUBLEBUFFER::Pointer()
{
	return buffer;
}