#pragma once
#include "Dekorator.hpp"

/**
* @file DekProst.hpp
* Plik odpowiedzialny jest za generowanie sygna�u prostok�tnego.
* 
*/

class DekProst : public Dekorator {

	private:
		///Amplituda sygna�u prostok�tnego
		double s_amplituda;
		///Wype�nienie sygna�u prostok�tnego
		double s_wypelnienie;

	public:
		///Konstruktor parametryczny sygna�u prostok�tnego
		DekProst(Komponent* komponent, double amplituda, double wypelnienie);
		///Destruktor sygna�u prostok�tnego
		~DekProst();
		///Metoda dziedziczona z klasy Komponent
		double gen() override;
};