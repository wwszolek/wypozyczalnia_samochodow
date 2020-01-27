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
	int numer_konta;

public:
	platnosc_przelewem();
	platnosc_przelewem(int, wypozyczenie*, std::string, int);

	bool wykonaj();
};

class platnosc_karta :public platnosc {
	int numer;

public:
	platnosc_karta();
	platnosc_karta(int, wypozyczenie*, int);

	bool wykonaj();
};

#endif