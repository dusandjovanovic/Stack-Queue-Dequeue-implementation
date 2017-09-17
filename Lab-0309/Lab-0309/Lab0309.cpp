// Lab0309.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackArray.h"

int main()
{
	stackArray stack(10);
	stack.push(11);
	stack.push(33);
	stack.push(1);
	stack.push(2);
	stack.push(3);

	//stack.reverseStack();
	stack.reverseQueue();

	cout << stack.getTop() << endl;
	cout << stack.pop() << endl;
	cout << stack.getTop() << endl;
	
	system("pause");
    return 0;
}

