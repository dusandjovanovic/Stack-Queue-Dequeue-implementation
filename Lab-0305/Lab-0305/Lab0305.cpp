// Lab0305.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "queueList.h"

int main()
{
	queueList list;

	list.enqueue(1);
	list.enqueue(2);
	list.enqueue(3);

	cout << list.getHead() << " " << list.getTail() << endl;

	list.dequeue();
	cout << list.getHead() << " " << list.getTail() << endl;

	list.dequeue();
	cout << list.getHead() << " " << list.getTail() << endl;

	try {
		list.dequeue();
		cout << list.getHead() << " " << list.getTail() << endl;
	}
	catch (std::exception e) {
		cout << "Empty queue..";
	}

	system("pause");

    return 0;
}

