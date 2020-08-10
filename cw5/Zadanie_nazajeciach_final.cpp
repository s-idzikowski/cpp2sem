/*
Menu

Kalvin
Fahrenheit
Celsjusz

Uwaga:

- w ramach zadania utwórz klasê „Temperatura”, zawieraj¹c¹ chronione pole „temp” oraz publiczne metody dostêpowe do tego pola o nazwie „setTemp” i „getTemp”
- zadaniem metody „setTemp” jest ustalenie wartoœci dla pola „temp” na tak¹, jaka zostanie podana jako argument jej wywo³ania.
- zadaniem metody „getTemp” jest przekazanie wartoœci pola „temp”
- utwórz klasy o nazwach zgodnych z punktami menu. Ka¿da z tych klas powinna dziedziczyæ po klasie „Temperatura”
- w utworzonych klasach specjalistycznych zdefiniuj metody publiczne przeliczaj¹ce podan¹ temperaturê na dwie inne skale np.: klasa Celsjusz bêdzie posiada³a metody „c_k” i „c_f” przeliczaj¹ce odpowiednio temperaturê podana w stopniach Celsjusza na temperaturê w stopniach Kelvina i Fahrenheita
*/

#include <iostream>

using namespace std;

class Temperatura
{
public:
	void setTemp(float temp) {
		this->temp = temp;
	}
	float getTemp() {
		return this->temp;
	}

protected:
	float temp;
};

class Kalvin : public Temperatura
{
public:
	float k_f() {
		return (temp * 1.8) - 459.67;
	}
	float k_c() {
		return temp - 273.15;
	}
};

class Fahrenheit : public Temperatura
{
public:
	float f_k() {
		return (temp + 459.67) * 5 / 9;
	}
	float f_c() {
		return (temp - 32) / 1.8;
	}
};

class Celsjusz : public Temperatura
{
public:
	float c_k() {
		return temp + 273.15;
	}
	float c_f() {
		return (temp * 1.8) + 32;
	}
};

int main()
{
	cout << "Program przeliczajacy temperatury:" << endl;
	cout << "1. Kalvin" << endl;
	cout << "2. Fahrenheit" << endl;
	cout << "3. Celsjusz" << endl;
	cout << "-------" << endl;
	cout << "0. Koniec programu" << endl;

	int wybor = 1;
	while (wybor != 0)
	{
		cout << "\n Wybor: " << endl; 
		cin >> wybor;
		float temp;
		switch (wybor)
		{
		case 0:
			cout << "KONIEC";
			return 0;
		case 1:
			cout << "wybrano 1 - Kalvin" << endl;
			Kalvin kalvin;
			cout << "Podaj temperature w Kalvin`ach: ";
			cin >> temp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Podano bledne dane" << endl;
				break;
			}
			kalvin.setTemp(temp);
			cout << "Temperatura " << kalvin.getTemp() << " Kalvin = " << kalvin.k_c() << " Celsjusz, " << kalvin.k_f() << " Fahrenheit" << endl;
			break;
		case 2:
			cout << "wybrano 2 - Fahrenheit" << endl;
			Fahrenheit fahrenheit;
			cout << "Podaj temperature w fahrenheit`ach: ";
			cin >> temp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Podano bledne dane" << endl;
				break;
			}
			fahrenheit.setTemp(temp);
			cout << "Temperatura " << fahrenheit.getTemp() << " Fahrenheit = " << fahrenheit.f_c() << " Celsjusz, " << fahrenheit.f_k() << " Kalvin" << endl;
			break;
		case 3:
			cout << "wybrano 3 - Celsjusz" << endl;
			Celsjusz celsjusz;
			cout << "Podaj temperature w Celsjusz`ach: ";
			cin >> temp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Podano bledne dane" << endl;
				break;
			}
			celsjusz.setTemp(temp);
			cout << "Temperatura " << celsjusz.getTemp() << " Celsjusz = " << celsjusz.c_k() << " Kalvin, " << celsjusz.c_f() << " Fahrenheit" << endl;
			break;
		default:
			cout << "Dokonano blednego wyboru";
			break;
		}
	}

}

