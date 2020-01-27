#include "baza_danych.h"

#include "auto.h"
#include "karta_dostepu.h"
#include "wypozyczenie.h"
#include "platnosc.h"

std::list<Auto*> baza_danych::auta;
std::list<karta_dostepu*> baza_danych::karty;
std::list<wypozyczenie*> baza_danych::wypozyczenia;
std::list<platnosc_przelewem*> baza_danych::przelewy;
std::list<platnosc_karta*> baza_danych::platnosci_karta;

Auto * baza_danych::dodaj(Auto a) {
	Auto* p = new Auto;
	*p = a;
	auta.push_back(p);

	std::cout << "Dodaje nowe auto" << std::endl;
	return p;
}

void baza_danych::usun(Auto* a) {
	auto it = auta.begin();
	while (it != auta.end()) {
		if (*it == a) {
			auta.erase(it);
			delete a;
			std::cout << "Usuwam auto" << std::endl;

			break;
		}
	}
}

karta_dostepu * baza_danych::dodaj(karta_dostepu k) {
	karta_dostepu* p = new karta_dostepu;
	*p = k;
	karty.push_back(p);

	return p;
}

void baza_danych::usun(karta_dostepu* a) {
	auto it = karty.begin();
	while (it != karty.end()) {
		if (*it == a) {
			karty.erase(it);
			delete a;
			std::cout << "Usuwam karte dostepu" << std::endl;

			break;
		}
	}
}

wypozyczenie * baza_danych::dodaj(wypozyczenie w) {
	wypozyczenie* p = new wypozyczenie;
	*p = w;
	wypozyczenia.push_back(p);

	return p;
}

void baza_danych::usun(wypozyczenie* a) {
	auto it = wypozyczenia.begin();
	while (it != wypozyczenia.end()) {
		if (*it == a) {
			wypozyczenia.erase(it);
			delete a;
			std::cout << "Usuwam wypozyczenie" << std::endl;

			break;
		}
	}
}

platnosc_przelewem * baza_danych::dodaj(platnosc_przelewem prz) {
	platnosc_przelewem* p = new platnosc_przelewem;
	*p = prz;
	przelewy.push_back(p);

	return p;
}

void baza_danych::usun(platnosc_przelewem* a) {
	auto it = przelewy.begin();
	while (it != przelewy.end()) {
		if (*it == a) {
			przelewy.erase(it);
			delete a;
			std::cout << "Usuwam przelew" << std::endl;

			break;
		}
	}
}

platnosc_karta * baza_danych::dodaj(platnosc_karta k) {
	platnosc_karta* p = new platnosc_karta;
	*p = k;
	platnosci_karta.push_back(p);

	return p;
}

void baza_danych::usun(platnosc_karta* a) {
	auto it = platnosci_karta.begin();
	while (it != platnosci_karta.end()) {
		if (*it == a) {
			platnosci_karta.erase(it);
			delete a;
			std::cout << "Usuwam platnosc karta" << std::endl;

			break;
		}
		it++;
	}
}


void baza_danych::wyswietl_liste_aut(){
	auto it = auta.begin();
	while (it != auta.end()) {
		std::cout << (*it)->show() << std::endl;

		it++;
	}
}