/*Zdefiniuj program pozwalaj¹cy odpowiedzieæ na pytania :

ilu klientów banku jest zad³u¿onych
na jaka ³¹czn¹ kwotê opiewa zad³u¿enie klientów


W ramach realizacji zadania utwórz :

funkcje realizuj¹ce podstawowe zadania programu(iloscKlientowZ, kwotaZadluzenia, pobiezDane, zapisz Plik)
strukturê ”Klienci” sk³adaj¹c¹ siê z odpowiednich pól(zgodnych z danymi zawartymi w pliku ”klienci.txt” – numerKlienta, zadluzenie)
zbiór przechowuj¹cy informacje o klientach banku
plik ”wynik.dat” zawieraj¹cy odpowiedz na zadane pytania
Uwaga :

-liczba wierszy w pliku klienci.txt jest nieznana


Plan:
1. Pobranie danych z pliku klienci.txt. osobno kolumna z Id i osobno kolumna z zadluzeniem.
2. Stworzenie struktury z tych danych(macierz 15 wierszy, 2 kolumny)
3. Zbudowanie petli ktora zliczy ile jest zadluzonych klientow na podstawie struktury
4. Suma ogolnego zadluzenia, zliczenie sumy drugiej kolumny struktury
5. Zapisanie dwoch liczb - 3 i 4 w nowym pliku


       pytanie - jak sciagnac dane z pliku tak aby pobrac dwie kolumny z pliku i stworzyc z tego strukture*/

#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<stdio.h>

using namespace std;

struct Klienci
{
    int numerKlienta;
    int zadluzenie; //Cechy struktury
};

//void zapis(int[], Klienci);


int main()
{
    int numerKlienta;
    int zadluzenie;
    Klienci tablica_zadluzenia;

    tablica_zadluzenia[]zadluzenie + tablica_zadluzenia[]numerKlienta = tablica_zadluzenia;
    ifstream uchwyt_z_pliku;
    uchwyt_z_pliku.open("klienci.txt", ios::in);
    if (uchwyt_z_pliku.is_open()) {//metoda is_open sprawdza, czy otwarcie pliku siê powiod³o
        for (;;) {
            int numerKlienta; int zadluzenie;
            if (!(uchwyt_z_pliku >> numerKlienta)) break; //przerwanie, je¿eli natrafiono na znacznik konca pliku eof
            uchwyt_z_pliku >> zadluzenie;
            cout << endl << numerKlienta << " " << zadluzenie;
        }
        uchwyt_z_pliku.close();//zamkniêcie pliku
    }
    // do
    // {
      //   getchar("klienci.txt", " ") || (" ", "klienci.txt");
       //  {
        //     kolumna1 = ("klienci.txt", " ");
         //    kolumna2 = (" ", "klienci.txt");
        // }
       //   cout << kolumna1 << " " << kolumna2 << endl;
    // }
     //while (kolumna1 != ""); {
    // cout << "Brak pliku";

     //return 0;
    uchwyt_z_pliku.close();

    int kwotaZadluzenia;
    {
        int i = zadluzenie;
        for (int i = 0; i < 10000; i++) {
            kwotaZadluzenia += tablica_zadluzenia[]zadluzenie;
        }
        return 0; }
    void zapis(int[], Klienci);
    {
        ofstream uchwyt_do_pliku;
        uchwyt_do_pliku.open("wynik.dat", ios::out);
        uchwyt_do_pliku << Klienci << endl;
        uchwyt_do_pliku.close();
    }

    system("pause");

}