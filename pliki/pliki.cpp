/*
Zdefiniuj program pozwalaj¹cy odpowiedzieæ na pytania:

ilu klientów banku jest zad³u¿onych
na jaka ³¹czn¹ kwotê opiewa zad³u¿enie klientów


W ramach realizacji zadania utwórz:

funkcje realizuj¹ce podstawowe zadania programu (iloscKlientowZ, kwotaZadluzenia, pobiezDane, zapisz Plik)
strukturê ”Klienci” sk³adaj¹c¹ siê z odpowiednich pól (zgodnych z danymi zawartymi w pliku ”klienci.txt” – numerKlienta, zadluzenie)
zbiór przechowuj¹cy informacje o klientach banku
plik ”wynik.dat” zawieraj¹cy odpowiedz na zadane pytania
Uwaga:

    - liczba wierszy w pliku klienci.txt jest nieznana*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Klienci
{
	int numerKlienta;
	int zadluzenie;
} klienci[50];

int ilosc = 0;

void pobiezDane(char[]);
int iloscKlientowZ(Klienci klienci[]);
int kwotaZadluzenia(Klienci klienci[]);
void zapiszPlik(char* plik, string k);

int main()
{
    char plik[] = "klienci.txt";
    char plikWyjsciowy[] = "wynik.dat";
    pobiezDane(plik);
    string odpowiedz = "Zadluzonych:" + to_string(iloscKlientowZ(klienci)) + " Zadluzenia:" + to_string(kwotaZadluzenia(klienci));
    cout << odpowiedz;
    zapiszPlik(plikWyjsciowy, odpowiedz);
}

void pobiezDane(char plik[]) {
    ifstream p(plik);
    string linia;
    if (p.is_open()) {
        while (getline(p, linia)) {
            int spacja = linia.find(' ');
            klienci[ilosc].numerKlienta = stoi(linia.substr(0, spacja));
            klienci[ilosc].zadluzenie = stoi(linia.substr(spacja + 1, linia.size()));
            
            ilosc++;
        }
    }
    else
    {
        cout << "Brak pliku";
    }
    p.close();
}

int iloscKlientowZ(Klienci klienci[])
{
    int licznik = 0;
    for (int i = 0; i < ilosc; i++)
    {
        if (klienci[i].zadluzenie > 0)
            licznik++;
    }
    return licznik;
}

int kwotaZadluzenia(Klienci klienci[])
{
    int zadluzenie = 0;
    for (int i = 0; i < ilosc; i++)
    {
        zadluzenie += klienci[i].zadluzenie;
    }
    return zadluzenie;
}

void zapiszPlik(char * plik, string k)
{
    ofstream zap(plik, ios::binary);
    zap.write(k.c_str(), k.size());
    zap.close();
}