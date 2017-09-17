#pragma once
#include <iostream>
#include "linkedList.h"
using namespace std;

class queueList {
protected:
	LList<double> array;
	Node<double>* head;
	Node<double>* tail;
public:
	queueList() {
	}

	virtual ~queueList() {
	}

	virtual bool isEmpty() {
		return head == nullptr;
	}

	virtual double getHead() {
		if (head == nullptr)
			throw new std::exception();
		else
			return head->info;
	}

	virtual double getTail() {
		if (tail == nullptr)
			throw new std::exception();
		else
			return tail->info;
	}

	virtual void enqueue(double element) {
		array.addToTail(element);
		tail = array.getTail();

		if (array.numberOfElements() == 1)
			head = tail;
	}

	virtual double dequeue() {
		if (array.getHead() == nullptr)
			throw new std::exception();

		double tmp = array.getHead()->info;
		array.deleteFromHead();
		head = array.getHead();
		
		if (array.numberOfElements() == 0)
			tail = nullptr;

		return tmp;
	}
};