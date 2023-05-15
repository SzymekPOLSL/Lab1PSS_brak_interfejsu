#pragma once
#include "Komponent.hpp"
#include <iostream>

/**
* @file KomponentKonkretny.hpp
* W pliku znajduje się podstawowy komponent, będący sygnałem w postaci wartości stałej.
* 
*/

class KomponentKonkretny : public Komponent {

	private:
		///Określenie jaką wartość stałą ma mieć sygnał
		double s_stala;

	public:
		///Konstruktor parametryczny klasy KomponentKonkretny
		KomponentKonkretny(double nstala): s_stala(nstala) {};
		///Destruktor klasy KomponentKonkretny
		~KomponentKonkretny() {};

		/// Metoda generuj dziedziczona od klasy Komponent, w której następuje zwrócenie wartości stałej.
		double gen() override{
			return s_stala;
		};
};
