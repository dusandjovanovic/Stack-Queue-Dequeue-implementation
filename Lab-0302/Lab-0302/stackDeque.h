#pragma once
#include <iostream>
#include "dequeArray.h"
using namespace std;

class stackArray : public dequeArray {
protected:
	//double* array;
	//long size;
	long top;
public:
	stackArray() : dequeArray() {
	}

	stackArray(long newSize) : dequeArray(newSize) {
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
		if (number != 0)
			double tmp = array[tail];
		double tmp = dequeueTail();
		top = tail;
		return tmp;
	}

	double getTop() {
		if (top == -1)
			throw new std::exception();
		else
			return array[top];
	}
};