#pragma once
#include "Kompozyt.hpp"

/**
* @file KompSz.hpp 
* Z³o¿enie uk³adu regulacji w strukturê szeregow¹.
*
*/

class KompSz : public Kompozyt {

	public:
		/// Destruktor
		~KompSz() {}

		/**
		* Wykorzystanie metody Symuluj do stworzenia struktury szeregowej.
		* Na pierwszy obiekt SISO podawana jest wartoœæ zadana, zaœ na kolejne wyjœcia kolejnych obiektów.
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