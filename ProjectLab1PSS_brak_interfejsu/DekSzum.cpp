#include "DekSzum.hpp"
#include <iostream>
#include <numeric>

/**
* @file DekSzum.cpp
* W pliku znajduje siê implementacja konstruktora, destruktora klasy DekSzum.
* Oprócz tego mo¿na tutaj znaleŸæ definicjê funkcji gen().
*
*/

//Konstruktor parametryczny implementacja
DekSzum::DekSzum(Komponent* komponent, double odchylenieSTD) : Dekorator(komponent), s_engine(std::random_device{}()), s_dist(0, odchylenieSTD), s_std(odchylenieSTD){}
//Destruktor implementacja
DekSzum::~DekSzum() {}

//Generowanie sygna³u w postaci szumu na podstawie zadanych parametrów (odchylenie standardowe, rozk³ad normalny).
double DekSzum::gen() {
	double wartSZUM = s_dist(s_engine);
	s_probka++;
	return  wartSZUM + Dekorator::gen();
}