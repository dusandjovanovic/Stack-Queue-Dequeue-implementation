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

	double postfixNotation(char* equation, int length) {
		int i = 0;
		while (i < length) {
			if (equation[i] > '0' && equation[i] < '9') {
				double x;
				x = equation[i] - '0';
				double multiplicator = 10;
				while (equation[++i] != ' ') {
					x += multiplicator * (equation[i] - '0');
					multiplicator *= 10;
				}
				push(x);
			}
			else if (equation[i] == '+')
				push(pop() + pop());
			else if (equation[i] == '-') {
				double second = pop();
				double first = pop();
				push(first - second);
			}
			else if (equation[i] == '*')
				push(pop() * pop());
			else if (equation[i] == '/') {
				double second = pop();
				double first = pop();
				push(first / second);
			}
			i++;
		}

		return pop();
	}
};