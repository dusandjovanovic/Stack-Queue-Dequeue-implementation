// Lab0307.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackMerged.h"

int main()
{
	stackArray stackMerged(10);

	stackMerged.pushFirst(1);
	stackMerged.pushFirst(2);
	
	cout << stackMerged.getTopFirst() << endl;

	stackMerged.pushSecond(3);
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;
	stackMerged.pushFirst(4);
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;
	stackMerged.popFirst();
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;
	stackMerged.pushSecond(11);
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;
	stackMerged.pushSecond(12);
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;
	stackMerged.pushFirst(13);
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;
	stackMerged.popFirst();
	cout << stackMerged.getTopFirst() << " " << stackMerged.getTopSecond() << endl;

	system("pause");
    return 0;
}

