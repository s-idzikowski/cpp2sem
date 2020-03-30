#include <iostream>
#include <string>

using namespace std;

class Silnik
{
public:

	Silnik(int pojemnosc, string producent) {
		this->pojemnosc = pojemnosc;
		this->producent = producent;
	}

	string getProducent() {
		return producent;
	}

	string toString() {
		return " SILNIK: producent - " + producent + " pojemnosc - " + to_string(pojemnosc);
	}

private:
	int pojemnosc;
	string producent;
};

class Urzadzenie
{
public:

	Urzadzenie(int obroty, Silnik silnik) : obroty(obroty), silnik(silnik) {}

	string getProducent() {
		return producent;
	}

	Silnik getSilnik() {
		return this->silnik;
	}

	string toString() {
		return "URZADZENIE: producent - " + producent + " obroty - " + to_string(obroty) + " ____ " + silnik.toString();
	}
private:
	const string producent = "BOSCH";
	int obroty;
	Silnik silnik;
};

int const ilosc = 6;
string zwroc(Urzadzenie tab[]);

int main() {
	Urzadzenie x();
	Urzadzenie tab[ilosc] = {
		Urzadzenie(1000, Silnik(600, "BOSCH")),
		Urzadzenie(2000, Silnik(1200, "INNY")),
		Urzadzenie(3000, Silnik(1500, "BOSCH")),
		Urzadzenie(4000, Silnik(1800, "BOSCH")),
		Urzadzenie(5000, Silnik(2500, "JAKIS")),
		Urzadzenie(6000, Silnik(3000, "BOSCH")),
	};

	cout << zwroc(tab);

}

string zwroc(Urzadzenie tab[]) {

	string wyswietl = "";
	
	for (int i = 0; i < ilosc; i++)
	{
		if (tab[i].getProducent() == tab[i].getSilnik().getProducent())
		{
			wyswietl += "Poz nr "+to_string(i+1) + ": " +tab[i].toString() + "\n";
		}
	}

	return wyswietl;
}