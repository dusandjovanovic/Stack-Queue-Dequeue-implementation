// Lab0308.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackArray.h"

int main()
{
	stackArray stack(20);

	cout << stack.postfixNotation("5 6 + 7 * 11 /", 14) << endl;

	system("pause");
    return 0;
}

