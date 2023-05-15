#include "PD.hpp"
#include <iostream>
#include <fstream>
#include <deque>
#include "json.hpp"

//Konstruktor domyślny
PD::PD() : s_kp(2.0), s_kd(1.0), s_Umax(10.0), s_Umin(0.0), s_h(1.0){
	this->s_error.resize(2,0);
}

//Konstruktor domyślny z uwzględnieniem wzmocnienia części różniczkującej jako parametru.
PD::PD(double& nkd):s_kp(0.0), s_kd(nkd), s_Umax(10.0), s_Umin(0.0), s_h(1.0) {
	this->s_error.resize(2, 0);
}

//Konstruktor parametryczny
PD::PD(double& nkp, double& nkd, double& nUmax, double& nUmin, double& nh): s_kp(nkp), s_kd(nkd), s_Umax(nUmax), s_Umin(nUmin), s_h(nh) {
	this->s_error.resize(2, 0);
}

//Destruktor
PD::~PD() {}

//Wyświetlenie aktualnie wybranych parametrów regulatora PD
std::ostream& PD::wyswietlParametryPD(std::ostream& os) {
	os << "Oto aktualnie wybrane parametry obiektu PI: \n";
	os << "Wzmocnienie członu proporcjonalnego: " << this->s_kp << std::endl;
	os << "Wzmocnienie członu różniczkującego: " << this->s_kd << std::endl;
	os << "Maksymalne sterowanie: " << this->s_Umax << std::endl;
	os << "Minimalne sterowanie: " << this->s_Umin << std::endl;
	os << "Czas próbkowania: " << this->s_h << std::endl;
	return os;
}

//Obliczenie części proporcjonalnej.
double PD::liczP() {
	return this->s_kp * this->s_error.at(0);
}

//Obliczenie części różniczukjącej.
double PD::liczD() {
	return this->s_kd * (this->s_error.at(0) - this->s_error.at(1)) / this->s_h;
}

// Proces regulacji regulatorem PD
double PD::Symuluj(double s_e){
	double u = 0.0;
	//Aktualizacja wartości błędu
	this->s_error.push_front(s_e);
	this->s_error.pop_back();
	//Obliczenie części proporcjonalnej oraz różniczkującej
	double P = liczP();
	double D = liczD();
	u = P + D;
	//Sprawdzenie, czy sterowanie mieści się w zadanym zakresie.
	if (u > this->s_Umax) {
		u = s_Umax;
	}
	else if (u < this->s_Umin) {
		u = s_Umin;
	}
	return u;
}

/*
* Odczyt danych z wcześniej przygotowanego pliku znajdującego się w podanej ścieżce.
* Podczas odczytu istotne jest nazewnictwo zmiennych podanych w pliku.
* Metoda aktualizuje odpowiednie pola obiektu PI.
*
*/
void PD::odczytajDane(PD& pd, const std::string& file_path) {

	// Odczyt danych z pliku JSON
	std::ifstream input(file_path);
	auto j = nlohmann::json::parse(input);

	// Zapis danych do odpowiednich pól obiektu
	pd.s_kp = j["kp"];
	pd.s_kd = j["kd"];
	pd.s_h = j["h"];
	pd.s_Umax = j["Umax"];
	pd.s_Umin = j["Umin"];
}

/*
* Zapis danych z obiektu PD do pliku o podanej ścieżce.
* Podczas zapisu do pliku wybierane jest nazewnictwo zmiennych.
* Metoda aktualizuje dane parametru.
*
*/
void PD::zapiszDane(const std::string& file_path) {
	// Tworzenie obiektu JSON
	nlohmann::json data = {
		{"kp", this->s_kp},
		{"kd", this->s_kd},
		{"h", this->s_h},
		{"Umax", this->s_Umax},
		{"Umin", this->s_Umin}
	};

	// Zapisywanie danych do pliku JSON
	std::ofstream file(file_path, std::ios::app);
	file << data;
}