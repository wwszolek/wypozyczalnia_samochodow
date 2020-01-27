#ifndef DANE_UZYTKOWNIKA_H
#define DANE_UZYTKOWNIKA_H

#include <string>

class dane_uzytkownika {
	std::string mail_kontaktowy;

public:
	dane_uzytkownika();
	dane_uzytkownika(std::string);

	void wyslij_maila(std::string);
};


class dane_administratora : public dane_uzytkownika {
	int kod_dostepu;

public:
	dane_administratora();
	dane_administratora(std::string, int);
};


class dane_klienta : public dane_uzytkownika {
	std::string imie;
	std::string nazwisko;
	std::string numer_dowodu_osobistego;

public:
	dane_klienta();
	dane_klienta(std::string, std::string, std::string, std::string);
};

#endif