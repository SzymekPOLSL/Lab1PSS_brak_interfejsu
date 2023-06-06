#pragma once
#include "Komponent_Struktura.hpp"
#include <iostream>
#include <list>

/**
* @file Kompozyt.hpp
* W pliku znajduje si� implementacja klasy Kompozyt, dziedzicz�cej z klasy Komponent_Struktura.
* W sk�ad klasy wchodz� definicje metod dodaj�cych i usuwaj�cych kolejne komponenty oraz funkcja Symuluj.
*
*/

class Kompozyt : public Komponent_Struktura {

	protected:
		/// Lista przechowuje "dzieci", czyli kolejne obiekty SISO.
		std::list <Komponent_Struktura*> children;

	public:
		/// Destruktor
		~Kompozyt() {}

		/// Przypisanie obiekt�w SISO do odpowiedniego "rodzica", czyli wybranej struktury.
		void dodaj(Komponent_Struktura* nkomponent) override {
			this->children.push_back(nkomponent);
			nkomponent->SetParent(this);
		}

		/// Usuni�cie obiektu SISO z odpowiedniego "rodzica", czyli wybranej struktury.
		void usun(Komponent_Struktura* nkomponent) override {
			children.remove(nkomponent);
			nkomponent->SetParent(nullptr);
		}
};