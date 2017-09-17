#pragma once
#include <iostream>
#include "queueArray.h"
using namespace std;

class stackArray : public queueArray {
protected:
	//double* array;
	//long size;
	long top;
public:
	stackArray() : queueArray() {
	}

	stackArray(long newSize) : queueArray(newSize) {
	}

	~stackArray() {
		top = tail = -1;
	}

	bool isEmpty() {
		return tail == -1;
	}

	long numberOfElements() {
		return number;
	}

	void push(double element) {
		enqueue(element);
		top = tail;
	}

	double pop() {
		if (number == 0)
			throw new std::exception();
		double tmp = array[tail];

		--tail;
		--top;
		--number;
		return tmp;
	}

	double getTop() {
		if (top == -1)
			throw new std::exception();
		else
			return array[top];
	}
};