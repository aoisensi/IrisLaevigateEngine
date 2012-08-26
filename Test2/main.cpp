#include <iostream>
#include <stdio.h>
#include "IrisLaevigataEngine.h"

using namespace std;

const int x = 16;
const int y = 12;

int main()
{
	IL::ILRaytracing Rendering;
	Rendering.CreatRayInit(1,100,ILROTATION(),ILANGLE(45),ILANGLE(45),ILVECTOR());
	for (int i=0;i<x;++i)
	{
		for (int j=0;j<y;++j)
		{
			ILSEGMENT seg = Rendering.CreateRay(2.0F*i/x-1.0F,2.0F*j/y-1.0F);
			printf("%.4lf ,%.4lf\n%.4lf ,%.4lf ,%.4lf  - %.4lf ,%.4lf ,%.4lf\n\n",2.0F*i/x-1.0F,2.0F*j/y-1.0F, seg.origin.x, seg.origin.y, seg.origin.z, seg.vector.x, seg.vector.y, seg.vector.z);
		}
	}
	getchar();
}