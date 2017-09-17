#pragma once
#include <iostream>
using namespace std;

class stackArray {
protected:
	double* array;
	int* stacks;
	long size;
	long topFirst;
	long topSecond;
public:
	stackArray() {
		array = nullptr;
		stacks = nullptr;
		size = 0;
		topFirst = topSecond = -1;
	}

	stackArray(long newSize) {
		size = newSize;
		array = new double[size];
		topFirst = topSecond = -1;

		stacks = new int[size];
		for (int i = 0; i < size; i++)
			stacks[i] = 0;		// 0 means free space, each stack can take it 1: first 2: second
	}

	~stackArray() {
		delete[] array;
	}

	bool isEmptyFirst() {
		return topFirst == -1;
	}

	bool isEmptySecond() {
		return topSecond == -1;
	}

	long numberOfElements() {
		if (topFirst > topSecond)
			return topFirst + 1;
		else
			return topSecond + 1;
	}

	void pushFirst(double element) {
		if (topFirst == size - 1 || topSecond == size - 1)
			return;

		while (stacks[++topFirst] != 0);
		array[topFirst] = element;
		stacks[topFirst] = 1;
	}

	void pushSecond(double element) {
		if (topFirst == size - 1 || topSecond == size - 1)
			return;

		while (stacks[++topSecond] != 0);
		array[topSecond] = element;
		stacks[topSecond] = 2;
	}

	double popFirst() {
		if (topFirst == -1)
			throw new std::exception();

		double tmp = array[topFirst];
		stacks[topFirst] = 0;
		while (stacks[--topFirst] != 1 && topFirst >= 0);
		return tmp;
	}

	double popSecond() {
		if (topSecond == -1)
			throw new std::exception();

		double tmp = array[topSecond];
		stacks[topSecond] = 0;
		while (stacks[--topSecond] != 2 && topSecond >= 0);
		return tmp;
	}

	double getTopFirst() {
		if (topFirst == -1)
			throw new std::exception();
		else
			return array[topFirst];
	}

	double getTopSecond() {
		if (topSecond == -1)
			throw new std::exception();
		else
			return array[topSecond];
	}
};