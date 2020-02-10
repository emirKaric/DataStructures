#include <iostream>
#include "Lista.h"
#include "ListaPov.h"
#include "ListaSek.h"
#include "Cvor.h"
#include "Stack.h"
#include "StackPov.h"
#include "StackSek.h"
#include "Red.h"
#include "RedPov.h"
#include "RedSek.h"
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

template<class T>
void testStack(Stack<T>* podaci) {
	int unos;
	do
	{
		int broj;
		cout << "1. Dodaj" << "\n";
		cout << "2. Ukloni" << "\n";
		cout << "3. Print" << "\n";
		cout << "4. Sve ukloni" << "\n";
		cout << "5. Exit" << "\n";
		cout << "Unesite: ";
		cin >> unos;
		int end = podaci->getSize();
		switch (unos)
		{
		case 1:
			cout << "Unesite broj: \n";
			cin >> broj;
			podaci->push(broj);
			break;
		case 2:
			podaci->pop();
			break;
		case 3:
			for (int i = 0; i < end; i++)
				cout << (*podaci)[i] << "|";
			cout << "\n";
			break;
		case 4:
			for (int i = 0; i < end; i++)
				podaci->pop();
			break;
		}
	} while (unos != 5);
}

template<class T>
void testRed(Red<T>* podaci) {
	int unos;
	do
	{
		int broj;
		cout << "1. Dodaj" << "\n";
		cout << "2. Ukloni" << "\n";
		cout << "3. Print" << "\n";
		cout << "4. Sve ukloni" << "\n";
		cout << "5. Exit" << "\n";
		cout << "Unesite: ";
		cin >> unos;
		int end = podaci->getSize();
		switch (unos)
		{
		case 1:
			cout << "Unesite broj: \n";
			cin >> broj;
			podaci->addElement(broj);
			break;
		case 2:
			podaci->removeElement();
			break;
		case 3:
			for (int i = 0; i < end; i++)
				cout << (*podaci)[i] << "|";
			cout << "\n";
			break;
		case 4:
			for (int i = 0; i < end; i++)
				podaci->removeElement();
			break;
		}
	} while (unos != 5);
}

int main()
{	
	//testLista(new ListaSek<int>());
	//testLista(new ListaPov<int>());

	//testStack(new StackSek<int>());
	//testStack(new StackPov<int>());
	//testRed(new RedSek<int>());
	testRed(new RedPov<int>());

	return 0;
}