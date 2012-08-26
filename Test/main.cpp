#include <iostream>
#include "IrisLaevigataEngine.h"

using namespace std;

int main()
{
	ILSEGMENT testseg = ILSEGMENT(0,100,0,0,-100,0);
	ILSURFACE testsur = ILSURFACE(100,0,-50,-100,0,-50,0,0,100,ILCOLOR());
	ILSURFACE testsuf = ILSURFACE(0,0,100,-100,0,-50,100,0,-50,ILCOLOR());
	ILVECTOR testvec;
	if(IL::ILChk::SegBySur(testseg,testsur,testvec))
	{
		cout << "true" << endl;
		cout << testvec.x << endl;
		cout << testvec.y << endl;
		cout << testvec.z << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	testvec;
	if(IL::ILChk::SegBySur(testseg,testsuf,testvec))
	{
		cout << "true" << endl;
		cout << testvec.x << endl;
		cout << testvec.y << endl;
		cout << testvec.z << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	getchar();
	return 0;
}