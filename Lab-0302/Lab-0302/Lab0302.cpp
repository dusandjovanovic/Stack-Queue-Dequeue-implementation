// Lab0302.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackDeque.h"

int main()
{
	stackArray stack(20);

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	cout << stack.pop() << endl;
	cout << stack.getTop() << endl;
	cout << endl;
	cout << stack.pop() << endl;
	cout << stack.getTop() << endl;


	system("pause");
	return 0;
}

