/*
Menu

Ze zbioru n - element-owego wartoœci losowych z przedzia³u <p,q> wybraæ wartoœæ najwiêksz¹ i najmniejsz¹
Obliczyæ sumê wartoœci parzystych zawartych w zbiorze wartoœci losowych z przedzia³u <p,q>
Koniec
 Uwaga:

		   Program powinien byæ napisany zgodnie z paradygmatem proceduralnym, a wiêc w ramach realizacji programu utworzyæ:

funkcjê „uzupe³nij” posiadajaca trzy argument: wskaŸnik na tablicê, referencja na p, referencja na q
funkcjê „wyswietl” posiadaj¹c¹ argument bêd¹cy wskaŸnikiem na tablicê
funkcjê „suma” – zawieraj¹c¹ instrukcje wyszukuj¹ce ze zbioru przekazanego poprzez wskaŸnik wartoœci parzyste oraz wyliczaj¹cy sumê tych elementów
funkcjê „min_max” -  wyszukuj¹ca ze zbioru przekazanego poprzez wskaŸnik wartoœci najwiêkszej i najmniejszej
funkcjê „menu” zwracaj¹c¹ wartoœæ wyboru przez u¿ytkownika opcji
- wartoœci p,q oraz wielkoœæ zbioru, podaje u¿ytkownik
- zabezpieczyæ program przed wprowadzaniem wartoœci b³êdnych
*/
#include <iostream>
#include <time.h>

using namespace std;

void uzupelnij(int* tab, int &p, int &q);
void wyswietl(int*);
void suma(int*); //wartosci parzyste
void min_max(int*);
int menu();
void bledneDane(); //jesli bledne dane to czyscimy bufor

int ilosc = 0;
int p, q;

int main() {

    srand(time(NULL));

    do
    {
        cout << "Podaj wielkosc zbioru: " << endl;
        cin >> ilosc;
        if (cin.fail()) {
            bledneDane();
        }
    } while (ilosc <= 0);

    int* zbior = new int[ilosc];

    while (true)
    {
        cout << "Menu \n";
        cout << "1. Uzupelnij\n";
        cout << "2. Wyswietl\n";
        cout << "3. Suma\n";
        cout << "4. Min_Max\n";
        cout << "5. Wyjdz\n";

        int wybor = menu();

        switch (wybor)
        {
        case 1:
            uzupelnij(zbior, p, q);
            break;
        case 2:
            wyswietl(zbior);
            break;
        case 3:
            suma(zbior);
            break;
        case 4:
            min_max(zbior);
            break;
        case 5:
            cout << "Wyjscie z programu";
            delete[] zbior;
            return 0;
        default:
            continue;
        }
    }
}

int menu() {
    int wybor = 0;
    do
    {
        cin >> wybor;
        if (cin.fail())
            bledneDane();
    } while (wybor < 0 && wybor >= 5);
    
    return wybor;
}

void uzupelnij(int* tab, int &p, int &q) {
    do
    {
        cout << "Podaj p i q: " << endl;
        cin >> p >> q;
        if (cin.fail()) {
            bledneDane();
            continue;
        }
        if (p >= q) {
            cout << "p musi byc mniejsze od q" << endl;
        }
        if (p <= 0 || q > ilosc) {
            cout << "Nieprawidlowy zakres. Wykracza poza dozwolona ilosc" << endl;
        }
    } while ((p >= q) || (p <= 0) || (q > ilosc));

    srand(time(0));
    for (int i = 0; i < ilosc; i++)
    {
        *tab = rand();
        tab++;
    }
   
}

void wyswietl(int* x) {
    for (int i = 0; i < ilosc; i++)
    {
        cout << "Pozycja: " << i+1 << " wartosc: " << *x << endl;
        ++x;
    }
}

void suma(int* x) {
    int suma = 0;
    for (int i = p-1; i < q; i++)
    {
        if (*(x + i) % 2 == 0) {
            suma += *(x + i);
        }
    }
    cout << "Suma parzystych liczb z przedzialu od " << p << " do " << q <<" wynosi: " << suma << endl;
}

void min_max(int* x) {
    int min = *(x + p);
    int max = *(x + p);
    for (int i = p+1; i < q; i++)
    {
        if (*(x + i) < min) {
            min = *(x + i);
        }
        if (*(x + i) > max) {
            max = *(x + i);
        }
    }
    cout << "Wartosc minimalna z przedzialu od " << p << " do " << q << " wynosi: " << min << endl;
    cout << "Wartosc maksymalna z przedzialu od " << p << " do " << q << " wynosi: " << max << endl;
}

void bledneDane() {
        system("cls");
        cout << "*****************************\n";
        cout << "Wprowadzono niepoprawne dane!\n";
        cout << "*****************************\n";
        cin.clear();
        cin.ignore(100, '\n');
}