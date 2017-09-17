// Lab0310.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackArray.h"

int main()
{
	stackArray stack(10);
	stack.push(1);
	stack.push(2);
	stack.push(3);

	stackArray* copyTo = stack.copyStackContent();

	cout << copyTo->getTop();
	cout << endl << copyTo->pop();
	cout << endl << copyTo->getTop() << endl;

	system("pause");
    return 0;
}

