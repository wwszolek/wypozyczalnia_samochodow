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
	baza_danych::wyswietl_liste_wyp();

	std::cout << "Ktore wypozyczenie chcesz zakonczyc?" << std::endl;
	int wyp;
	std::cin >> wyp;

	auto w = baza_danych::get_wyp(wyp);
	w->zakoncz();
	auto a = w->getAuto();
	a->zwroc();

	std::cout << "Dziekujemy za uslugi\n" << std::endl;
}

void panel_administratora() {

}


void dodaj_auto(const std::string& r, const std::string& t, const std::string& k, const std::string& mr, const std::string& md, double moc, int liczba) {
	karta_dostepu kd;
	kd.zaprogramuj(654);
	auto kkk = baza_danych::dodaj(kd);
	baza_danych::dodaj(Auto(r, t, k, mr, md, moc, liczba, kkk));
}

int main() {
	dodaj_auto("KR 72726", "Osobowy", "Czarny", "BWM", "3", 280, 5);
	dodaj_auto("LZ 12312", "Dostawczy", "Bialy", "Ford", "Transit", 120, 3);
	dodaj_auto("WA 72542", "Sportowy", "Czerwony", "Ferrari", "458", 560, 2);


	std::cout << "Witaj w systemie wypozyczalni samochodow" << std::endl;


	int choice = 0;
	while (true) {
		std::cout << "Dokonaj wyboru:\n(1) Wypozycz samochod\n(2) Pozostaw samochod" << std::endl;
		std::cin >> choice;
		
		switch (choice) {
		case 1:
			wypozycz_samochod();
			break;
		case 2:
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