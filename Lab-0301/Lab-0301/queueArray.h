#pragma once
#include <iostream>
using namespace std;

class queueArray {
protected:
	double* array;
	long size;
	long head;
	long tail;
	long number;
public:
	queueArray() {
		array = nullptr;
	}

	queueArray(long newSize) {
		size = newSize;
		array = new double[size];
		head = tail = -1;
		number = 0;
	}

	virtual ~queueArray() {
		delete[] array;
	}

	virtual bool isEmpty() {
		return number == 0;
	}

	virtual double getHead() {
		if (head == -1)
			throw new std::exception();
		else
			return array[head];
	}

	virtual void enqueue(double element) {
		if (number == size)
			return;

		if (++tail == size)
			tail = 0;
		array[tail] = element;

		++number;
		if (number == 1)
			head = tail;
	}

	virtual double dequeue() {
		if (number == size)
			throw new std::exception();

		double tmp = array[head];
		if (++head == size)
			head = 0;

		--number;
		if (number == 0)
			head = tail = -1;

		return tmp;
	}
};