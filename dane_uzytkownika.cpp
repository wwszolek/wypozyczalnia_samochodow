#include "dane_uzytkownika.h"

#include <string>
#include <iostream>

dane_uzytkownika::dane_uzytkownika() {}

dane_uzytkownika::dane_uzytkownika(std::string mail_kontaktowy) : mail_kontaktowy(mail_kontaktowy) {}

void dane_uzytkownika::wyslij_maila(std::string tresc) {
	std::cout << "Wysylam maila o tresci:\n" << tresc << "\nNa maila: " << mail_kontaktowy << std::endl;
}


dane_administratora::dane_administratora() {}

dane_administratora::dane_administratora(std::string mail, int kod_dostepu) :
	dane_uzytkownika(mail), kod_dostepu(kod_dostepu) {}



dane_klienta::dane_klienta() {}

dane_klienta::dane_klienta(std::string mail, std::string imie, std::string nazwisko, std::string nr_dowodu) :
	dane_uzytkownika(mail), imie(imie), nazwisko(nazwisko), numer_dowodu_osobistego(nr_dowodu) {}

std::string dane_klienta::show() {
	return "Tomasz Kowalski";
}