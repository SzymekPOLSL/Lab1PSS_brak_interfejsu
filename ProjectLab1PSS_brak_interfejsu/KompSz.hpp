#pragma once
#include "Kompozyt.hpp"

/**
* @file KompSz.hpp 
* Z�o�enie uk�adu regulacji w struktur� szeregow�.
*
*/

class KompSz : public Kompozyt {

	public:
		/// Destruktor
		~KompSz() {}

		/**
		* Wykorzystanie metody Symuluj do stworzenia struktury szeregowej.
		* Na pierwszy obiekt SISO podawana jest warto�� zadana, za� na kolejne wyj�cia kolejnych obiekt�w.
		*/
		double Symuluj(double s_y) override {
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
};