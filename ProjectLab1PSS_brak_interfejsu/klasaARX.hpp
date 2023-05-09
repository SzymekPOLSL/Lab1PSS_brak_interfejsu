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
    unsigned int s_k; ///< Opóźnienie
    double s_varE; ///< Wariancja białego szumu

protected:
    /// Współczynniki wielomianu A
    std::vector<double> s_paramA;
    /// Współczynniki wielomianu B
    std::vector<double> s_paramB;
    ///Kolejka z wartościami wejścia. Jej rozmiar zależy od ilości współczynników wielomianu B zsumowaną z opóźnieniem.
    std::deque<double> s_u; 
    ///Kolejka z wartościami wyjścia. Jej rozmiar zależy od ilości współczynników wielomianu A.
    std::deque<double> s_y;

public:
    ARX(); ///< Konstruktor domyślny
    /**
    * Konstruktor parametryczny z następującymi zmiennymi wejściowymi:
    * @param[in] paramA
    * @param[in] paramB
    * @param[in] k
    * @param[in] varE
    *
    */
    ARX(std::vector<double>& nparamA, std::vector<double>& nparamB, unsigned int& nk, double& nvarE);
    ~ARX();

    std::ostream& wyswietlParametry(std::ostream & os); ///< Metoda odpowiedzialna za wyświetlenie aktualnych pól opisujących model ARX.

    
    // Kolejne 4 metody pełnią rolę Setterów, umożlwiających zastąpienie poszczególnych pól obiektu ARX.
    ///Zmiana współczynników wielomianu A
    void aktualizujWielomianA(std::vector <double> wielomian);
    ///Zmiana współczynników wielomianu B
    void aktualizujWielomianB(std::vector <double> wielomian);
    ///Zmiana opóźnienia modelu ARX
    void aktualizujParametr(unsigned int parametr);
    ///Zmiana wariancji białego szumu
    void aktualizujParametr(double parametr);

    double Symuluj(double s_u) override; ///< Dziedziczona metoda Symuluj z klasy bazowej SISO

    /** 
    * Metoda służy do odczytania parametrów obiektu ARX z pliku konfiguracyjnego(json)
    * @param[in] obiekt ARX
    * @param[in] ścieżka do pliku, z którego odczytywane są parametry
    * 
    */
    void odczytajDane(ARX& arx, const std::string& file_path);
    
    /**
    * Metoda służy do zapisu aktualnych parametrów obiektu ARX z pliku konfiguracyjnego(json)
    * @param[in] ścieżka do pliku, do którego zapisywane są parametry
    * 
    */
    void zapiszDane(const std::string& file_path);
};