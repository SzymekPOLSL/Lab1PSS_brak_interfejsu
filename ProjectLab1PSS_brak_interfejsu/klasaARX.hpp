#include "klasaSISO.hpp"
#include <iostream>
#include <vector>
#include <deque>

/** 
* @file klasaARX.hpp
* Klasa ARX dziedziczy metodę Symuluj z klasy interfejs SISO. 
* Jej zadaniem jest symulacja obiektu w postaci modelu ARX
*/

class ARX: public SISO{
    int s_k; ///< Opóźnienie
    double s_varE; ///< Wariancja białego szumu

protected:
    /// Współczynniki wielomianów A oraz B
    std::vector<double> s_paramA, s_paramB;
    ///Kolejki z wartościami wejścia oraz wyjścia. Ich rozmiar zależy od ilości współczynników wielomianów A oraz B.
    std::deque<double> s_u, s_y; 

public:
    ARX(); ///< Konstruktor domyślny
    ARX(std::vector<double> nparamA, std::vector<double> nparamB, int nk, double nvarE); ///< Konstruktor parametryczny
    ~ARX();

    std::ostream& wyswietlParametry(std::ostream & os); ///< Metoda odpowiedzialna za wyświetlenie aktualnych pól opisujących model ARX.

    
    // Kolejne 4 metody pełnią rolę Setterów, umożlwiających zastąpienie poszczególnych pól obiektu ARX.
    ///Zmiana współczynników wielomianu A
    void aktualizujWielomianA(std::vector <double> wielomian);
    ///Zmiana współczynników wielomianu B
    void aktualizujWielomianB(std::vector <double> wielomian);
    ///Zmiana opóźnienia modelu ARX
    void aktualizujParametr(int parametr);
    ///Zmiana wariancji białego szumu
    void aktualizujParametr(double parametr);

    double Symuluj(double s_u) override; ///< Dziedziczona metoda Symuluj z klasy bazowej SISO

    ///Metoda służy do odczytania parametrów obiektu ARX z pliku konfiguracyjnego (json)
    void odczytajDane(ARX& arx);
    
    ///Metoda służy do zapisu aktualnych parametrów obiektu ARX z pliku konfiguracyjnego (json)
    void zapiszDane();
};