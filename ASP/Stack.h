#pragma once

template<class T>
class Stack {
public:
	virtual void push(const T&) = 0;
	virtual T& pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T& operator[](int) = 0;
	virtual T& get(int) = 0;
	virtual int getSize() = 0;
};