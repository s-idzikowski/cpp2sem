/*
Menu

Ze zbioru n - element-owego warto�ci losowych z przedzia�u <p,q> wybra� warto�� najwi�ksz� i najmniejsz�
Obliczy� sum� warto�ci parzystych zawartych w zbiorze warto�ci losowych z przedzia�u <p,q>
Koniec
 Uwaga:

		   Program powinien by� napisany zgodnie z paradygmatem proceduralnym, a wi�c w ramach realizacji programu utworzy�:

funkcj� �uzupe�nij� posiadajaca trzy argument: wska�nik na tablic�, referencja na p, referencja na q
funkcj� �wyswietl� posiadaj�c� argument b�d�cy wska�nikiem na tablic�
funkcj� �suma� � zawieraj�c� instrukcje wyszukuj�ce ze zbioru przekazanego poprzez wska�nik warto�ci parzyste oraz wyliczaj�cy sum� tych element�w
funkcj� �min_max� -  wyszukuj�ca ze zbioru przekazanego poprzez wska�nik warto�ci najwi�kszej i najmniejszej
funkcj� �menu� zwracaj�c� warto�� wyboru przez u�ytkownika opcji
- warto�ci p,q oraz wielko�� zbioru, podaje u�ytkownik
- zabezpieczy� program przed wprowadzaniem warto�ci b��dnych
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