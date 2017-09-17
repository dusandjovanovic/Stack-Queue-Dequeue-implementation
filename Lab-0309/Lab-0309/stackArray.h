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

	void reverseStack() {
		stackArray* tmp = new stackArray(size);

		while (!isEmpty()) {
			double data = pop();
			tmp->push(data);
		}

		delete[] this->array;
		array = tmp->array;
		top = tmp->top;

		/*
		for(int i = 0; i <= top; i++){
			double data = array[i];
			tmp->push(data);
		}

		top = -1;
		while(!tmp->isEmpty()){
			double data = tmp->pop();
			push(data);
		}
		*/
	}

	void reverseQueue() {
		queueArray* tmp = new queueArray(size);

		while (!isEmpty()) {
			double data = pop();
			tmp->enqueue(data);
		}

		while (!tmp->isEmpty()) {
			double data = tmp->dequeue();
			push(data);
		}

		delete tmp;
	}
};