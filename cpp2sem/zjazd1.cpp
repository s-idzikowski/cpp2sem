#include<iostream>
#include<cstdlib>

using std::cin;
using std::cout;

struct napoj
{
	int id;
	char rodzaj[20];
	char nazwa[20];
	float cena;
	int ilosc;
	float wartosc() {
		return ilosc * cena;
	}
};

void uzupelnij(napoj napoje[], int ilosc);


int main()
{
	napoj browarki[5];
	uzupelnij(browarki, 2);
	int ktory = 0;
	cout << "Podaj rekord: "; cin >> ktory;

	
	cout << browarki[ktory - 1].nazwa << " " << browarki[ktory - 1].wartosc();

	return 0;
}

void uzupelnij(napoj napoje[], int ilosc) {
	for (int i = 0; i < ilosc; i++)
	{
		cout << "Podaj identyfikator napoju: "; cin >> napoje[i].id;
		cout << "Podaj nazwe napoju: "; cin >> napoje[i].nazwa;
		cout << "Podaj rodzaj napoju: "; cin >> napoje[i].rodzaj;
		cout << "Podaj cene napoju: "; cin >> napoje[i].cena;
		cout << "Podaj ilosc napoju: "; cin >> napoje[i].ilosc;
	}
}
	

