#include <iostream>
#pragma once

class SISO{
public:
    virtual ~SISO();
    //Metoda czysto wirtualna, zwraca próbkę wyjścia
    virtual double Symuluj(double s_u) = 0;
};