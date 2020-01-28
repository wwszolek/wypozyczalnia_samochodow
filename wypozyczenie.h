#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include <ctime>

#include "auto.h"
#include "dane_uzytkownika.h"


class wypozyczenie {
	time_t data_rozpoczecia;
	time_t data_zakonczenia;

	Auto* _auto;
	dane_klienta* klient;
public:
	wypozyczenie();
	wypozyczenie(Auto*);

	void rozpocznij();
	void zakoncz();
	int oblicz_kwote(int);

	std::string show();

	Auto* getAuto();
};

#endif