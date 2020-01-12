#pragma once

template<class T>
class Lista{
public:
	virtual void dodaj_na_pocetak(const T&) = 0;
	virtual void dodaj_na_kraj(const T&) = 0;
	virtual T ukloni_sa_pocetka() = 0;
	virtual T ukloni_sa_kraja() = 0;
	virtual bool jel_pun() = 0;
	virtual bool jel_prazna() = 0;
	virtual T operator[](int) = 0;
	virtual T get(int) = 0;
	virtual int get_brojac() = 0;
};