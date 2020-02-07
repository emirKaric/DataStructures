#pragma once
#include "Stack.h"
#include <exception>

template <class T>
class StackSek : public Stack<T> {
	T* array;
	int maxSize;
	int actualSize;
public:
	StackSek(int maxSize = 10) {
		if (maxSize <= 0)
			maxSize = 10;
		this->maxSize = maxSize;
		actualSize = 0;
		array = new T[maxSize];
	}

	void push(const T& item) {
		if (isFull())
			expandArray();
		array[actualSize] = item;
		++actualSize;
	}
	T& pop() {
		if (actualSize == 0)
			throw std::exception("Nema clanova za uklonit");
		--actualSize;
		return array[actualSize];
	}
	bool isEmpty() {
		return actualSize == 0;
	}
	bool isFull() {
		return actualSize == maxSize;
	}
	T& operator[](int index) {
		if (index < 0 || index >= actualSize)
			throw std::exception("Ne postoji taj elemenat");
		return array[index];
	}
	T& get(int index) {
		return operator[](index);
	}
	int getSize() {
		return actualSize;
	}
private:
	void expandArray() {
		T* tempArray = new T[maxSize * 2];
		for (int i = 0; i < maxSize; i++){
			tempArray[i] = array[i];
		}
		maxSize *= 2;
		delete[] array;
		array = tempArray;
	}
};