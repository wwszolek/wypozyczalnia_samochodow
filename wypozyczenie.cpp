#include "wypozyczenie.h"

#include "platnosc.h"

wypozyczenie::wypozyczenie() : _auto(NULL){}

wypozyczenie::wypozyczenie(Auto* _auto) : _auto(_auto){}

void wypozyczenie::rozpocznij() {
	std::cout << "Rozpoczynam wypozyczenie" << std::endl;
	data_rozpoczecia = time(NULL);
}

void wypozyczenie::zakoncz() {
	std::cout << "Koncze wypozyczenie" << std::endl;
	data_zakonczenia = time(NULL);
}

int wypozyczenie::oblicz_kwote(int liczba_dni) {
	return liczba_dni * 10000;
}

std::string wypozyczenie::show() {
	std::cout<< klient->show() + "\n" + _auto->show();

	return "aaa";
}

Auto* wypozyczenie::getAuto() {
	return _auto;
}