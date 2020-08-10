//Utwórz program realizuj¹cy zadanie wyliczenia pola powierzchni ca³kowitej i objêtoœci bry³y wskazanej z menu u¿ytkownika.
//
//Menu
//1. Szeœcian
//2. Ostros³up o podstawie kwadratu
//3. Walec
//4. Kula
//5. Graniastos³up prawid³owy o podstawie trójk¹ta
//
//W ramach realizacji zadania utwórz :
//*klasê abstrakcyjn¹ "Bry³a" zawieraj¹ca metody wirtualne "Objetosc" i "PCalkowite"
//* klasy specjalistyczne dziedzicz¹ce po klasie "Bryla" zawieraj¹ce definicje odpowiednich pól jak i implementacje metod odziedziczonych, a tak¿e ewentualne inne metody(metody dostêpowe do pól, metody wyliczaj¹ce pole powierzchni boku i podstawy je¿eli ich definicja jest uzasadniona)
#define _USE_MATH_DEFINES
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

class Ostroslup : public Bryla {
private:
	float krawedzPodstawy;
	float wysokoscOstroslupa;
	float wysokoscScianyBocznej;
public:
	Ostroslup(float krawedzPodstawy, float wysokoscOstroslupa) {
		this->krawedzPodstawy = krawedzPodstawy;
		this->wysokoscOstroslupa = wysokoscOstroslupa;
		this->wysokoscScianyBocznej = sqrtf(pow(0.5 * krawedzPodstawy, 2) + pow(wysokoscOstroslupa, 2));
	}
	float Objetosc() {
		return 1.0 / 3 * pow(krawedzPodstawy,2) * wysokoscOstroslupa;
	}
	float PCalkowite() {
		return pow(krawedzPodstawy, 2) + 2 * krawedzPodstawy * wysokoscScianyBocznej;
	}
};

class Walec : public Bryla {
private:
	float promienPodstawy;
	float wysokoscWalca;
public:
	Walec(float promienPodstawy, float wysokoscWalca) {
		this->promienPodstawy = promienPodstawy;
		this->wysokoscWalca = wysokoscWalca;
	}
	float Objetosc() {
		return M_PI * pow(promienPodstawy, 2) * wysokoscWalca;
	};
	float PCalkowite() {
		return 2 * M_PI * promienPodstawy * (promienPodstawy + wysokoscWalca);
	};
};

class Kula : public Bryla {
private:
	float promienKuli;
public:
	Kula(float promienKuli) {
		this->promienKuli = promienKuli;
	}
	float Objetosc() {
		return 4.0 / 3 * M_PI * pow(promienKuli, 3);
	};
	float PCalkowite() {
		return 4 * M_PI * pow(promienKuli, 2);
	};
};

class Graniastoslup : public Bryla {
private:
	float krawedzPodstawy;
	float wysokoscGraniastoslupa;
public:
	Graniastoslup(float krawedzPodstawy, float wysokoscGraniastoslupa) {
		this->krawedzPodstawy = krawedzPodstawy;
		this->wysokoscGraniastoslupa = wysokoscGraniastoslupa;
	}
	float Objetosc() {
		return (pow(krawedzPodstawy, 2) * sqrtf(3)) / 4 * wysokoscGraniastoslupa;
	};
	float PCalkowite() {
		return (pow(krawedzPodstawy, 2) * sqrtf(3) + 6 * krawedzPodstawy * wysokoscGraniastoslupa) / 2;
	};
};

int main() {
	Bryla* bryla;
	
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
		}

		switch (wybor)
		{
		case 1:
			{
				cout << "wybrano 1 - Szescian\n";
				cout << "Podaj dlugosc boku szesciana: ";
				float dlugoscBoku;
				cin >> dlugoscBoku;
				Szescian szescian(dlugoscBoku);
				bryla = &szescian;
				cout << "Objetosc wybranej bryly to: " << bryla->Objetosc() << endl;
				cout << "Pole Calkowite wybranej bryly to: " << bryla->PCalkowite() << endl;
			}
			break;
		case 2:
			{
				cout << "wybrano 2 - Ostroslup o podstawie kwadratu\n";
				cout << "Podaj dlugosc krawedzi podstawy: ";
				float dlugoscKrawedzi;
				cin >> dlugoscKrawedzi;
				cout << "Podaj wysokosc ostroslupa: ";
				float wysokoscOstroslupa;
				cin >> wysokoscOstroslupa;
				Ostroslup ostroslup(dlugoscKrawedzi, wysokoscOstroslupa);

				bryla = &ostroslup;
				cout << "Objetosc wybranej bryly to: " << bryla->Objetosc() << endl;
				cout << "Pole Calkowite wybranej bryly to: " << bryla->PCalkowite() << endl;
			}
			break;
		case 3:
			{
				cout << "wybrano 3 - Walec\n";
				cout << "Podaj promien podstawy walca: ";
				float promienPodstawy;
				cin >> promienPodstawy;
				cout << "Podaj wysokosc walca: ";
				float wysokoscWalca;
				cin >> wysokoscWalca;
				Walec walec(promienPodstawy, wysokoscWalca);

				bryla = &walec;
				cout << "Objetosc wybranej bryly to: " << bryla->Objetosc() << endl;
				cout << "Pole Calkowite wybranej bryly to: " << bryla->PCalkowite() << endl;
			}
			break;
		case 4:
			{
				cout << "wybrano 4 - Kula\n";
				cout << "Podaj promien kuli: ";
				float promienKuli;
				cin >> promienKuli;

				Kula kula(promienKuli);

				bryla = &kula;
				cout << "Objetosc wybranej bryly to: " << bryla->Objetosc() << endl;
				cout << "Pole Calkowite wybranej bryly to: " << bryla->PCalkowite() << endl;
			}
			break;
		case 5:
		{
			cout << "wybrano 5 - Graniastoslup\n";
			cout << "Podaj krawedz postawy: ";
			float krawedzPodstawy;
			cin >> krawedzPodstawy;
			cout << "Podaj wysokosc graniastoslupa: ";
			float wysokosc;
			cin >> wysokosc;

			Graniastoslup graniastoslup(krawedzPodstawy, wysokosc);

			bryla = &graniastoslup;
			cout << "Objetosc wybranej bryly to: " << bryla->Objetosc() << endl;
			cout << "Pole Calkowite wybranej bryly to: " << bryla->PCalkowite() << endl;
		}
			break;
		default:
			cout << "Bledny wybor";
			break;
		}
	} while (true);
	

	return 0;
}