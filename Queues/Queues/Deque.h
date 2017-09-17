#pragma once
#include <iostream>
using namespace std;

template <typename type>
class Deque {
protected:
	type* array;
	long size;
	long head;
	long tail;
	long numOfElements;
public:
	Deque(long newSize) {
		size = newSize;
		array = new type[size];
		head = tail = -1;
		numOfElements = 0;
	}
	~Deque() {
		delete[] array;
	}

	void enqueueHead(type element) {
		if (numberOfElements == size)
			throw new std::exception("Queue is full.");
		if (numOfElements == 0)
			head = tail = 0;
		else if (head-- == 0) // decrease head by mod N
			head = size - 1;
		array[head] = element;
		++numOfElements;
	}

	type dequeueHead() {
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

	void enqueueTail(type element) {
		if (numberOfElements == size)
			throw new std::exception("Queue is full.");
		if (++tail == size)	// increase tail by mod N
			tail = 0;
		array[tail] = element;
		if (numberOfElements == 0)	// add to empty queue edge case
			head = tail;
		numberOfElments++;
	}

	void dequeueTail() {
		if (numberOfElements == 0)
			throw new std::exception("Queue is empty.");
		type tmp = array[tail];
		if (tail-- == 0) // decrease tail by mod N
			tail = size - 1;
		--numOfElements;
		return tmp;
	}
};
