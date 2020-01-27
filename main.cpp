#include <iostream>

void wypozycz_samochod() {
	
}

void zglos_usterke() {

}

void pozostaw_samochod() {

}

void panel_administratora() {

}

int main() {
	std::cout << "Witaj w systemie wypozyczalni samochodow" << std::endl;

	int choice = 0;
	while (true) {
		std::cout << "Dokonaj wyboru:\n(1) Wypozycz samochod\n(2) Zglos usterke\n(3)Pozostaw samochod" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			void wypozycz_samochod();
			break;
		case 2:
			void zglos_usterke();
			break;
		case 3:
			void pozostaw_samochod();
			break;
		case 17:
			void panel_administratora();
			break;
		default:
			std::cout << "Zla opcja, wybierz ponownie" << std::endl;
			break;
		}
	}

	return 0;
}