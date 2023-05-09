#pragma once
#include <vector>
#include <iostream>

/**
* @file funkcjePomocnicze.hpp
* Plik zawiera w sobie definicje funkcji pomocniczych, wykorzystywanych w głównej części projektu.
*
*/

/// Funkcja odpowiedzialna za zapis wyjścia modelu ARX do pliku.
void zapiszDoPliku(std::vector<double> dane, const std::string& file_path);

///Funkcja umożlwiająca wyświetlenie kolejnych elementów wektora.
void print(std::vector<double> const& input);