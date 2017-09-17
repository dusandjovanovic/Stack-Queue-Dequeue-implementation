#pragma once
#include <iostream>
using namespace std;

template <typename type>
class Queue {
protected:
	type* array;
	long size;
	long head;
	long tail;
	long numOfElements;
public:
	Queue(long newSize) {
		size = newSize;
		array = new type[size];
		head = tail = -1;
		numOfElements = 0;
	}
	~Queue() {
		delete[] array;
	}

	bool isEmpty() {
		return numOfElements == 0;
	}

	long numberOfElements() {
		return numOfElements;
	}

	type getHead() {
		if (numberOfElements == 0)
			throw new std::exception("Queue is empty.");
		return array[head];
	}

	void enqueue(type element) {
		if (numberOfElements == size)
			throw new std::exception("Queue is full.");
		if (++tail == size)	// increase tail by mod N
			tail = 0;
		array[tail] = element;
		if (numberOfElements == 0)	// add to empty queue edge case
			head = tail;
		numberOfElments++;
	}

	type dequeue() {
		if (numberOfElements == 0)
			throw new std::exception("Queue is empty.");
		type tmp = array[head];
		if (++head == size)	// increase head by mod N
			head = 0;
		numberOfElements--;
		if (numberOfElements == 0)	// remove from one-element queue edge case
			head = tail = -1;
		return tmp;
	}
};