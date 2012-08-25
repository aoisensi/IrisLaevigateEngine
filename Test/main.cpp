#include <stdio.h>
#include "IrisLaevigataEngine.h"

int main()
{
	ILSPACE MainSpace = ILSPACE(255);
	ILCOLOR Black = ILCOLOR(0,0,0);
	ILCOLOR White = ILCOLOR(255,255,255);
	ILBITMAP picture = ILBITMAP(640,480);
	MainSpace.AddSurface(ILSURFACE(ILVECTOR(100,100,100),ILVECTOR(-100,100,100),ILVECTOR(100,-100,100),Black));
	MainSpace.AddSurface(ILSURFACE(ILVECTOR(100,100,100),ILVECTOR(100,-100,100),ILVECTOR(100,100,-100),Black));
	MainSpace.AddSurface(ILSURFACE(ILVECTOR(100,100,100),ILVECTOR(100,100,-100),ILVECTOR(-100,100,100),Black));
	MainSpace.AddSurface(ILSURFACE(ILVECTOR(-100,100,100),ILVECTOR(100,-100,100),ILVECTOR(100,100,-100),White));
	ILCAMERA Camera = ILCAMERA(1,10000,ILROTATION(0,0,0),ILVECTOR(0,0,-1000),ILANGLE(45),ILANGLE(45/4*3),ILCOLOR(0,0,255));
	IL::ILRaytracing* render = new IL::ILRaytracing();
	render->Rendering(MainSpace,Camera,picture);
	getchar();
	picture.dispose();
	return 0;
}