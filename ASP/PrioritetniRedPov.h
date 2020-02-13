#pragma once
#include "Cvor.h"
#include "PrioritetniRed.h"
#include <exception>


template <class T>
class PrioritetniRedPov : public PrioritentiRed<T> {
	Cvor<T>* first;
public:
	PrioritetniRedPov() {
		first = nullptr;
	}

	bool isFull() {
		return false;
	}

	bool isEmpty() {
		return first == nullptr;
	}

	void addElement(T& element) {
		Cvor<T>* tempFirst = first;
		Cvor<T>* tempBeforeFirst = nullptr;
		while (tempFirst != nullptr && tempFirst->getInfo() >= element){
			tempBeforeFirst = tempFirst;
			tempFirst = tempFirst->getNext();
		}
		Cvor<T>* newNode = new Cvor<T>(element, tempFirst);
		if (tempBeforeFirst == nullptr)
			first = newNode;
		else
			tempBeforeFirst->setNext(newNode);
	}

	T removeElement() {
		if (isEmpty())
			throw std::exception("Array is empty");
		Cvor<T>* tempFirst = first;
		T info = tempFirst->getInfo();
		first = first->getNext();
		delete tempFirst;
		return info;
	}

	int getSize() {
		Cvor<T>* tempFirst = first;
		int size = 0;
		while (tempFirst != nullptr) {
			tempFirst = tempFirst->getNext();
			++size;
		}
		return size;
	}

	T& operator[](int index) {
		int size = 0;
		Cvor<T>* tempFirst = first;
		while (tempFirst != nullptr){
			if (size == index)
				return tempFirst->getInfo();
			tempFirst = tempFirst->getNext();
			++size;
		}
		throw std::exception("There is no element at this position");
	}

	T& getElement(int index) {
		return operator[](index);
	}
};