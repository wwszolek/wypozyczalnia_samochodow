#include "karta_dostepu.h"

#include <iostream>

karta_dostepu::karta_dostepu() : kod(-1) {}

void karta_dostepu::zaprogramuj(int x)
{
	kod = x;
	std::cout << "Karta dostepu zaprogramowana kodem " << x << std::endl;
}

bool karta_dostepu::czy_poprawna()
{
	return kod > 0;
}