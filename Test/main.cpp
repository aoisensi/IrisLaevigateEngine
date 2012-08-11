#include <stdio.h>
#include "IrisLaevigataEngine.h"

int main()
{
	ILVECTOR foo = ILVECTOR(0,10,-20);
	ILVECTOR bar = ILVECTOR(10,60,10);
	ILVECTOR test = foo - - bar;
	ILLINE line = ILLINE(ILSEGMENT(foo,bar));
	printf("%f,%f,%f\n",test.x,test.y,test.z);
	printf("Sqrt(2) = %.30f\n",IL::ILMath::Sqrt(2));
	printf("%f\n",test.Norm());
	printf("Sin(60) = %.30f\n",IL::ILMath::Sin(30));
	printf("%f,%f,%f,%f,%f\n",line.a,line.b,line.c,line.d,line.e);
	getchar();
	return 0;
}