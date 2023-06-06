#pragma once
#include "Kompozyt.hpp"

/**
* @file KomRow.hpp
* Z³o¿enie uk³adu regulacji w strukturê równoleg³¹.
* 
*/

class KompRow : public Kompozyt {

	public:
		/// Destruktor
		~KompRow();

		/**
		* Wykorzystanie metody Symuluj do stworzenia struktury równoleg³ej.
		* Wynikiem jest suma kolejnych wyjœæ obiektów SISO.
		*/
		double Symuluj(double s_y) override;

};
