#pragma once
#include <iostream>
using namespace std;

class stackArray {
protected:
	double* array;
	long size;
	long top;
public:
	stackArray() {
		array = nullptr;
		size = 0;
		top = -1;
	}

	stackArray(long newSize) {
		size = newSize;
		array = new double[size];
		top = -1;
	}

	~stackArray() {
		delete[] array;
	}

	bool isEmpty() {
		return top == -1;
	}

	long numberOfElements() {
		return top + 1;
	}

	void push(double element) {
		if (top == size - 1)
			return;
		else
			array[++top] = element;
	}

	double pop() {
		if (top == -1)
			throw new std::exception();
		else {
			double result = array[top--];
			return result;
		}

	}

	double getTop() {
		if (top == -1)
			throw new std::exception();
		else
			return array[top];
	}

	stackArray* copyStackContent() {
		stackArray* to = new stackArray(size);
		stackArray tmp(size);

		while (!isEmpty()) {
			double data = pop();
			tmp.push(data);
		}

		while (!tmp.isEmpty()) {
			double data = tmp.pop();
			to->push(data);
		}

		return to;
	}
};