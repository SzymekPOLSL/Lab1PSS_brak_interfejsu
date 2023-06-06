#pragma once
#include "Komponent_Struktura.hpp"
#include <iostream>
#include <list>

/**
* @file Kompozyt.hpp
* W pliku znajduje siê implementacja klasy Kompozyt, dziedzicz¹cej z klasy Komponent_Struktura.
* W sk³ad klasy wchodz¹ definicje metod dodaj¹cych i usuwaj¹cych kolejne komponenty oraz funkcja Symuluj.
*
*/

class Kompozyt : public Komponent_Struktura {

	protected:
		/// Lista przechowuje "dzieci", czyli kolejne obiekty SISO.
		std::list <Komponent_Struktura*> children;

	public:
		/// Destruktor
		~Kompozyt() {}

		/// Przypisanie obiektów SISO do odpowiedniego "rodzica", czyli wybranej struktury.
		void dodaj(Komponent_Struktura* nkomponent) override {
			this->children.push_back(nkomponent);
			nkomponent->SetParent(this);
		}

		/// Usuniêcie obiektu SISO z odpowiedniego "rodzica", czyli wybranej struktury.
		void usun(Komponent_Struktura* nkomponent) override {
			children.remove(nkomponent);
			nkomponent->SetParent(nullptr);
		}
};