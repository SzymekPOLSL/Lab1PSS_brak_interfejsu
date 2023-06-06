#pragma once

/**
* @file Kompozyt.hpp
* Plik kompozytu zawiera w sobie metody wykorzystywane przez komponenty.
* Jest jednym z elementów szablonu projektowego Kompozyt.
*/

class Komponent_Struktura {

	protected:
		/// WskaŸnik na klasê Komponent_Struktura wskazuj¹ca na "rodziców", czyli najstarsze elementy drzewa.
		Komponent_Struktura* parent;

	public:
		/// Wirtualny destruktor
		virtual ~Komponent_Struktura() {}

		/// Ustawienie danego "rodzica"
		void SetParent(Komponent_Struktura* nparent) {
			this->parent = nparent;
		}

		/// Odebranie danego rodzica
		Komponent_Struktura* GetParent() const {
			return this->parent;
		}

		/// Operacja dodawania kolejnych "dzieci" do drzewa. W tym wypadku s¹ to obiekty SISO.
		virtual void dodaj(Komponent_Struktura* komponent) {}
		/// Operacja usuniêcia kolejnych "dzieci" do drzewa. W tym wypadku s¹ to obiekty SISO.
		virtual void usun(Komponent_Struktura* komponent) {}

		/**
		* Metoda czysto wirtualna, symuluje zwraca próbkê wyjœcia po dostarczeniu próbki wejœcia.
		* @param[in] s_u
		* @param[out] y
		*/
		virtual double Symuluj(double s_u) = 0;
};