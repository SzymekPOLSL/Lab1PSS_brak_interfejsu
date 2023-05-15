#pragma once
/**
* @file Komponent.hpp
* Klasa Komponent stanowi klasę bazową w postaci interfejsu dla klas pochodnych.
* W jej skład wchodzi funkcja generuj, której zadaniem będzie generowanie sygnału zadanego.
* 
*/

class Komponent {

	public:

		/// Destruktor klasy komponent
		virtual ~Komponent() {};

		/// Metoda generuj, dziedziczona przez klasy pochodne
		virtual double gen() = 0;

};