#include <iostream>
#include "IrisLaevigataEngine.h"

using namespace std;

int main()
{
	ILVECTOR foo = ILVECTOR(0,10,-20);
	ILVECTOR bar = ILVECTOR(10,60,10);
	ILVECTOR test = foo - - bar;
	cout << test.x << "," << test.y << "," << test.z << endl;
	getchar();
	return 0;
}