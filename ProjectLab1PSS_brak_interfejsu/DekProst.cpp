#include "DekProst.hpp"
#include <cmath>

/**
* @file DekProst.cpp
* W pliku znajduje siê implementacja konstruktora, destruktora klasy DekProst.
* Oprócz tego mo¿na tutaj znaleŸæ definicjê funkcji gen().
*
*/

//Zdefiniowanie sta³ej PI
#define M_PI 3.14159265358979323846

//Konstruktor parametryczny implementacja
DekProst::DekProst(Komponent* komponent, double amplituda, double wypelnienie) : Dekorator(komponent), s_amplituda(amplituda), s_wypelnienie(wypelnienie) {}
//Destruktor implementacja
DekProst::~DekProst() {}
//Generowanie sygna³u prostok¹tnego na podstawie sygna³u sinus oraz aktualnej próbki i przypisanie dodatniej, b¹dŸ ujemnej wartoœci zadanej amplitudy.
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