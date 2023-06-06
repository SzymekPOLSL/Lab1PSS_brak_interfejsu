#pragma once
#include "Komponent_Struktura.hpp"
/**
* @file klasaSISO.hpp
* Klasa SISO stanowi klasę bazową w postaci interfejsu dla klas pochodnych. Dziedziczy również elementy
* W jej skład wchodzi jedynie czysto wirtualna metoda Symuluj, zwracająca próbkę wyjścia, po podaniu na nią próbki wejścia.
*/

class SISO: public Komponent_Struktura {
public:
    ///Przez to, że klasa posiada jedynie metodę wirtualną, wirtualny musi być również destruktor.
    virtual ~SISO() {};

};