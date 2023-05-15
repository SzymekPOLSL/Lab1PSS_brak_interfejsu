#include "DekSin.hpp"
#include "Dekorator.hpp"
#include <cmath>

/**
* @file DekProst.cpp
* W pliku znajduje się implementacja konstruktora, destruktora klasy DekSin.
* Oprócz tego można tutaj znaleźć definicję funkcji gen().
*
*/

//Definicja stałej PI
#define M_PI 3.14159265358979323846

//Konstruktor parametryczny implementacja
DekSin::DekSin(Komponent* komponent, double nA, double nf, double nfi) : Dekorator(komponent), s_A(nA), s_f(nf), s_fi(nfi) {}
//Destruktor implementacja
DekSin::~DekSin() {}

//Generowanie sygnału sinusoidalnego na podstawie zadanych parametrów (częstotliwość, amplituda, przesunięcie fazowe) oraz aktualnej próbki.
double DekSin::gen() {
	double wartSIN = s_A * sin(2 * M_PI / s_f * s_probka + s_fi);
	s_probka++;
	return  wartSIN + Dekorator::gen();
}