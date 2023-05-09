#include "funkcjePomocniczne.hpp"
#include <fstream>
#include <iostream>

//Zapisywanie danych w postaci wektora zawierającego dane typu double do pliku.
void zapiszDoPliku(std::vector<double> dane, const std::string& file_path) {

    //Otwarcie pliku do zapisu
    std::ofstream plik(file_path, std::ios::out);

    //Sprawdzenie, czy plik został poprawnie otwarty
    if (plik.is_open())
    {
        std::cout << "Nastąpi zapis danych do pliku!" << std::endl;

        // Zapisanie danych do pliku
        for (const auto& d : dane)
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

//Wyświetlanie podanego do funkcji wektora
void print(std::vector<double> const& input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}