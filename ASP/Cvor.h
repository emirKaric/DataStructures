#pragma once

template <class T>
class Cvor {
	T info;
	Cvor* next;
public:
	Cvor(const T& i, Cvor* n) {
		info = i;
		next = n;
	}
	void setInfo(const T& i) {
		info = i;
	}
	T& getInfo() {
		return info;
	}
	void setNext(Cvor* n) {
		next = n;
	}
	Cvor* getNext() {
		return next;
	}
};