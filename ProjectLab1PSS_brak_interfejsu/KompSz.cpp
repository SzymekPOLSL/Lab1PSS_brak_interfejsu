#include "KompSz.hpp"

//Destruktor
KompSz::~KompSz() {}

//Symulacja dzia�ania struktury szeregowej uk�adu
double KompSz::Symuluj(double s_y){
	double wynik = 0;
	double wejscie = s_y;
	for (Komponent_Struktura* c : children) {
		if (c != nullptr) {
			wynik = c->Symuluj(wejscie);
			wejscie = wynik;
		}
	}
	return wynik;
}