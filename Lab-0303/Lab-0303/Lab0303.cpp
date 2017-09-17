// Lab0303.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackList.h"

int main()
{
	stackList list;

	list.push(1);
	list.push(2);
	list.push(3);

	cout << list.pop() << endl;
	cout << list.getTop() << endl;
	cout << list.pop() << endl;
	cout << list.getTop() << endl;

	list.push(11);
	cout << list.getTop() << endl;

	system("pause");
    return 0;
}

