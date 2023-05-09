#pragma once
#include "klasaSISO.hpp"
#include <iostream>
#include <deque>

/**
* @file PI.hpp
* Klasa Pi dziedziczy metodę Symuluj z klasy bazowej SISO.
* Jej zadaniem jesT przeprowadzenie regulacji na podstawie zadanych nastaw części P oraz I.
* Jest również dziedziczona przez klasę PID.
*
*/

class PI: virtual public SISO{
	protected:
		/// Wzmocnienie części proporcjonalnej
		double s_kp_PI;
		/// Wzmocnienie części całkującej
		double s_ki_PI;
		/// Wartość zadana
		double s_w_PI;
		/// Max sterowanie
		double s_Umax_PI;
		/// Min sterowanie
		double s_Umin_PI;
		/// Kolejka, do której zapisywane są błędy (wartość zadana - próbka wyjścia)
		std::deque<double> s_error_PI;
		/// Suma błędów do obliczenia części całkującej
		double s_sumaI_PI;
		/// Czas próbkowania
		double s_h_PI;
	public:
		/// Konstruktor domyślny klasy PI
		PI();
		/// Konstruktor parametryczny klasy PI
		PI(double& nkp, double& nki, double& nsumaI, double& nw, double& nUmax, double& nUmin, double& nh);
		/// Destruktor klasy PI
		~PI();

		/**
		* Metoda publiczna dziedziczona z klasy SISO
		* Regulacja obiektu za pomocą regulatora PI.
		* @param[in] s_y ///< próbka wyjścia z obiektu
		* @param[out] s_u ///< próbka sterowania
		*
		*/
		double Symuluj(double s_y) override;

		/// Wyświetlenie parametrów regulatora PI
		std::ostream& wyswietlParametryPI(std::ostream& os);

		/**
		* Metoda służy do odczytania parametrów obiektu PI z pliku konfiguracyjnego(json)
		* @param[in] obiekt PI
		* @param[in] ścieżka do pliku, z którego odczytywane są parametry
		*
		*/
		void odczytajDane(PI& pi, const std::string& file_path);

		/**
		* Metoda służy do zapisu aktualnych parametrów obiektu PI z pliku konfiguracyjnego(json)
		* @param[in] ścieżka do pliku, do którego zapisywane są parametry
		*
		*/
		void zapiszDane(const std::string& file_path);

};