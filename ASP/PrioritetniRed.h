#pragma once

template<class T>
class PrioritentiRed {
public:
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void addElement(T&) = 0;
	virtual T removeElement() = 0;
	virtual int getSize() = 0;
	virtual T& operator[](int) = 0;
	virtual T& getElement(int) = 0;
};