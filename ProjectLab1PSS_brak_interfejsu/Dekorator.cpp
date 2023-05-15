#include "Dekorator.hpp"

/**
* @file Dekorator.cpp
* W pliku znajduje się implementacja konstruktora, destrukotra klasy Dekorator.
* Oprócz tego można tutaj znaleźć definicję funkcji gen().
*
*/

//Konstruktor parametryczny klasy Dekorator
Dekorator::Dekorator(Komponent* komponent) : s_k(komponent), s_probka(0) {}

//Destruktor parametryczny klasy Dekorator
Dekorator::~Dekorator() {}

//Implementacja funkcji gen(), w której następuje wywołanie funkcji gen() danego dekoratora.
double Dekorator::gen() {
	if (s_k!=nullptr) {
		return s_k->gen();
	}
	return 0.0;
}