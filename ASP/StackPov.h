#pragma once
#include "Cvor.h"
#include "Stack.h"
#include <exception>
using namespace std;


template<class T>
class StackPov : public Stack<T> {
	Cvor<T>* head;
public:
	StackPov() {
		head = nullptr;
	}

	void push(const T& item) {
		Cvor<T>* temp = new Cvor<T>(item, head);
		head = temp;
	}
	T& pop() {
		if (head == nullptr)
			throw std::exception("Nema clanova za uklonit");
		T& tempItem = head->getInfo();
		Cvor<T>* temp = head;
		head = head->getNext();
		delete temp;
		return tempItem;
	}
	bool isEmpty() {
		return head == nullptr;
	}
	bool isFull() {
		return false;
	}
	T& operator[](int index) {
		Cvor<T>* tempHead = head;
		int tracker = 0;
		while (tempHead != nullptr){
			if (tracker == index)
				return tempHead->getInfo();
			tempHead = tempHead->getNext();
			tracker++;
		}
		throw std::exception("Ne postoji taj elemnet");
	}
	T& get(int index) {
		return operator[](index);
	}
	int getSize() {
		Cvor<T>* tempHead = head;
		int size = 0;
		while (tempHead != nullptr){
			size++;
			tempHead = tempHead->getNext();
		}
		return size;
	}
};