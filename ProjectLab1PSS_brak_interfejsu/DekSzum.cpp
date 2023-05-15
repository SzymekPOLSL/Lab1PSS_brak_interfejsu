#include "DekSzum.hpp"
#include <iostream>
#include <numeric>

/**
* @file DekSzum.cpp
* W pliku znajduje si� implementacja konstruktora, destruktora klasy DekSzum.
* Opr�cz tego mo�na tutaj znale�� definicj� funkcji gen().
*
*/

//Konstruktor parametryczny implementacja
DekSzum::DekSzum(Komponent* komponent, double odchylenieSTD) : Dekorator(komponent), s_engine(std::random_device{}()), s_dist(0, odchylenieSTD), s_std(odchylenieSTD){}
//Destruktor implementacja
DekSzum::~DekSzum() {}

//Generowanie sygna�u w postaci szumu na podstawie zadanych parametr�w (odchylenie standardowe, rozk�ad normalny).
double DekSzum::gen() {
	double wartSZUM = s_dist(s_engine);
	s_probka++;
	return  wartSZUM + Dekorator::gen();
}