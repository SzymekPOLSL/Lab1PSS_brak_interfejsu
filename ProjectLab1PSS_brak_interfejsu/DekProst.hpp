#pragma once
#include "Dekorator.hpp"

/**
* @file DekProst.hpp
* Plik odpowiedzialny jest za generowanie sygna³u prostok¹tnego.
* 
*/

class DekProst : public Dekorator {

	private:
		///Amplituda sygna³u prostok¹tnego
		double s_amplituda;
		///Wype³nienie sygna³u prostok¹tnego
		double s_wypelnienie;

	public:
		///Konstruktor parametryczny sygna³u prostok¹tnego
		DekProst(Komponent* komponent, double amplituda, double wypelnienie);
		///Destruktor sygna³u prostok¹tnego
		~DekProst();
		///Metoda dziedziczona z klasy Komponent
		double gen() override;
};