#pragma once
#include "Komponent.hpp"

/**
* @file Dekorator.hpp
* Klasa Dekorator stanowi klasę bazową w postaci interfejsu dla klas pochodnych (dekoratorów sygnałów).
* W jej skład wchodzi funkcja generuj, której zadaniem będzie generowanie sygnału zadanego.
*
*/

class Dekorator: public Komponent {

	protected:
		///Wskaźnik na poszczególne komponenty
		Komponent* s_k;
		///Dana próbka czasu
		unsigned int s_probka;

	public:
		/// Konstruktor klasy Destruktor
		Dekorator(Komponent* komponent);
		/// Destruktor klasy Dekorator
		~Dekorator();

		/// Metoda generuj dziedziczona od klasy Komponent
		double gen() override;

};
