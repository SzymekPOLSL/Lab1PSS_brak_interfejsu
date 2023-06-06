#include "KompRow.hpp"

//Destruktor
KompRow::~KompRow() {}

//Symulacja dzia�ania struktury r�wnoleg�ej uk�adu
double KompRow::Symuluj(double s_y) {
	double wynik = 0;
	for (Komponent_Struktura* c : children) {
		if (c != nullptr) {
			wynik += c->Symuluj(s_y);
		}
	}
	return wynik;
}