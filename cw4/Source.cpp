/*
1. Napisz funkcj� o nag��wku vector<double> suma(vector<double> t1, vector<double> t2) ,
kt�ra zwr�ci tablic� wype�nion� w taki spos�b, aby ka�dy element tej tablicy by� sum� odpowiednich element�w z tablic t1 i t2
(zadbawszy uprzednio o odpowiedni rozmiar wektora wynikowego). Co proponujesz zrobi�, gdy rozmiary tablic danych s� r�ne?

2. Napisz funkcj� o nag��wku vector<int> uporzadkuj(const vector<int> & dane), kt�ra zwr�ci nowy wektor z t� sam� zawarto�ci�,
co dany,ale uporz�dkowany w ten spos�b, by wszystkie liczby parzyste poprzedza�y liczby nieparzyste.
Nie u�ywaj �adnych standardowych algorytm�w ani struktur danych opr�cz vectora.

3. *Napisz program, kt�ry spyta u�ytkownika o nazw� pliku i przeprowadzi statystyk� znak�w niebia�yc wyst�puj�cych w tym pliku
wy�wietlaj�c jednokrotnie kod ka�dego z wyst�puj�cych znak�w wraz z jego liczebno�ci�. U�yj vectora.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<double> suma(vector<double> t1, vector<double> t2);
vector<int> uporzadkuj(const vector<int>& dane);

int main() {
	//test pierwszego zadania
	vector<double> pierwsza = { 1.22, 2.11, 3.43 };
	vector<double> druga = { 1.56, 2.532, 3.12, 4.55, 5.666, 6.633};
	vector<double> wynik = suma(pierwsza, druga);

	cout << "Wynik dodawania wektorow: " << endl;
	for (int i = 0; i < wynik.size(); i++)
	{
		cout << wynik.at(i) << " ";
	}
	
	
	//test drugiego zadania
	vector<int> dane = { 11, 23, 1, 3, 2, 4, 1, 4, 66, 21 };
	vector<int> uporzadkowaneDane = uporzadkuj(dane);

	cout << "\nUporzadkowane dane od najmniejszej do najwiekszej (najpierw nieparzyste a pozniej parzyste)\n";
	for (int i = 0; i < uporzadkowaneDane.size(); i++)
	{
		cout << uporzadkowaneDane.at(i) << " ";
	}


	//ZADANIE NR 3
	cout << "\n\nPodaj nazwe pliku: ";
	string nazwaPliku; cin >> nazwaPliku;
	char* plik = new char[64];
	strcpy_s(plik, nazwaPliku.length()+1, nazwaPliku.c_str());
	
	vector <int> znaki(128);

	ifstream p(plik);
	
	if (p.is_open()) {
		char c;
		while (p.get(c)) {
			if (isspace(c)) continue;
			znaki.at(toascii(c)) += 1;
		}
	}
	else
	{
		cout << "Brak pliku";
	}
	p.close();
	delete[] plik;

	cout << "\nStatystyka wystapien znakow z wykluczeniem bialych znakow\n\n";
	for (int i = 0; i < znaki.size(); i++)
	{
		if (znaki[i] > 0) {
			cout << "Znak: '" << (char)i << "' Kod ASCII: " << i << " Ilosc wystapien: " << znaki.at(i) << endl;
		}
		
	}
	return 0;
}

vector<double> suma(vector<double> t1, vector<double> t2) {
	vector<double> wynik;

	if (t1.size() > t2.size()) {
		wynik = t1;
		for (int i = 0; i < t2.size(); i++)
		{
			wynik[i] += t2[i];
		}
	}
	else
	{
		wynik = t2;
		for (int i = 0; i < t1.size(); i++)
		{
			wynik[i] += t1[i];
		}
	}
	return wynik;
}

vector<int> uporzadkuj(const vector<int>& dane) {

	vector<int> wynik = dane;
	int licznikParzystych = 0;

	// przenosze parzyste na koniec i zliczam ich ilosc
	for (int i = 0; i < wynik.size() - licznikParzystych; i++)
	{
		if (wynik.at(i) % 2 == 0 ) {			
			wynik.push_back(wynik.at(i));
			wynik.erase(wynik.begin()+i);
			i--;
			licznikParzystych++;
		}
	}

	//sortowanie nieparzystych babelkowo
	for (int i = 0; i < wynik.size() - licznikParzystych; i++)
	{
		for (int j = 0; j < wynik.size() - licznikParzystych - 1; j++)
		{
			if (wynik[j] > wynik[j + 1])
				swap(wynik[j], wynik[j + 1]);

		}
	}

	//sortowanie parzystych babelkowo
	for (int i = wynik.size() - licznikParzystych; i < wynik.size(); i++)
	{
		for (int j = wynik.size() - licznikParzystych; j < wynik.size() - 1; j++)
		{
			if (wynik[j] > wynik[j + 1])
				swap(wynik[j], wynik[j + 1]);

		}
	}
	return wynik;
}