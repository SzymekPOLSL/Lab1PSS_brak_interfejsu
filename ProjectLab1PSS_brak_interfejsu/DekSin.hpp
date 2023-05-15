#pragma once
#include "Dekorator.hpp"

/**
* @file DekSin.hpp
* Plik odpowiedzialny jest za generowanie sygna�u sinusoidalnego.
*
*/

class DekSin : public Dekorator {

	private:
		///Cz�stotliwo�� sygna�u sinusoidalnego
		double s_f;
		///Amplituda sygna�u sinusoidalnego
		double s_A;
		///Przesuni�cie fazowe sygna�u sinusoidalnego
		double s_fi;

	public:
		///Konstruktor parametryczny klasy DekSin
		DekSin(Komponent* komponent, double nA, double nf, double nfi);
		///Destruktor klasy DekSin
		~DekSin();
		///Metoda gen, dziedziczona z klasy Komponent
		double gen() override;
};