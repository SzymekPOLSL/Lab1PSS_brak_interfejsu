#include "DekSin.hpp"
#include "Dekorator.hpp"
#include <cmath>

/**
* @file DekProst.cpp
* W pliku znajduje siê implementacja konstruktora, destruktora klasy DekSin.
* Oprócz tego mo¿na tutaj znaleŸæ definicjê funkcji gen().
*
*/

//Definicja sta³ej PI
#define M_PI 3.14159265358979323846

//Konstruktor parametryczny implementacja
DekSin::DekSin(Komponent* komponent, double nA, double nf, double nfi) : Dekorator(komponent), s_A(nA), s_f(nf), s_fi(nfi) {}
//Destruktor implementacja
DekSin::~DekSin() {}

//Generowanie sygna³u sinusoidalnego na podstawie zadanych parametrów (czêstotliwoœæ, amplituda, przesuniêcie fazowe) oraz aktualnej próbki.
double DekSin::gen() {
	double wartSIN = s_A * sin(2 * M_PI / s_f * s_probka + s_fi);
	s_probka++;
	return  wartSIN + Dekorator::gen();
}