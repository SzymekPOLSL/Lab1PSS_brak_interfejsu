#include "PID.hpp"
#include <iostream>
#include <fstream>
#include <deque>
#include "json.hpp"

//Tworzenie obiektu PID, dokonywane jest na podstawie pól klas PD oraz PI.
PID::PID(double nkp, double nki, double nsumaI, double nUmax, double nUmin, double nh, double nkd) : PD(nkd), PI(nkp, nki, nsumaI, nUmax, nUmin, nh)  {
	this->s_error_PI.resize(2, 0);
}

//Destruktor
PID::~PID() {}

//Wyświetlenie parametrów regulatora PID
std::ostream& PID::wyswietlParametryPID(std::ostream& os) {
	os << "Oto aktualnie wybrane parametry obiektu PID: \n";
	os << "Wzmocnienie członu proporcjonalnego: " << this->s_kp_PI << std::endl;
	os << "Wzmocnienie członu całkującego: " << this->s_ki_PI << std::endl;
	os << "Wzmocnienie członu różniczkującego: " << this->s_kd << std::endl;
	os << "Maksymalne sterowanie: " << this->s_Umax_PI << std::endl;
	os << "Minimalne sterowanie: " << this->s_Umin_PI << std::endl;
	os << "Czas próbkowania: " << this->s_h_PI << std::endl;
	return os;
}

// Proces regulacji regulatorem PID
double PID::Symuluj(double s_e) {
	double u = 0.0;
	//Aktualizacja wartości błędu
	this->s_error_PI.push_front(s_e);
	this->s_error_PI.pop_back();
	//Obliczenie sumy błędu potrzebnej w części całkującej
	this->s_sumaI_PI += this->s_error_PI.at(0);
	//Obliczenie części proporcjonalnej, całkującej oraz różniczkującej
	double P = PI::liczP();
	double I = liczI();
	double D = liczD();
	u = P + I + D;
	//Anti-wnidup
	if (u > this->s_Umax_PI) {
		this->s_sumaI_PI = (u - P - D)/(this->s_ki_PI * this->s_h_PI);
		u = s_Umax_PI;
	}
	else if (u < this->s_Umin_PI) {
		this->s_sumaI_PI = (u - P - D)/(this->s_ki_PI * this->s_h_PI);
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
void PID::odczytajDane(PID& pid, const std::string& file_path) {

	// Odczyt danych z pliku JSON
	std::ifstream input(file_path);
	auto j = nlohmann::json::parse(input);

	// Zapis danych do odpowiednich pól obiektu
	pid.s_kp_PI = j["kp"];
	pid.s_ki_PI = j["ki"];
	pid.s_kd = j["kd"];
	pid.s_h_PI = j["h"];
	pid.s_Umax_PI = j["Umax"];
	pid.s_Umin_PI = j["Umin"];
}

/*
* Zapis danych z obiektu PID do pliku o podanej ścieżce.
* Podczas zapisu do pliku wybierane jest nazewnictwo zmiennych.
* Metoda aktualizuje dane parametru.
*
*/
void PID::zapiszDane(const std::string& file_path) {
	// Tworzenie obiektu JSON
	nlohmann::json data = {
		{"kp", this->s_kp_PI},
		{"ki", this->s_ki_PI},
		{"kd", this->s_kd},
		{"h", this->s_h_PI},
		{"Umax", this->s_Umax_PI},
		{"Umin", this->s_Umin_PI}
	};

	// Zapisywanie danych do pliku JSON
	std::ofstream file(file_path, std::ios::app);
	file << data;
}