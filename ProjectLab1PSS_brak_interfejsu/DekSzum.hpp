#pragma once
#include "Dekorator.hpp"
#include <iostream>
#include <random>

/**
* @file DekSzum.hpp
* Plik odpowiedzialny jest za generowanie sygnału w postaci szumu.
*
*/

class DekSzum : public Dekorator {

	private:
		/// Generator szumu
		std::default_random_engine s_engine;
		/// Wybór rozkładu - rozkład normalny
		std::normal_distribution<double> s_dist;
		double s_std;

	public:
		/// Konstruktor domyślny
		DekSzum(Komponent* komponent, double odchylenieSTD);
		/// Destruktor klasy DekSzum
		~DekSzum();

		///Metoda gen, dziedziczona z klasy Komponent
		double gen() override;
};
