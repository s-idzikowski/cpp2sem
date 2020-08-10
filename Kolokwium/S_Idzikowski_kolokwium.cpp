#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Info_pociag
{
    int numer_pociagu;
    int liczba_km;
    int czas_opoznienia;
};

class Pociagi {
private:
    vector<Info_pociag> pociagi;
    
public:
    Pociagi(vector<Info_pociag> pociagi) {
        this->pociagi = pociagi;
    }
    int suma() {
        int suma = 0;
        for (size_t i = 0; i < pociagi.size(); i++)
        {
            suma += pociagi[i].czas_opoznienia;
        }
        return suma;
    }
    vector <Info_pociag> ktore_przekroczyly() {
        vector<Info_pociag> przekroczone;
        for (size_t i = 0; i < pociagi.size(); i++)
        {
            if (pociagi[i].czas_opoznienia > float((pociagi[i].liczba_km * (70.0 / 60)))*0.1) {
                przekroczone.push_back(pociagi.at(i));
            }
        }
        return przekroczone;
    }
};

void pobierzDane(char zrodlo[], vector<Info_pociag> &lista_pociagow);
void zapiszPlik(char* plik, string k);

int main() {

	char zrodlo[] = "pociagi.txt";
    vector<Info_pociag> lista_pociagow;
	pobierzDane(zrodlo, lista_pociagow);

    Pociagi * pociagi = new Pociagi(lista_pociagow);
    
    char plikWyjsciowy[] = "wynik.dat";

    string odpowiedz = "A) Pociagi, ktore przebyly trase w niedopuszczalnym czasie to: ";
    
    for (size_t i = 0; i < pociagi->ktore_przekroczyly().size(); i++)
    {
        odpowiedz.append(to_string(pociagi->ktore_przekroczyly()[i].numer_pociagu));
        odpowiedz.append(" ");
    }

    odpowiedz.append("\nB) Suma opoznien wszystkich pociagow to: " + to_string(pociagi->suma()));

    
    zapiszPlik(plikWyjsciowy, odpowiedz);
    //cout << odpowiedz;
    delete pociagi;
	return 0;
}

void pobierzDane(char zlodlo[], vector<Info_pociag> &lista_pociagow) {
    ifstream p(zlodlo);
    string linia;
    if (p.is_open()) {
        int licznik = 0;
        while (getline(p, linia)) {
            int spacja1 = linia.find(' ');
            string pozostalo = linia.substr(spacja1 + 1, linia.size());
            int spacja2 = pozostalo.find(' ');

            Info_pociag pociag;
            pociag.numer_pociagu = stoi(linia.substr(0, spacja1));
            pociag.liczba_km = stoi(pozostalo.substr(0, spacja2));
            pociag.czas_opoznienia = stoi(pozostalo.substr(spacja2 + 1));
            lista_pociagow.push_back(pociag);
        }
    }
    else
    {
        cout << "Brak pliku";
    }
    p.close();
}

void zapiszPlik(char* plik, string k)
{
    ofstream zap(plik, ios::binary);
    zap.write(k.c_str(), k.size());
    zap.close();
}