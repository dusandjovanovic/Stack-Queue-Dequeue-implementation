#pragma once

#include "linkedList.h"

#pragma once
#include <iostream>
using namespace std;

class stackList {
protected:
	LList<double> array;
	Node<double>* top;
public:
	stackList() {
		top = nullptr;
	}

	~stackList() {
	}

	bool isEmpty() {
		return top == nullptr;
	}

	long numberOfElements() {
		return array.numberOfElements();
	}

	void push(double element) {
		array.addToTail(element);
		top = array.getTail();
	}

	double pop() {
		if (array.getHead() == nullptr)
			throw new std::exception();
		double popped = array.getTail()->nodeValue();
		array.deleteFromTail();
		top = array.getTail();
		return popped;
	}

	double getTop() {
		if (array.getHead() == nullptr)
			throw new std::exception();
		else
			return array.getTail()->nodeValue();
	}
};