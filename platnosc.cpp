#include "platnosc.h"

#include <iostream>

platnosc::platnosc() {}

platnosc::platnosc(int kwota) : kwota(kwota) {}

bool platnosc::wykonaj() {
	std::cout << "Platnosc poprawnie wykonana na kwote" << kwota << std::endl;
	return true;
}


platnosc_przelewem::platnosc_przelewem() {}

platnosc_przelewem::platnosc_przelewem(int kwota, std::string tytul, int numer_konta) :
	platnosc(kwota), tytul(tytul), numer_konta(numer_konta) {}

bool platnosc_przelewem::wykonaj() {
	std::cout << "Wykonuje przelew tytulem \"" << tytul << "\" na numer konta " << numer_konta << std::endl;
	return platnosc::wykonaj();
}


platnosc_karta::platnosc_karta() {}

platnosc_karta::platnosc_karta(int kwota, int numer): platnosc(kwota), numer(numer) {}

bool platnosc_karta::wykonaj() {
	std::cout << "Wykonuje platnosc karta o numerze " << numer << std::endl;
	return platnosc::wykonaj();
}