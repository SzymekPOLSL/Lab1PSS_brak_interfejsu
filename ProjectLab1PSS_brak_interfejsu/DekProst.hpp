#pragma once
#include "Dekorator.hpp"

/**
* @file DekProst.hpp
* Plik odpowiedzialny jest za generowanie sygnału prostokątnego.
* 
*/

class DekProst : public Dekorator {

	private:
		///Amplituda sygnału prostokątnego
		double s_amplituda;
		///Wypełnienie sygnału prostokątnego
		double s_wypelnienie;

	public:
		///Konstruktor parametryczny sygnału prostokątnego
		DekProst(Komponent* komponent, double amplituda, double wypelnienie);
		///Destruktor sygnału prostokątnego
		~DekProst();
		///Metoda dziedziczona z klasy Komponent
		double gen() override;
};