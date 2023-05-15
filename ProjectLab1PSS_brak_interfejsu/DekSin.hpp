#pragma once
#include "Dekorator.hpp"

/**
* @file DekSin.hpp
* Plik odpowiedzialny jest za generowanie sygnału sinusoidalnego.
*
*/

class DekSin : public Dekorator {

	private:
		///Częstotliwość sygnału sinusoidalnego
		double s_f;
		///Amplituda sygnału sinusoidalnego
		double s_A;
		///Przesunięcie fazowe sygnału sinusoidalnego
		double s_fi;

	public:
		///Konstruktor parametryczny klasy DekSin
		DekSin(Komponent* komponent, double nA, double nf, double nfi);
		///Destruktor klasy DekSin
		~DekSin();
		///Metoda gen, dziedziczona z klasy Komponent
		double gen() override;
};