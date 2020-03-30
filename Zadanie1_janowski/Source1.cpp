//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Silnik
//{
//public:
//	Silnik();
//
//	Silnik(int pojemnosc, string producent) {
//		this->pojemnosc = pojemnosc;
//		this->producent = producent;
//	}
//	int getPojemnosc() {
//		return pojemnosc;
//	}
//	string getProducent() {
//		return producent;
//	}
//
//private:
//	int pojemnosc;
//	string producent;
//};
//
//class Urzadzenie
//{
//public:
//	Urzadzenie();
//
//	Urzadzenie(int obroty, Silnik* silnik) {
//		this->obroty = obroty;
//		this->silnik = silnik;
//	}
//
//	string getProducent() {
//		return producent;
//	}
//	int getObroty() {
//		return obroty;
//	}
//	Silnik* getSilnik() {
//		return this->silnik;
//	}
//private:
//	const string producent = "BOSCH";
//	int obroty = 0;
//	Silnik* silnik;
//};
//
//int const ilosc = 6;
//string zwroc(Urzadzenie* tab[ilosc]);
//
//int main() {
//
//	Urzadzenie* tab[ilosc] = {
//		new Urzadzenie(3232, new Silnik(123, "BOSCH")),
//		new Urzadzenie(53242, new Silnik(234, "INNY")),
//		new Urzadzenie(2342, new Silnik(345, "BOSCH")),
//		new Urzadzenie(1231, new Silnik(432, "BOSCH")),
//		new Urzadzenie(42342, new Silnik(3232, "JAKIS")),
//		new Urzadzenie(6456, new Silnik(32131, "BOSCH")),
//	};
//
//	cout << zwroc(tab);
//}
//
//string zwroc(Urzadzenie* tab[ilosc]) {
//
//	string wyswietl = "";
//
//	for (int i = 0; i < ilosc; i++)
//	{
//		if (tab[i]->getProducent() == tab[i]->getSilnik()->getProducent())
//		{
//			wyswietl += "URZADZENIE nr: " + to_string(i + 1) + " : Producent - " + tab[i]->getProducent() + " Obroty: " + to_string(tab[i]->getObroty()) + " SILNIK producent: " + tab[i]->getSilnik()->getProducent() + " pojemnosc: " + to_string(tab[i]->getSilnik()->getPojemnosc()) + "\n";
//		}
//	}
//
//	return wyswietl;
//}