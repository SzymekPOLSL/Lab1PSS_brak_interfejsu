#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <locale>
#include "klasaARX.hpp"
#include "klasaSISO.hpp"

//Zapis wyjścia modelu ARX do pliku
void zapiszDoPliku(std::vector<double> dane);

int main(){
    std::locale::global(std::locale("pl_PL.UTF-8"));
    std::wcout.imbue(std::locale());
    std::vector<double> wyjscie_y;

    //Stworzenie obiektu klasy ARX
    //Wybór jednej z możliwości
    ARX arx = { { -0.4 }, { 0.6 }, 1, 0 };
    //ARX arx = { { -0.4 }, { 0.6 }, 2, 0 };
    //ARX arx = { {-0.4, 0.2}, {0.6, 0.3}, 2, 0.0 };
    arx.wyswietlParametry();
    
    //Symulacja dla zadanej liczby próbek i wejścia w postaci skoku jednostkowego
    for (int i = 0; i < 25; i++)
    {   
        if (i == 0) {
            double y_i = arx.Symuluj(0.0);
            std::cout << "wyjście: " << y_i << std::endl;
            wyjscie_y.push_back(y_i);
        }
        else {
            double y_i = arx.Symuluj(1.0);
            std::cout << "wyjście: " << y_i << std::endl;
            wyjscie_y.push_back(y_i);
        }
    }

    zapiszDoPliku(wyjscie_y);
    arx.wyswietlParametry();
    
    return 0;
}

void zapiszDoPliku(std::vector<double> dane){

    std::ofstream plik("Dane.txt", std::ios::out);

    if (plik.is_open())
    {
        std::cout << "Nastąpi zapis danych do pliku!" << std::endl;

        // Zapisanie danych do pliku
        for (const auto &d : dane)
        {
            plik << d << "\n"; // Zapisanie danych, oddzielając je znakiem nowej linii
        }

        // Zamknięcie pliku
        plik.close();
    }
    else
    {
        std::cout << "Nie udało się otworzyć pliku do zapisu!" << std::endl;
    }

}