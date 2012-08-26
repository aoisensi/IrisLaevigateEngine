#include <iostream>
#include "IrisLaevigataEngine.h"

using namespace std;

int main()
{
	ILSEGMENT testseg = ILSEGMENT(0,100,0,0,-100,0);
	ILVSURFACE testsur = ILVSURFACE(ILSURFACE(100,0,-50,-100,0,-50,0,0,100),ILCOLOR());
	ILVSURFACE testsuf = ILVSURFACE(ILSURFACE(0,0,100,-100,0,-50,100,0,-50),ILCOLOR());
	ILVECTOR testvec;
	double t,u,v;
	IL::ILRaytracing render;
	if(render.RayCheckSurface(testseg,testsur.surface,t,u,v))
	{
		cout << "true" << endl;
		cout << t << endl;
		cout << u << endl;
		cout << v << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	testvec;
	if(render.RayCheckSurface(testseg,testsuf.surface,t,u,v))
	{
		cout << "true" << endl;
		cout << t << endl;
		cout << u << endl;
		cout << v << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	getchar();
	return 0;
}