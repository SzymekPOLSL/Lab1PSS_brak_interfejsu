#include "klasaSISO.hpp"
#include "klasaARX.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <numeric>
#include <random>
#include "json.hpp" 

/**
* @file klasaARX.cpp
* W pliku znajdują się zaimplementowane funkcje i konstruktory klasy ARX, zadeklarowane w pliku nagłówkowym.
* Klasa ARX dziedziczy funkcję Symuluj z klasy SISO, której implementacja znajduje się również w tym pliku.
* Poza tymi metodami w pliku można znaleźć dodatkowo funkcję print, umożliwiającą wyświetlenie elementów wektora.
* 
*/

/// Wykorzystanie przestrzeni nazw "nlohmann::json", używając wyłącznie "json".
using json = nlohmann::json; 

///Wyświetlenie kolejnych elementów wektora
void print(std::vector<double> const &input); // Funkcja umożlwiająca wyświetlenie kolejnych elementów wektora.


ARX::ARX(): s_paramA(1), s_paramB(0), s_k(0), s_varE(0), s_u(0), s_y(0){} // Wpisanie wartości domyślnych do konstruktora

/*
* Przypisanie polom konstruktora wartości za pomocą zmiennych w liście inicjalizacyjnej. 
* Wielkość s_u oraz s_y zależy od liczby podanych współczynników wielomianów A oraz B. 
* 
*/
ARX::ARX(std::vector<double>& nparamA, std::vector<double>& nparamB, unsigned int& nk, double& nvarE): s_paramA(nparamA), s_paramB(nparamB), s_k(nk), s_varE(nvarE), s_u(0), s_y(0) {
    this->s_u.resize((int)s_paramB.size()+s_k, 0);
    this->s_y.resize((int)s_paramA.size(), 0);
}

ARX::~ARX(){}

/*
* Wyświetlenie kolejnych pól stworzonego obiektu z uwzględnieniem dodatkowo rzędów wielomianów. 
* Metoda wykorzystuje funkcję "print" do wyświetlenia kolejnych elementów wektora.
*
*/
std::ostream& ARX::wyswietlParametry(std::ostream& os){
    os << "Oto aktualnie wybrane parametry modelu ARX: \n";
    os << "dA = " << this->s_paramA.size() << ", dB = " << this->s_paramB.size() << std::endl;
    os << "s_k = " << this->s_k << ", s_varE = " << this->s_varE << std::endl; 
    os << "Param_A: ";
    print(this->s_paramA);
    os << "Param_B: ";
    print(this->s_paramB);
    os << std::endl;
    return os;
}

/*
* Wpisanie nowych współczynników wielomianu A. 
* Wyzerowanie kolejek s_y oraz s_u, z uwzględnieniem nowej wielkości wielomianu A
*
*/
void ARX::aktualizujWielomianA(std::vector <double> wielomian) {
    this->s_paramA.clear();
    this->s_paramA = wielomian;
    this->s_y.resize((int)s_paramA.size(), 0);
    this->s_u.resize((int)s_paramB.size() + s_k, 0);
}

/*
* Wpisanie nowych współczynników wielomianu B.
* Wyzerowanie kolejek s_y oraz s_u, z uwzględnieniem nowej wielkości wielomianu B
*
*/
void ARX::aktualizujWielomianB(std::vector <double> wielomian) {
    this->s_paramB.clear();
    this->s_paramB = wielomian;
    this->s_y.resize((int)s_paramA.size(), 0);
    this->s_u.resize((int)s_paramB.size() + s_k, 0);
}

/* 
* Wpisanie nowej wartości opóźnienia. 
* Aktualizacja wielkości kolejki s_u.
*
*/
void ARX::aktualizujParametr(unsigned int parametr) {
    this->s_k = parametr;
    this->s_y.resize((int)s_paramA.size(), 0);
    this->s_u.resize((int)s_paramB.size() + s_k, 0);
}

/* 
* Wpisanie nowej wartości wariancji białego szumu.
* Zerowanie kolejek s_y oraz s_u
* 
*/
void ARX::aktualizujParametr(double parametr) {
    this->s_varE = parametr;
    this->s_y.resize((int)s_paramA.size(), 0);
    this->s_u.resize((int)s_paramB.size() + s_k, 0);
}

/* 
* Symulacja modelu ARX. Na wejściu podawana jest pojedyncza próbka wejścia,
* zaś poprzez symulację otrzymywana jest próbka wyjścia. Wyjście zaszumiane jest białym szumem.
* 
*/
double ARX::Symuluj(double u){
    //Usunięcie wartości wejścia z tyłu i dodanie nowego wejścia z przodu.
    this->s_u.push_front(u);
    this->s_u.pop_back();
    //Obliczenie wartości wyjścia w i-tej próbce
    double a = std::inner_product(this->s_paramB.begin(), this->s_paramB.end(), this->s_u.begin()+s_k, 0.0);
    double b = std::inner_product(this->s_paramA.begin(), this->s_paramA.end(), this->s_y.begin(), 0.0);
    double wynik = a - b;
    //Losowanie wartości, odwzorowującej szum (rozkład normalny)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(0, 1);
    double szum = dist(gen) * s_varE;
    //Usunięcie wartości wyjścia z tyłu i dodanie nowego wyjścia wraz z szumem z przodu.
    this->s_y.push_front(wynik+szum);
    this->s_y.pop_back();
    return wynik;
}

/* 
* Odczyt danych z wcześniej przygotowanego pliku "obiekt.json".
* Podczas odczytu istotne jest nazewnictwo zmiennych podanych w pliku.
* Metoda aktualizuje odpowiednie pola obiektu ARX.
* 
*/
void ARX::odczytajDane(ARX& arx) {

    // Odczyt danych z pliku JSON
    std::ifstream input("obiekt.json");
    auto j = json::parse(input);

    // Zapis danych do odpowiednich pól obiektu
    arx.aktualizujWielomianA(j["paramA"]);
    arx.aktualizujWielomianB(j["paramB"]);
    unsigned int k = j["k"];
    double var = j["varE"];
    arx.aktualizujParametr(k);
    arx.aktualizujParametr(var);
}

/* 
* Zapis danych z obiektu ARX do pliku "obiekt.json".
* Podczas zapisu do pliku wybierane jest nazewnictwo zmiennych.
* Metoda aktualizuje dane parametru.
* 
*/
void ARX::zapiszDane() {
    // Tworzenie obiektu JSON
    json data = {
        {"paramA", this->s_paramA},
        {"paramB", this->s_paramB},
        {"k", this->s_k},
        {"varE", this->s_varE}
    };

    // Zapisywanie danych do pliku JSON
    std::ofstream file("obiekt.json");
    file << data;
    file.close();
}

//Wyświetlanie podanego do funkcji wektora
void print(std::vector<double> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}