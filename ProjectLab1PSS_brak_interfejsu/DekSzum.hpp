#pragma once
#include "Dekorator.hpp"
#include <iostream>
#include <random>

/**
* @file DekSzum.hpp
* Plik odpowiedzialny jest za generowanie sygna�u w postaci szumu.
*
*/

class DekSzum : public Dekorator {

	private:
		/// Generator szumu
		std::default_random_engine s_engine;
		/// Wyb�r rozk�adu - rozk�ad normalny
		std::normal_distribution<double> s_dist;
		double s_std;

	public:
		/// Konstruktor domy�lny
		DekSzum(Komponent* komponent, double odchylenieSTD);
		/// Destruktor klasy DekSzum
		~DekSzum();

		///Metoda gen, dziedziczona z klasy Komponent
		double gen() override;
};
