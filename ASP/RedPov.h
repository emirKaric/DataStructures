#pragma once
#include "Red.h"
#include "Cvor.h"
#include <exception>

template <class T>
class RedPov : public Red<T> {
	Cvor<T>* front;
	Cvor<T>* back;
public:
	RedPov() {
		front = nullptr;
		back = nullptr;
	}
	
	void addElement(T& element) {
		Cvor<T>* tempNode = new Cvor<T>(element, nullptr);
		if (!isEmpty()) {
			back->setNext(tempNode);
			back = tempNode;
			return;
		}
		front = tempNode;
		back = tempNode;
	}

	T& removeElement() {
		if (isEmpty())
			throw std::exception("Nema clanova za ukloniti.");
		T tempElement = front->getInfo();
		Cvor<T>* tempNode = front;
		front = front->getNext();
		delete tempNode;
		
		if (isEmpty()) 
			back = nullptr;

		return tempElement;
	}
	bool isEmpty() {
		return front == nullptr;
	}
	int getSize() {
		int size = 0;
		Cvor<T>* tempNode = front;
		while (tempNode != nullptr) {
			tempNode = tempNode->getNext();
			++size;
		}
		return size;
	}
	bool isFull() {
		return false;
	}
	T& operator[](int index) {
		int brojac = 0;
		Cvor<T>* tempNode = front;
		while (tempNode != nullptr) {
			if (brojac == index)
				return tempNode->getInfo();
			tempNode = tempNode->getNext();
			++brojac;
		}
		throw std::exception("Element ne postoji!");
	}
	T& getElement(int index) {
		return operator[](index);
	}
};