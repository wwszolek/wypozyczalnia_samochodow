#ifndef AUTO_H
#define AUTO_H

#include "karta_dostepu.h"

#include <string>
#include <iostream>

class Auto{
	std::string nr_rejestracyjny;
	std::string typ;
	std::string kolor;
	std::string marka;
	std::string model;
	double moc_silnika;
	int liczba_miejsc;
	bool czy_wypozyczone;

	karta_dostepu* karta;
public:
	Auto();
	Auto(std::string, std::string, std::string, std::string, std::string, double, int, karta_dostepu*);
	bool wypozycz();
	bool zwroc();
	std::string show();
	bool czy_Wypozyczone();
};

#endif