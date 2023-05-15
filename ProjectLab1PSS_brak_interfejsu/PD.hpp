#pragma once
#include "klasaSISO.hpp"
#include <iostream>
#include <deque>

/**
* @file PD.hpp
* Klasa PD dziedziczy metodę Symuluj z klasy bazowej SISO.
* Jej zadaniem jes przeprowadzenie regulacji na podstawie zadanych nastaw części P oraz D. 
* Jest również dziedziczona przez klasę PID.
* 
*/

class PD: virtual public SISO {
	private:
		/// Kolejka, do której zapisywane są błędy (wartość zadana - próbka wyjścia)
		std::deque<double> s_error;
		/// Wzmocnienie część proporcjonalna
		double s_kp; 
		/// Max sterowanie
		double s_Umax;
		/// Min sterowanie
		double s_Umin;
		/// Czas próbkowania
		double s_h;
	protected:
		/// Wzmocnienie część różniczkująca
		double s_kd;
	public:
		/// Konstruktor domyślny klasy PD
		PD();
		/// Dziedziczenie tylko wartości kd (do PID)
		PD(double& nkd);
		/// Konstruktor parametryczny klasy PD
		PD(double& nkp, double& nkd, double& nUmax, double& nUmin, double& nh);
		/// Destruktor klasy PD
		~PD();

		/**
		* Metoda publiczna dziedziczona z klasy SISO
		* Regulacja obiektu za pomocą regulatora PD.
		* @param[in] s_e ///< próbka uchybu
		* @param[out] s_u ///< próbka sterowania
		*
		*/
		double Symuluj(double s_e) override;

		/**
		* Metoda służy do obliczenia części proporcjonalnej regulatora.
		* @param[out] P ///< składowa proporcjonalna
		* 
		*/
		double liczP();

		/**
		* Metoda służy do obliczenia części różniczkującej regulatora.
		* @param[out] D ///< składowa różniczkująca
		* 
		*/
		double liczD();

		/// Wyświetlenie parametrów regulatora PD
		std::ostream& wyswietlParametryPD(std::ostream& os);

		/**
		* Metoda służy do odczytania parametrów obiektu PD z pliku konfiguracyjnego(json)
		* @param[in] obiekt PI
		* @param[in] ścieżka do pliku, z którego odczytywane są parametry
		*
		*/
		void odczytajDane(PD& pd, const std::string& file_path);

		/**
		* Metoda służy do zapisu aktualnych parametrów obiektu PD z pliku konfiguracyjnego(json)
		* @param[in] ścieżka do pliku, do którego zapisywane są parametry
		*
		*/
		void zapiszDane(const std::string& file_path);
};