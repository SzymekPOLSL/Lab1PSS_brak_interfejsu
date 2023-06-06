#pragma once
#include "Kompozyt.hpp"

/**
* @file KomRow.hpp
* Z�o�enie uk�adu regulacji w struktur� r�wnoleg��.
* 
*/

class KompRow : public Kompozyt {

	public:
		/// Destruktor
		~KompRow();

		/**
		* Wykorzystanie metody Symuluj do stworzenia struktury r�wnoleg�ej.
		* Wynikiem jest suma kolejnych wyj�� obiekt�w SISO.
		*/
		double Symuluj(double s_y) override;

};
