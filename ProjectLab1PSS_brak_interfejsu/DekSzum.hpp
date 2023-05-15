#pragma once
#include "Dekorator.hpp"
#include <iostream>
#include <random>

/**
* @file DekSzum.hpp
* Plik odpowiedzialny jest za generowanie sygna³u w postaci szumu.
*
*/

class DekSzum : public Dekorator {

	private:
		/// Generator szumu
		std::default_random_engine s_engine;
		/// Wybór rozk³adu - rozk³ad normalny
		std::normal_distribution<double> s_dist;
		double s_std;

	public:
		/// Konstruktor domyœlny
		DekSzum(Komponent* komponent, double odchylenieSTD);
		/// Destruktor klasy DekSzum
		~DekSzum();

		///Metoda gen, dziedziczona z klasy Komponent
		double gen() override;
};
