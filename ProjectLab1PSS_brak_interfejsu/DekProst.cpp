#include "DekProst.hpp"
#include <cmath>

/**
* @file DekProst.cpp
* W pliku znajduje si� implementacja konstruktora, destruktora klasy DekProst.
* Opr�cz tego mo�na tutaj znale�� definicj� funkcji gen().
*
*/

//Zdefiniowanie sta�ej PI
#define M_PI 3.14159265358979323846

//Konstruktor parametryczny implementacja
DekProst::DekProst(Komponent* komponent, double amplituda, double wypelnienie) : Dekorator(komponent), s_amplituda(amplituda), s_wypelnienie(wypelnienie) {}
//Destruktor implementacja
DekProst::~DekProst() {}
//Generowanie sygna�u prostok�tnego na podstawie sygna�u sinus oraz aktualnej pr�bki i przypisanie dodatniej, b�d� ujemnej warto�ci zadanej amplitudy.
double DekProst::gen() {
	double wartosc = 0;
	s_probka++;
	if (sin(M_PI / s_wypelnienie * s_probka) >= 0){
		wartosc = s_amplituda;
	}
	else {
		wartosc = -s_amplituda;
	}
	return wartosc + Dekorator::gen();
}