#include <iostream>
#include "Lista.h"
#include "ListaPov.h"
#include "ListaSek.h"
#include "Cvor.h"
using namespace std;

template <class T>
void testLista(Lista<T>* podaci) {
	int unos;
	do{
		int broj;
		cout << "1. Dodaj na pocetak  " << "\n";
		cout << "2. Dodaj na kraj	   " << "\n";
		cout << "3. Ukloni sa pocetka " << "\n";
		cout << "4. Ukloni sa kraja   " << "\n";
		cout << "5. Print			   " << "\n";
		cout << "6. Sve ukloni		   " << "\n";
		cout << "7. Exit			   " << "\n";
		cout << "Unesite: ";
		cin >> unos;
		int end = podaci->get_brojac();
		switch (unos)
		{
			case 1:
				cout << "Unesite broj: \n";
				cin >> broj;
				podaci->dodaj_na_pocetak(broj);
				break;
			case 2:
				cout << "Unesite broj: \n";
				cin >> broj;
				podaci->dodaj_na_kraj(broj);
				break;
			case 3:
				podaci->ukloni_sa_pocetka();
				break;
			case 4:
				podaci->ukloni_sa_kraja();
				break;
			case 5:
				for (int i = 0; i < end; i++)
					cout << (*podaci)[i] << "|";
				cout << "\n";
				break;
			case 6:
				for (int i = 0; i < end; i++)
					podaci->ukloni_sa_pocetka();
				break;
		}
	} while (unos != 7);
}


int main()
{	
	testLista(new ListaSek<int>());
	testLista(new ListaPov<int>());

	return 0;
}