#include <iostream>
#include <stdio.h>
#include "IrisLaevigataEngine.h"

using namespace std;

const int x = 40;
const int y = 30;

int main()
{
	ILBALL Ball = ILBALL(ILVECTOR(),100.0F);
	IL::ILRaytracing render;
	render.CreatRayInit(1,1000,ILROTATION(0,0,0),ILANGLE(45),ILANGLE(45/4*3),ILVECTOR(0,0,-800),x,y);
	for(int i=0;i<y;++i)
	{
		for(int j=0;j<x;++j)
		{
			ILSEGMENT Segment = render.CreateRay(j,i);
			ILVECTOR V;
			if(render.ChkBall(Ball,Segment,V))
			{
				cout << "¡";
			}
			else
			{
				cout << " ";
			}
		}
	}
	getchar();
}