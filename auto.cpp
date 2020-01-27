#include "auto.h"

#include "karta_dostepu.h"

#include <string>

Auto::Auto() : czy_wypozyczone(false), karta(NULL) {}

Auto::Auto(std::string nr_rejestracyjny, std::string typ, std::string kolor, std::string marka, std::string model, double moc_silnika, int liczba_miejsc, karta_dostepu* karta): 
	nr_rejestracyjny(nr_rejestracyjny), typ(typ), kolor(kolor), marka(marka), moc_silnika(moc_silnika), model(model), liczba_miejsc(liczba_miejsc), czy_wypozyczone(false), karta(karta){}

bool Auto::wypozycz() {
	if(czy_wypozyczone){
		std::cout << "Nie mozna wypozyczyc, auto juz wypozyczone" << std::endl;
		return false;
	}
	else {
		czy_wypozyczone = true;
		std::cout << "Zmieniam status auta na wypozyczone" << std::endl;
		return true;
	}
}

bool Auto::zwroc() {
	if (!czy_wypozyczone) {
		std::cout << "Nie mozna zwrocic, auto nie jest wypozyczone" << std::endl;
		return false;
	}
	else {
		czy_wypozyczone = false;
		std::cout << "Zmieniam status auta na nie wypozyczone" << std::endl;
		return true;
	}
}


std::string Auto::show() {
	return marka + " " + model + "\n" + typ + " " + kolor + "\n" + nr_rejestracyjny + "\nMoc silnika: " + std::to_string(moc_silnika) + "\nLiczba miejsc:" + std::to_string(liczba_miejsc);
}

bool Auto::czy_Wypozyczone() {
	return czy_wypozyczone;
}