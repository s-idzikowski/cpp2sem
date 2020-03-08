#include<iostream>
using namespace std;

using std::cout;
using std::cin;

struct plyty {
    unsigned short int id_p;
    string tytul;
    string zespol;
    int rok;
    float cena;

};
int licznik = 0;
plyty asortyment[10];

void wstawPlyty(plyty[], int);
void wyswietlPlyty(plyty[], int);
void podajZespolwyswietl(plyty[], int);
void podajRokwyswietl(plyty[], int);


int main()
{
    while (true)
    {
        cout << "Menu \n";
        cout << "1. Wstaw atrybuty plyt\n";
        cout << "2. Wyswietl wszystkie plyty\n";
        cout << "3. Wyszukaj wszystkie plyty z podanego zespolu\n";
        cout << "4. Wyszukaj wszystkie plyty z podanego roku\n";
        cout << "5. Wyjdz\n";

        int wybor;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            wstawPlyty(asortyment, 10);
            break;
        case 2:
            wyswietlPlyty(asortyment, licznik);
            break;
        case 3:
            podajZespolwyswietl(asortyment, licznik);
            break;
        case 4:
            podajRokwyswietl(asortyment, licznik);
            break;
        case 5:
            cout << "KONIEC";
            return 0;
        default:
            continue;
        }
    }
}



void wstawPlyty(plyty plyta[], int n) {
    int i = 0;
    bool pyt = false;
    do {
        cout << "Podaj id plyty: "; cin >> plyta[i].id_p;
        cout << "Podaj tytul plyty: "; cin >> plyta[i].tytul;
        cout << "Podaj zespol: "; cin >> plyta[i].zespol;
        cout << "Podaj rok: "; cin >> plyta[i].rok;
        cout << "Podaj cene plyty: "; cin >> plyta[i].cena;
        cout << "Czy dodajesz plyte? (1-tak, 0-nie): ";
        licznik++;
        cin >> pyt;
    } while (pyt && i < n);
}

void wyswietlPlyty(plyty plyta[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << plyta[i].id_p << " id plyty " << endl;
        cout << plyta[i].tytul << " tytul plyty" << endl;
        cout << plyta[i].zespol << " zespol " << endl;
        cout << plyta[i].rok << " rok" << endl;
        cout << plyta[i].cena << " cena plyty " << endl;
    }
}

void podajZespolwyswietl(plyty plyta[], int n) {
    cout << "\nPodaj zespol ";
    string zespol;
    cin >> zespol;
    for (int i = 0; i < n; i++) {
        if (plyta[i].zespol == zespol)
        {
            cout << "\nId: " << plyta[i].id_p << " \n tutul: " << plyta[i].tytul;
            cout << "\nrok: " << plyta[i].rok << " \n cena " << plyta[i].cena;

        }
    }
}
void podajRokwyswietl(plyty plyta[], int n) {
    cout << "\nPodaj rok ";
    int rok;
    cin >> rok;
    for (int i = 0; i < n; i++) {
        if (plyta[i].rok == rok)
        {
            cout << "\nId: " << plyta[i].id_p << " tutul: " << plyta[i].tytul;
            cout << "\nrok: " << plyta[i].rok << " \n cena " << plyta[i].cena;

        }

    }
}