#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <locale>
#include "json.hpp"
#include "klasaARX.hpp"
#include "klasaSISO.hpp"
#include "PI.hpp"
#include "PD.hpp"
#include "PID.hpp"
#include "funkcjePomocniczne.hpp"
#include "Komponent.hpp"
#include "KomponentKonkretny.hpp"
#include "DekSin.hpp"
#include "DekSzum.hpp"
#include "DekProst.hpp"

int main(){
    //Uwzględnienie przy wypisywaniu danych w terminalu polskich liter.
    std::locale::global(std::locale("pl_PL.UTF-8"));
    std::wcout.imbue(std::locale());
    std::vector<double> wyjscie_y;
    std::vector<double> wyjscie_u;
    std::vector<double> wyjscie_w;

    //Stworzenie obiektu klasy ARX
    //Wybór jednej z możliwości
    //ARX arx{ { -0.4 }, { 0.6 }, 1, 0.05 };
    //ARX arx = { { -0.4 }, { 0.6 }, 2, 0 };
    //ARX arx = { {-0.4, 0.2}, {0.6, 0.3}, 2, 0.0 };

    //Stworzenie obiektu o domyślnych parametrach
    ARX arx;
    //Stworzenie regulatorów PI oraz PD o domyślnych parametrach
    PI pi;
    PD pd;
    //Stworzenie regulatora PID o zadanych wartościach parametrów
    PID pid = {0.1, 0.1, 0.0, 100.0, 0.0, 1.0, 2.0};
    pid.wyswietlParametryPID(std::cout);

    //Ścieżki do zapisu oraz odczytu parametrów
    std::string file_path_odczyt = "C:/Users/panda/source/repos/ProjectLab1PSS_brak_interfejsu/ProjectLab1PSS_brak_interfejsu/obiekt.json";
    std::string file_path_zapis = "C:/Users/panda/source/repos/ProjectLab1PSS_brak_interfejsu/ProjectLab1PSS_brak_interfejsu/data.json";

    //Zamiana parametrów obiektów na dane z pliku konfiguracyjnego
    arx.odczytajDane(arx, file_path_odczyt);
    pi.odczytajDane(pi, file_path_odczyt);
    pi.wyswietlParametryPI(std::cout);
    arx.wyswietlParametry(std::cout);

    //Przygotowanie wartości zadanej, wykorzystanej w regulacji obiektu
    Komponent* simple = new KomponentKonkretny(2);
    Komponent* decorator1 = new DekSzum(simple, 0.1);
    Komponent* decorator2 = new DekSin(decorator1, 1, 60, 0);
    Komponent* decorator3 = new DekProst(decorator2, 1, 20);

    //Zmienne sterowania oraz wartości zadanej
    double u_i = 0;
    double w_i = 0;

    //Symulacja dla zadanej liczby próbek i wejścia w postaci sterowania wybranego regulatora.
    //Wartość zadana generowana jest przy wykorzystaniu generatora wartości zadanej.
    for (int i = 0; i < 50; i++)
    {   
        if (i == 0) {
            double y_i = arx.Symuluj(0.0);
            std::cout << "wyjście: " << y_i << std::endl;
            w_i = decorator3->gen();
            u_i = pi.Symuluj(w_i - y_i);
            wyjscie_u.push_back(u_i);
            wyjscie_y.push_back(y_i);
        }
        else {
            double y_i = arx.Symuluj(u_i);
            std::cout << "wyjście: " << y_i << std::endl;
            w_i = decorator3->gen();
            u_i = pi.Symuluj(w_i - y_i);
            wyjscie_u.push_back(u_i);
            wyjscie_y.push_back(y_i);
        }
    }

    //Zapisanie danych otrzymanego wyjścia do pliku tekstowego.
    std::string file_path = "C:/Users/panda/source/repos/ProjectLab1PSS_brak_interfejsu/ProjectLab1PSS_brak_interfejsu/Dane.txt";
    zapiszDoPliku(wyjscie_y, file_path);

    //Zapisanie parametrów obiektu oraz regulatora do pliku
    arx.zapiszDane(file_path_zapis);
    pi.zapiszDane(file_path_zapis);
    arx.wyswietlParametry(std::cout);

    delete decorator3;
    delete decorator2;
    delete decorator1;
    delete simple;

    return 0;
}