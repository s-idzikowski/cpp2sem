#include <iostream>

using namespace std;

int sumaLiczb(int*);

int main() {
	//int a = 5;
	//int *b = &a; //wskaznik b bedzie wskazywal na pamiec zmiennej a

	//cout << "Wartosc zmienna a:" << a << "\n";
	//cout << "Wielkosc zmiennej a: " << sizeof(a) << "\n";
	//cout << "Alokacja zmiennej a: " << &a <<"\n";

	//cout << "Wartosc zmienna b:" << *b << "\n"; //wyluskac musimy
	//cout << "Wielkosc zmiennej b: " << sizeof(b) << "\n";
	//cout << "Alokacja zmiennej b: " << b << "\n"; //bez operatora adresu

	int a[] = { 2, 5, 8, 9, 11 };
	//int b = 6;
	cout << "Suma elementow tablicy = " << sumaLiczb(&a[0]);
	return 0;
}

int sumaLiczb(int* x) {
	int wynik = 0;

	for (int i = 0; i < 5; i++)
	{
		wynik += (*x);
		++(x);
	}

	return wynik;
}