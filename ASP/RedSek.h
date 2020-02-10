#pragma once
#include "Red.h"
#include <exception>



/*
	Jedno od poboljsanja implementacije je dodavanje funkcije za uvecavanje niza
*/

 // Ovo je cirkularni red ima i drugih implementacija 
template<class T>
class RedSek : public Red<T> {
	T* array;
	int maxSize;
	int actualSize;
	int front;
	int end;
public:
	RedSek(int maxSize = 100) {
		if (maxSize <= 0)
			maxSize = 10;
		this->maxSize = maxSize;
		actualSize = 0;
		front = 0;
		end = 0;
		array = new T[maxSize];
	}
	void addElement(T& element) {
		if (isFull())
			throw std::exception("Niz je pun");
		array[end] = element;
		++end;
		++actualSize;
		if (end == maxSize)
			end = 0;
	}
	T& removeElement() {
		if (isEmpty())
			throw std::exception("Nema clanova za ukloniti.");
		T tempElement = array[front];
		++front;
		--actualSize;
		if (front == maxSize)
			front = 0;
		return tempElement;
	}
	bool isEmpty() {
		return actualSize == 0;
	}
	int getSize() {
		return actualSize;
	}
	bool isFull() {
		return actualSize == maxSize;
	}
	T& operator[](int index) {
		int tempIndex = (front + index) % maxSize;
		if (tempIndex >= end)
			throw std::exception("Ne postoji taj broj!!");
		return array[tempIndex];
	}
	T& getElement(int index) {
		return operator[](index);
	}
};