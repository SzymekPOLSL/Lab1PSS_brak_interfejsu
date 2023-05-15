#include "PI.hpp"
#include <iostream>
#include <fstream>
#include <deque>
#include "json.hpp"

//Konstruktor domyślny
PI::PI(): s_kp_PI(0.1), s_ki_PI(0.1), s_sumaI_PI(0.0), s_Umax_PI(100.0), s_Umin_PI(0), s_h_PI(1.0) {
	this->s_error_PI.push_front(0.0);
}

//Konstruktor parametryczny
PI::PI(double& nkp, double& nki, double& nsumaI, double& nUmax, double& nUmin, double& nh) : s_kp_PI(nkp), s_ki_PI(nki), s_sumaI_PI(nsumaI), s_Umax_PI(nUmax), s_Umin_PI(nUmin), s_h_PI(nh) {
	this->s_error_PI.push_front(0.0);
}

//Destruktor
PI::~PI() {}

//Wyświetlenie poszczególnych parametrów regulatora PI
std::ostream& PI::wyswietlParametryPI(std::ostream& os) {
	os << "Oto aktualnie wybrane parametry obiektu PI: \n";
	os << "Wzmocnienie członu proporcjonalnego: " << this->s_kp_PI << std::endl;
	os << "Wzmocnienie członu całkującego: " << this->s_ki_PI << std::endl;
	os << "Maksymalne sterowanie: " << this->s_Umax_PI << std::endl;
	os << "Minimalne sterowanie: " << this->s_Umin_PI << std::endl;
	os << "Czas próbkowania: " << this->s_h_PI << std::endl;
	return os;
}

//Obliczenie części proporcjonalnej.
double PI::liczP() {
	return this->s_kp_PI * this->s_error_PI.at(0);
}

//Obliczenie części różniczukjącej.
double PI::liczI() {
	return this->s_ki_PI * this->s_sumaI_PI * this->s_h_PI;
}

// Proces regulacji regulatorem PI
double PI::Symuluj(double s_e) {
	double u = 0.0;
	//Aktualizacja wartości błędu
	this->s_error_PI.push_front(s_e);
	this->s_error_PI.pop_back();
	//Obliczenie sumy błędu potrzebnej w części całkującej
	this->s_sumaI_PI += this->s_error_PI.at(0);
	//Obliczenie części proporcjonalnej oraz całkującej
	double P = liczP();
	double I = liczI();
	u = P + I;
	//Anti-wnidup
	if (u > this->s_Umax_PI) {
		this->s_sumaI_PI = (u - P) / (this->s_ki_PI * this->s_h_PI);
		u = s_Umax_PI;
	}
	else if (u < this->s_Umin_PI) {
		this->s_sumaI_PI = (u - P) / (this->s_ki_PI * this->s_h_PI);
		u = s_Umin_PI;
	}

	return u;
}

/*
* Odczyt danych z wcześniej przygotowanego pliku znajdującego się w podanej ścieżce.
* Podczas odczytu istotne jest nazewnictwo zmiennych podanych w pliku.
* Metoda aktualizuje odpowiednie pola obiektu PI.
*
*/
void PI::odczytajDane(PI& pi, const std::string& file_path) {

	// Odczyt danych z pliku JSON
	std::ifstream input(file_path);
	auto j = nlohmann::json::parse(input);

	// Zapis danych do odpowiednich pól obiektu
	pi.s_kp_PI = j["kp"];
	pi.s_ki_PI = j["ki"];
	pi.s_h_PI = j["h"];
	pi.s_Umax_PI = j["Umax"];
	pi.s_Umin_PI = j["Umin"];
}

/*
* Zapis danych z obiektu PI do pliku o podanej ścieżce.
* Podczas zapisu do pliku wybierane jest nazewnictwo zmiennych.
* Metoda aktualizuje dane parametru.
*
*/
void PI::zapiszDane(const std::string& file_path) {
	// Tworzenie obiektu JSON
	nlohmann::json data = {
		{"kp", this->s_kp_PI},
		{"ki", this->s_ki_PI},
		{"h", this->s_h_PI},
		{"Umax", this->s_Umax_PI},
		{"Umin", this->s_Umin_PI}
	};

	// Zapisywanie danych do pliku JSON
	std::ofstream file(file_path, std::ios::app);
	file << data;
}