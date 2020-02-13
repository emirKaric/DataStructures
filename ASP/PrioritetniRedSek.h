#pragma once
#include "PrioritetniRed.h"
#include <exception>

template<class T>
class PrioritetniRedSek : public PrioritentiRed<T> {
	int maxSize;
	int actualSize;
	T* array;
public:
	PrioritetniRedSek(int maxSize = 100) {
		if (maxSize < 100)
			maxSize = 100;
		array = new T[maxSize];
		actualSize = 0;
		this->maxSize = maxSize;
	}

	bool isFull() {
		return actualSize == maxSize;
	}

	bool isEmpty() {
		return actualSize == 0;
	}

	void addElement(T& element) {
		if (isFull())
			resizeArray();
		array[actualSize] = element;
		++actualSize;
	}

	T removeElement() {
		if (isEmpty())
			throw std::exception("Queue is empty");
		T maxV = array[0];
		int maxI = 0;
		for (int i = 1; i < actualSize; i++){
			if (maxV < array[i]) {
				maxV = array[i];
				maxI = i;
			}
		}

		array[maxI] = array[actualSize - 1];
		--actualSize;
		return maxV;
	}

	int getSize() {
		return actualSize;
	}

	T& operator[](int index) {
		if (index < 0 || index >= actualSize)
			throw std::exception("There is no element at this position");
		return array[index];
	}

	T& getElement(int index) {
		return operator[](index);
	}

private:
	void resizeArray() {
		T* tempArray = new T[maxSize * 2];
		for (int i = 0; i < actualSize; i++){
			tempArray[i] = array[i];
		}
		maxSize *= 2;
		delete array;
		array = tempArray;
	}
};