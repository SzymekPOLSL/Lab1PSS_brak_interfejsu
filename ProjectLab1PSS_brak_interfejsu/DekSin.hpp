#pragma once
#include "Dekorator.hpp"

/**
* @file DekSin.hpp
* Plik odpowiedzialny jest za generowanie sygna³u sinusoidalnego.
*
*/

class DekSin : public Dekorator {

	private:
		///Czêstotliwoœæ sygna³u sinusoidalnego
		double s_f;
		///Amplituda sygna³u sinusoidalnego
		double s_A;
		///Przesuniêcie fazowe sygna³u sinusoidalnego
		double s_fi;

	public:
		///Konstruktor parametryczny klasy DekSin
		DekSin(Komponent* komponent, double nA, double nf, double nfi);
		///Destruktor klasy DekSin
		~DekSin();
		///Metoda gen, dziedziczona z klasy Komponent
		double gen() override;
};