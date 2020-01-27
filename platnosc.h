#ifndef PLATNOSC_H
#define PLATNOSC_H

#include <string>

class platnosc {
	int kwota;

public:
	platnosc();
	platnosc(int);

	bool wykonaj();
};

class platnosc_przelewem : public platnosc {
	std::string tytul;
	int numer_konta;

public:
	platnosc_przelewem();
	platnosc_przelewem(int, std::string, int);

	bool wykonaj();
};

class platnosc_karta :public platnosc {
	int numer;

public:
	platnosc_karta();
	platnosc_karta(int, int);

	bool wykonaj();
};

#endif