#include<iostream>

using std::cout;
using std::cin;

struct lalki {
	unsigned short int id_l;
	char nazwa[10];
	float cena;
	int ilosc;
	float kwota() {
		return cena * ilosc;
	}
};

lalki asortyment[3];

void wstawZabawke(lalki[], int);
void wyswietlZabawki(lalki[], int);

int main() {
	wstawZabawke(asortyment, 2);
	system("CLS");
	wyswietlZabawki(asortyment, 2);
	return 0;
}

void wstawZabawke(lalki lala[], int n) {
	int i = 0;
	bool pyt = false;
	do {
		cout << "Podaj id lalki: "; cin >> lala[i].id_l;
		cout << "Podaj nazwe lalki: "; cin >> lala[i].nazwa;
		cout << "Podaj cena lalki: "; cin >> lala[i].cena;
		cout << "Podaj ilosc lalek: "; cin >> lala[i].ilosc;
		cout << "Czy dodajesz lalke? (1-tak, 0-nie): ";
		cin >> pyt;
		i++;
	} while (pyt && i < n);
}

void wyswietlZabawki(lalki lala[], int n) {
	int i = 0;
	do {
		cout << lala[i].id_l << " ";
		cout << lala[i].nazwa << " " << lala[i].cena << " ";
		cout << lala[i].ilosc << " kwota laczna: " << lala[i].kwota() << "\n";
		i++;
	} while (i < n);
}
