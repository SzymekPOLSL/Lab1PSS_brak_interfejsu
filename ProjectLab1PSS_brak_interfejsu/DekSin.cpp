#include "DekSin.hpp"
#include "Dekorator.hpp"
#include <cmath>

/**
* @file DekProst.cpp
* W pliku znajduje si� implementacja konstruktora, destruktora klasy DekSin.
* Opr�cz tego mo�na tutaj znale�� definicj� funkcji gen().
*
*/

//Definicja sta�ej PI
#define M_PI 3.14159265358979323846

//Konstruktor parametryczny implementacja
DekSin::DekSin(Komponent* komponent, double nA, double nf, double nfi) : Dekorator(komponent), s_A(nA), s_f(nf), s_fi(nfi) {}
//Destruktor implementacja
DekSin::~DekSin() {}

//Generowanie sygna�u sinusoidalnego na podstawie zadanych parametr�w (cz�stotliwo��, amplituda, przesuni�cie fazowe) oraz aktualnej pr�bki.
double DekSin::gen() {
	double wartSIN = s_A * sin(2 * M_PI / s_f * s_probka + s_fi);
	s_probka++;
	return  wartSIN + Dekorator::gen();
}