///*Napisz funkcj� o nag��wku vector<int> uporzadkuj(const vector<int> & dane), kt�ra zwr�ci nowy wektor z t� sam� zawarto�ci�,
//co dany,ale uporz�dkowany w ten spos�b, by wszystkie liczby parzyste poprzedza�y liczby nieparzyste.
//Nie u�ywaj �adnych standardowych algorytm�w ani struktur danych opr�cz vectora.
//*/
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector<int> uporzadkuj(const vector<int>& dane);
//
//int main() {
//
//	vector<int> numbers;
//	int value = 0;
//
//	cout << "Dodaj nieujemne elementy wektora. Polecenie zakonczy sie kiedy dodasz ujemna liczbe \n";
//	while (value >= 0) {
//		cin >> value;
//		if (value >= 0)
//			numbers.push_back(value);
//	}
//	
//	cout << "Uporzadkowanie dodanych elementow\n";
//	vector<int> uporzadkowane = uporzadkuj(numbers);
//	//wyswietlenie danych
//	for (int i = 0; i < uporzadkowane.size(); i++)
//	{
//		cout << uporzadkowane.at(i) << " ";
//	}
//	
//}
//
//vector<int> uporzadkuj(const vector<int>& dane) {
//
//	vector<int> newDane;
//
//	// iteruje po vectorze ktory zostanie przekazany do funkcji
//	for (int i = 0; i < dane.size(); i++)
//	{
//		// jesli liczba nie jest parzysta to umieszczam ja na koncu nowego wektora
//		if (dane.at(i) % 2 != 0) {
//			newDane.push_back(dane.at(i));
//		}
//		else // w przeciwnym wypadku (jesli jest parzysta) to umieszczam ja na poczatku nowego vectora
//		{
//			newDane.insert(newDane.begin(), dane.at(i));
//		}
//	}
//	//zwracam nowy uporzadkowany vector
//	return newDane;
//}