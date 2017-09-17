// Lab0306.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dequeueList.h"

int main()
{
	dequeueList list;

	list.enqueue(1);
	list.enqueue(2);
	list.enqueue(3);

	cout << list.getHead() << " " << list.getTail() << endl;

	list.enqueueHead(11);
	cout << list.getHead() << " " << list.getTail() << endl;

	list.dequeue();
	cout << list.getHead() << " " << list.getTail() << endl;

	list.dequeueTail();
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

