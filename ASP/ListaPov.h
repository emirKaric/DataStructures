#pragma once
#include "Lista.h"
#include "Cvor.h"
#include <exception>

template <class T>
class ListaPov: public Lista<T> {
	Cvor<T>* prvi;
public:
	ListaPov() {
		prvi = nullptr;
	}
	void dodaj_na_pocetak(const T& x) {
		Cvor<T>* temp = new Cvor<T>(x, prvi);
		prvi = temp;
	}
	void dodaj_na_kraj(const T& x) {
		if (jel_prazna()) {
			dodaj_na_pocetak(info);		
			return;
		}
		Cvor<T>* temp = prvi;
		while (temp->getNext() != nullptr){
			temp = temp->getNext();
		}
		temp->setNext(new Cvor<T>(x, nullptr));
	}
	T ukloni_sa_pocetka() {
		if (jel_prazna()) {
			throw std::exception("Lista prazna");
		}
		Cvor<T>* temp = prvi;
		prvi = prvi->getNext();
		T info = temp->getInfo();
		delete temp;
		return info;
	}
	T ukloni_sa_kraja() {
		Cvor<T>* trenutni = prvi;
		Cvor<T>* prethodni = nullptr;
		T info;
		if (jel_prazna()) {
			throw std::exception("Lista prazna");
		}
		while (trenutni->getNext() != nullptr) {
			prethodni = trenutni;
			trenutni = trenutni->getNext();
		}
		if (prethodni == nullptr) {
			info = prvi->getInfo();
			delete prvi;
			prvi = nullptr;
		}
		else {
			Cvor<T>* temp = prethodni->getNext();
			info = temp->getInfo();
			prethodni->setNext(nullptr);
			delete temp;
		}
		return info;
	}
	bool jel_pun() {
		return false;
	}
	bool jel_prazna() {
		return prvi == nullptr;
	}
	T operator[](int index) {
		int brojac = 0;
		Cvor<T>* temp = prvi;
		if (jel_prazna()){
			throw std::exception("Lista prazna");
		}
		do{
			if (brojac == index)
				return temp->getInfo();
			temp = temp->getNext();
			brojac++;
		} while (temp != nullptr);
		throw std::exception("Ne postoji taj element");
	}
	T get(int index) {
		return operator[](index);
	}
	int get_brojac() {
		int brojac = 0;
		Cvor<T>* temp = prvi;
		while(temp != nullptr){
			temp = temp->getNext();
			brojac++;
		}
		return brojac;
	}
};