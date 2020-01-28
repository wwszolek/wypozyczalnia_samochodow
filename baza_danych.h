#ifndef BAZA_DANYCH_H
#define BAZA_DANYCH_H

#include "auto.h"
#include "karta_dostepu.h"
#include "wypozyczenie.h"
#include "platnosc.h"

#include <list>

class baza_danych {
	static std::list<Auto*> auta;
	static std::list<karta_dostepu*> karty;
	static std::list<wypozyczenie*> wypozyczenia;
	static std::list<platnosc_przelewem*> przelewy;
	static std::list<platnosc_karta*> platnosci_karta;

	baza_danych() = delete;
public:
	static Auto* dodaj(Auto);
	static karta_dostepu* dodaj(karta_dostepu);
	static wypozyczenie* dodaj(wypozyczenie);
	static platnosc_przelewem* dodaj(platnosc_przelewem);
	static platnosc_karta* dodaj(platnosc_karta);


	static void usun(Auto*);
	static void usun(karta_dostepu*);
	static void usun(wypozyczenie*);
	static void usun(platnosc_przelewem*);
	static void usun(platnosc_karta*);

	static void wyswietl_liste_aut();
	static Auto* get_auto(int);
};

#endif