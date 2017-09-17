#pragma once
#include <iostream>
using namespace std;

class stackArray {
protected:
	char* array;
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
		array = new char[size];
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

	void push(char element) {
		if (top == size - 1)
			return;
		else
			array[++top] = element;
	}

	char pop() {
		if (top == -1)
			throw new std::exception();
		else {
			char result = array[top--];
			return result;
		}

	}

	char getTop() {
		if (top == -1)
			throw new std::exception();
		else
			return array[top];
	}

	void infixToPostfix(char* equation, int length) {
		int i = 0;
		cout << endl;
		while (i < length) {
			if (equation[i] >= 'a' && equation[i] <= 'z')
				cout << equation[i] << " ";
			else {
				if (equation[i] == '(')
					push(equation[i]);
				else if (equation[i] == ')') {
					bool stacked = false;
					while (stacked == false) {
						if (top != -1 && getTop() == '(') {
							pop();
							stacked = true;
							continue;
						}
						cout << pop() << " ";
					}
				}
				else {
					while(top != -1 && (getTop() == '*' || getTop() == '/' || getTop() == '^'))
						cout << pop() << " ";
					push(equation[i]);
				}
			}
			i++;
		}
		while(!isEmpty())
			cout << pop() << " ";
		cout << endl;
	}

	void infixToPrefix(char* reverse, int length) {

		char* equation = new char[length];
		int i = 0, j = length - 1;
		while (i < length) {
			equation[i] = reverse[j];
			if (equation[i] == '(')
				equation[i] = ')';
			else if (equation[i] == ')')
				equation[i] = '(';
			i++;
			j--;
		}

		infixToPostfix(equation, length);

		delete equation;
	}
};