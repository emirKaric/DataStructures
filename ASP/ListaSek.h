#pragma once
#include "Lista.h"
#include <exception>

template<class T>
class ListaSek: public Lista<T>{
	T* niz;
	int trenutno;
	int max;

	void Alociraj() {
		T* temp = new T[max * 2];
		for (int i = 0; i < trenutno; i++){
			temp[i] = niz[i];
		}
		max *= 2;
		delete[] niz;
		niz = temp;
	}
public:
	ListaSek(int m = 10){
		max = m;
		trenutno = 0;
		niz = new T[max];
	}
	~ListaSek(){
		delete[] niz;
		niz = nullptr;
	}
	void dodaj_na_pocetak(const T& x) {
		if (jel_pun()) {
			Alociraj();
		}
		for (int i = trenutno - 1; i >= 0; i--){
			niz[i + 1] = niz[i];
		}
		niz[0] = x;
		++trenutno;
	}
	void dodaj_na_kraj(const T& x) {
		if (jel_pun()) {
			Alociraj();
		}
		niz[trenutno] = x;
		++trenutno;
	}
	T ukloni_sa_pocetka() {
		if (jel_prazna()) {
			throw std::exception("Nema clanova za ukloniti");
		}

		T temp = niz[0];
		for (int i = 0; i < trenutno - 1; i++){
			niz[i] = niz[i + 1];
		}
		--trenutno;
		return temp;
	}
	T ukloni_sa_kraja() {
		if (jel_prazna()) {
			throw std::exception("Nema clanova za ukloniti");
		}
		--trenutno;
		return niz[trenutno];
	}
	bool jel_prazna() {
		return (trenutno == 0);
	}
	bool jel_pun() {
		return trenutno == max;
	}
	T operator[](int index) {
		if (index >= trenutno || index < 0) {
			throw std::exception("Ne postoji taj index");
		}
		return niz[index];
	}
	T get(int index) {
		if (index >= trenutno || index < 0) {
			throw std::exception("Ne postoji taj index");
		}
		return niz[index];
	}
	int get_brojac() {
		return trenutno;
	}
};