#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <locale>
#include "json.hpp"
#include "klasaARX.hpp"
#include "klasaSISO.hpp"

/// Funkcja odpowiedzialna za zapis wyjścia modelu ARX do pliku
void zapiszDoPliku(std::vector<double> dane);

int main(){
    //Uwzlęgnienie przy wypisywaniu danych w terminalu polskich liter.
    std::locale::global(std::locale("pl_PL.UTF-8"));
    std::wcout.imbue(std::locale());
    std::vector<double> wyjscie_y;

    //Stworzenie obiektu klasy ARX
    //Wybór jednej z możliwości
    //ARX arx = { { -0.4 }, { 0.6 }, 1, 0.01 };
    //ARX arx = { { -0.4 }, { 0.6 }, 2, 0 };
    //ARX arx = { {-0.4, 0.2}, {0.6, 0.3}, 2, 0.0 };

    //Stworzenie obiektu o domyślnych parametrach
    ARX arx;

    //Zamiana parametrów obiektu na dane z pliku konfiguracyjnego
    arx.odczytajDane(arx);
    arx.wyswietlParametry(std::cout);
    
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

    //Zapisanie danych otrzymanego wyjścia do pliku tekstowego.
    zapiszDoPliku(wyjscie_y);

    //Zapisanie parametrów obiektu do pliku
    arx.zapiszDane();
    arx.wyswietlParametry(std::cout);

    return 0;
}

//Zapisywanie danych w postaci wektora zawierającego dane typu double do pliku.
void zapiszDoPliku(std::vector<double> dane){

    //Otwarcie pliku do zapisu
    std::ofstream plik("Dane.txt", std::ios::out);

    //Sprawdzenie, czy plik został poprawnie otwarty
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