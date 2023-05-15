#pragma once
#include "PI.hpp"
#include "PD.hpp"
#include <iostream>

/**
* @file PID.hpp
* Klasa PD dziedziczy metodę Symuluj z klasy bazowej SISO, jak również odpowiednie pola z klas PI oraz PID.
* Jej zadaniem jes przeprowadzenie regulacji na podstawie zadanych nastaw części P, I oraz D.
*
*/

class PID : public PI, PD {
	public:
		/* 
		* Konstruktor parametryczny klasy PID.
		* Poszczególne pola dziedziczone są z klas PI oraz PD.
		* 
		*/
		PID(double nkp, double nki, double nsumaI, double nUmax, double nUmin, double nh, double nkd);
		/// Destruktor klasy PID
		~PID();

		/**
		* Metoda publiczna dziedziczona z klasy SISO
		* Regulacja obiektu za pomocą regulatora PID.
		* @param[in] s_y ///< próbka uchybu
		* @param[out] s_u ///< próbka sterowania
		*
		*/
		double Symuluj(double s_e) override;
		
		/// Wyświetlenie parametrów regulatora PID
		std::ostream& wyswietlParametryPID(std::ostream& os);

		/**
		* Metoda służy do odczytania parametrów obiektu PID z pliku konfiguracyjnego(json)
		* @param[in] obiekt PI
		* @param[in] ścieżka do pliku, z którego odczytywane są parametry
		*
		*/
		void odczytajDane(PID& pid, const std::string& file_path);

		/**
		* Metoda służy do zapisu aktualnych parametrów obiektu PID z pliku konfiguracyjnego(json)
		* @param[in] ścieżka do pliku, do którego zapisywane są parametry
		*
		*/
		void zapiszDane(const std::string& file_path);
};
