// Lab0311.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackArray.h"

int main()
{
	stackArray stack(20);

	stack.infixToPostfix("((a+b)*c/d+e^f)/g", 17);
	stack.infixToPrefix("((a+b)*c/d+e^f)/g", 17);

	cout << endl;
	system("pause");
    return 0;
}

