#pragma once
/**
* @file klasaSISO.hpp
* Klasa SISO stanowi klasę bazową w postaci interfejsu dla klas pochodnych. 
* W jej skład wchodzi jedynie czysto wirtualna metoda Symuluj, zwracająca próbkę wyjścia, po podaniu na nią próbki wejścia.
*/

class SISO{
public:
    ///Przez to, że klasa posiada jedynie metodę wirtualną, wirtualny musi być również destruktor.
    virtual ~SISO() {};
    /**
    * Metoda czysto wirtualna, symuluje zwraca próbkę wyjścia po dostarczeniu próbki wejścia.
    * @param[in] s_u
    * @param[out] y
    */
    virtual double Symuluj(double s_u) = 0;
};