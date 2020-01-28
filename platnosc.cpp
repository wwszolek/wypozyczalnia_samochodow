#include "platnosc.h"

#include <iostream>

platnosc::platnosc(): _wypozyczenie(NULL) {}

platnosc::platnosc(int kwota, wypozyczenie* _wypozyczenie) :
	kwota(kwota), _wypozyczenie(_wypozyczenie) {}

bool platnosc::wykonaj() {
	std::cout << "Platnosc poprawnie wykonana na kwote" << kwota << std::endl;
	return true;
}


platnosc_przelewem::platnosc_przelewem() {}

platnosc_przelewem::platnosc_przelewem(int kwota, wypozyczenie* _wypozyczenie, std::string tytul, std::string numer_konta) :
	platnosc(kwota, _wypozyczenie), tytul(tytul), numer_konta(numer_konta) {}

bool platnosc_przelewem::wykonaj() {
	std::cout << "Wykonuje przelew tytulem \"" << tytul << "\" na numer konta " << numer_konta << std::endl;
	return platnosc::wykonaj();
}


platnosc_karta::platnosc_karta() {}

platnosc_karta::platnosc_karta(int kwota, wypozyczenie* _wypozyczenie, std::string numer): 
	platnosc(kwota, _wypozyczenie), numer(numer) {}

bool platnosc_karta::wykonaj() {
	std::cout << "Wykonuje platnosc karta o numerze " << numer << std::endl;
	return platnosc::wykonaj();
}