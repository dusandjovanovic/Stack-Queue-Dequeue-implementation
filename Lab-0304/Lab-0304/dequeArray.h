#pragma once
#include <iostream>
using namespace std;

class dequeArray {
protected:
	double* array;
	long size;
	long head;
	long tail;
	long number;
public:
	dequeArray() {
		array = nullptr;
	}

	dequeArray(long newSize) {
		size = newSize;
		array = new double[size];
		head = tail = -1;
		number = 0;
	}

	~dequeArray() {
		delete[] array;
	}

	bool isEmpty() {
		return number == 0;
	}

	double getHead() {
		if (head == -1)
			throw new std::exception();
		else
			return array[head];
	}

	double getTail() {
		if (tail == -1)
			throw new std::exception();
		else
			return array[head];
	}

	void enqueue(double element) {
		if (number == size)
			return;

		if (++tail == size)
			tail = 0;
		array[tail] = element;

		++number;
		if (number == 1)
			head = tail;
	}

	void enqueueHead(double element) {
		if (number == size)
			return;

		if (--head == -1)
			head = size - 1;
		array[head] = element;

		++number;
		if (number == 1)
			tail = head;
	}

	double dequeue() {
		if (number == 0)
			throw new std::exception();

		double tmp = array[head];
		if (++head == size)
			head = 0;

		--number;
		if (number == 0)
			head = tail = -1;

		return tmp;
	}

	double dequeueTail() {
		if (number == 0)
			return;

		double tmp = array[tail];
		if (--tail == 0)
			tail = size - 1;

		--number;
		if (number == 0)
			head = tail = -1;

		return tmp;
	}
};