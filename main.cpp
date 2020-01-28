#include <iostream>

#include "baza_danych.h"
#include "auto.h"

void wypozycz_samochod() {
	baza_danych::wyswietl_liste_aut();
	std::cout << "Wybierz samochod" << std::endl;
	int car;
	std::cin >> car;

	auto a = baza_danych::get_auto(car);
	wypozyczenie w(a);

	std::cout << "Na ile dni chcesz wypozyczyc samochod" << std::endl;
	int dni;
	std::cin >> dni;
	std::cout << "Bedzie cie to kosztowac " << w.oblicz_kwote(dni) << std::endl;
	std::cout << "Zgadzasz sie? (y/n)" << std::endl;

	char c;
	std::cin >> c;
	if (c == 'y') {
		std::cout << "Podaj swoje dane: imie, nazwisko, numer dowodu osobistego, oraz mail kontaktowy" << std::endl;
		std::string i, n, d, m;
		std::cin >> i >> n >> d >> m;
		dane_klienta k(m, i, n, d);

		std::cout << "Wybierz rodzaj platnosci, platnosc przelewem - p, karta - k" << std::endl;
		char p;
		std::cin >> p;
		if (p == 'p') {
			std::cout << "Podaj tytul przelewu i numer konta" << std::endl;
			std::string t;
			std::string nr;
			std::cin >> t >> nr;
			auto www = baza_danych::dodaj(w);
			platnosc_przelewem pl(w.oblicz_kwote(dni), www, t, nr);
			auto ppp = baza_danych::dodaj(pl);
			
			std::string s = "Transakcja powiodla siê";
			std::string f = "Transakcja nie powiodla siê";

			if (ppp->wykonaj()) {
				k.wyslij_maila(s);
				w.rozpocznij();
				a->wypozycz();
			}
			else {
				k.wyslij_maila(f);
				baza_danych::usun(ppp);
				baza_danych::usun(www);
			}
		}
		else if (p == 'k') {
			std::cout << "Podaj numer karty" << std::endl;
			std::string nr;
			std::cin >> nr;
			auto www = baza_danych::dodaj(w);
			platnosc_karta pl(w.oblicz_kwote(dni), www, nr);
			auto ppp = baza_danych::dodaj(pl);

			std::string s = "Transakcja powiodla siê";
			std::string f = "Transakcja nie powiodla siê";

			if (ppp->wykonaj()) {
				k.wyslij_maila(s);
				w.rozpocznij();
				a->wypozycz();
			}
			else {
				k.wyslij_maila(f);
				baza_danych::usun(ppp);
				baza_danych::usun(www);
			}
		}
	}
	std::cout << "Dziekujemy za skorzystanie z uslugi\n" << std::endl;

}

void zglos_usterke() {

}

void pozostaw_samochod() {

}

void panel_administratora() {

}


int main() {
	baza_danych::dodaj(Auto());
	baza_danych::dodaj(Auto());


	std::cout << "Witaj w systemie wypozyczalni samochodow" << std::endl;


	int choice = 0;
	while (true) {
		std::cout << "Dokonaj wyboru:\n(1) Wypozycz samochod\n(2) Zglos usterke\n(3) Pozostaw samochod" << std::endl;
		std::cin >> choice;
		
		switch (choice) {
		case 1:
			wypozycz_samochod();
			break;
		case 2:
			zglos_usterke();
			break;
		case 3:
			pozostaw_samochod();
			break;
		case 17:
			panel_administratora();
			break;
		default:
			std::cout << "Zla opcja, wybierz ponownie" << std::endl;
			break;
		}
	}

	return 0;
}