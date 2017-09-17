#pragma once
#include <iostream>
#include "linkedList.h"
using namespace std;

class dequeueList {
protected:
	LList<double> array;
	Node<double>* head;
	Node<double>* tail;
public:
	dequeueList() {
		head = tail = nullptr;
	}

	~dequeueList() {
	}

	bool isEmpty() {
		return head == nullptr;
	}

	double getHead() {
		if (head == nullptr)
			throw new std::exception();
		else
			return head->info;
	}

	double getTail() {
		if (tail == nullptr)
			throw new std::exception();
		else
			return tail->info;
	}

	void enqueue(double element) {
		array.addToTail(element);
		tail = array.getTail();

		if (array.numberOfElements() == 1)
			head = tail;
	}

	void enqueueHead(double element) {
		array.addToHead(element);
		head = array.getHead();

		if (array.numberOfElements() == 1)
			tail = head;
	}

	double dequeue() {
		if (array.numberOfElements() == 0)
			throw new std::exception();

		double tmp = head->info;
		array.deleteFromHead();
		head = array.getHead();

		if (array.numberOfElements() == 0)
			tail = head;

		return tmp;
	}

	double dequeueTail() {
		if(array.numberOfElements() == 0)
			throw new std::exception();

		double tmp = tail->info;
		array.deleteFromTail();
		tail = array.getTail();

		if (array.numberOfElements() == 0)
			head = tail;

		return tmp;
	}
};