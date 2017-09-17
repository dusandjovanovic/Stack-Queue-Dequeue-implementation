#pragma once
#include <iostream>
using namespace std;

template <typename type>
class Stack {
protected:
	type* array;
	long size;
	long top;
public:
	Stack(long newSize) {
		size = newSize;
		array = new type[size];
		top = -1;
	}
	~Stack() {
		delete[] array;
	}

	bool isEmpty() {
		return top == -1;
	}

	long numberOfElements() {
		return top + 1;
	}

	void push(type element) {
		if (top == size - 1)
			throw new std::exception("Stack is full.");
		array[++top] = element;
	}

	type pop() {
		if (top == -1)
			throw new std::exception("Stack is empty.");
		type tmp = array[top--];
		return tmp;
	}

	type getTop(){
		if (top == -1)
			throw new std::exception("Stack is empty.");
		return array[top];
	}
};