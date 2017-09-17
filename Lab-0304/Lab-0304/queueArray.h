#pragma once
#include <iostream>
#include "dequeArray.h"
using namespace std;

class queueArray : dequeArray{
protected:

public:
	queueArray() : dequeArray(){
	}

	queueArray(long newSize) : dequeArray(newSize) {
	}

	virtual ~queueArray() {
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
		dequeArray::enqueue(element);
	}

	virtual double dequeue() {
		return dequeArray::dequeue();
	}
};