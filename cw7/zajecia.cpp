//Utw�rz program realizuj�cy zadanie wyliczenia pola powierzchni ca�kowitej i obj�to�ci bry�y wskazanej z menu u�ytkownika.
//
//Menu
//1. Sze�cian
//2. Ostros�up o podstawie kwadratu
//3. Walec
//4. Kula
//5. Graniastos�up prawid�owy o podstawie tr�jk�ta
//
//W ramach realizacji zadania utw�rz :
//*klas� abstrakcyjn� "Bry�a" zawieraj�ca metody wirtualne "Objetosc" i "PCalkowite"
//* klasy specjalistyczne dziedzicz�ce po klasie "Bryla" zawieraj�ce definicje odpowiednich p�l jak i implementacje metod odziedziczonych, a tak�e ewentualne inne metody(metody dost�powe do p�l, metody wyliczaj�ce pole powierzchni boku i podstawy je�eli ich definicja jest uzasadniona)

#include <iostream>
#include <cmath>

using namespace std;

class Bryla {
	public:
		virtual float Objetosc() = 0;
		virtual float PCalkowite() = 0;
};

class Szescian : public Bryla {
private:
	float dlugoscBoku;
public:
	Szescian(float dlugoscBoku) {
		this->dlugoscBoku = dlugoscBoku;
	}
	float Objetosc() {
		return pow(dlugoscBoku, 3);
	};
	float PCalkowite() {
		return 6 * pow(dlugoscBoku, 2);
	};
};

Bryla* bryla;
void PodajSzescian() {
	cout << "Podaj Dlugosc boku szesciana: ";
	float dlugoscBoku;
	cin >> dlugoscBoku;
	Szescian szescian(dlugoscBoku);
	bryla = &szescian;
	cout << "Objetosc szesciana to: " << bryla->Objetosc() << endl;
	cout << "Pole Calkowite szesciana to: " << bryla->PCalkowite() << endl;
}


int main() {

	cout << "Menu: \n";
	cout << "1. Szescian\n";
	cout << "2. Ostroslup o podstawie kwadratu\n";
	cout << "3. Walec\n";
	cout << "4. Kula\n";
	cout << "5. Graniastoslup prawidlowy o podstawie trojkata\n";

	int wybor;
	do
	{
		cout << "\nWybor: " << endl;
		cin >> wybor;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Podano bledne dane" << endl;
			break;
		}

		switch (wybor)
		{
		case 1:
			cout << "wybrano 1 - Szescian\n";
			PodajSzescian();
			break;
		case 2:
			cout << "wybrano 2";
			
			break;
		case 3:
			cout << "wybrano 3";
			break;
		case 4:
			cout << "wybrano 4";
			break;
		case 5:
			cout << "wybrano 5";
			break;
		default:
			cout << "Bledny wybor";
			break;
		}
	} while (true);
	

	return 0;
}