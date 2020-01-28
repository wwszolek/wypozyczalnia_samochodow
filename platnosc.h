#ifndef PLATNOSC_H
#define PLATNOSC_H

#include <string>
#include "wypozyczenie.h"

class platnosc {
	int kwota;

	wypozyczenie* _wypozyczenie;
public:
	platnosc();
	platnosc(int, wypozyczenie*);

	bool wykonaj();
};

class platnosc_przelewem : public platnosc {
	std::string tytul;
	std::string numer_konta;

public:
	platnosc_przelewem();
	platnosc_przelewem(int, wypozyczenie*, std::string, std::string);

	bool wykonaj();
};

class platnosc_karta :public platnosc {
	std::string numer;

public:
	platnosc_karta();
	platnosc_karta(int, wypozyczenie*, std::string);

	bool wykonaj();
};

#endif