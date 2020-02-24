/*
Utwórz program za pomoc¹ jêzyka C/C++ , który realizowa³ bêdzie zadanie obrane za pomoc¹ menu u¿ytkownika:
A: Wprowadzanie informacji o p³ytach
B: Szukanie:
1.       Wszystkich danych
2.       Wyœwietlenie wszystkich p³yt podanego zespo³u
3.       Wyœwietlenie wszystkich p³yt z podanego roku
C: Wyjœcie
Uwaga:
				- struktura sk³ada siê z pól: id_Plyty, Tytul, Zespol, Rok, Cena
*/
#include<iostream>

using namespace std;

struct Plyta
{
	int Id_plyty;
	char Tytul[30];
	char Zespol[30];
	int Rok;
	float Cena;
};

int licznik_plyt = 0;
Plyta plyty[50];

void menu();
void wprowadz(Plyta plyty[]);
void wyszukajMenu();
void wyswietl(Plyta plyty[]);
void wyswietl(Plyta plyty[], char zespol[]);
void wyswietl(Plyta plyty[], int rok);

int main()
{
	menu();
}

void menu() 
{
start:
	cout << "---------------------------------\n";
	cout << "---- Menu glowne -----\n";
	cout << "1 - Wprowadz informacje o plytach\n";
	cout << "2 - Wyszukaj\n";
	cout << "3 - Wyjdz\n";
	cout << "---------\n";
	cout << "--> ";

	int wybor;
	cin >> wybor;
	if (cin.fail()) {
		system("cls");
		cout << "*****************************\n";
		cout << "Wprowadzono niepoprawne dane!\n";
		cout << "*****************************\n";
		cin.clear();
		cin.ignore(100, '\n');
		goto start;
	}

	switch (wybor)
	{
	case 1:
		cout << "Wprowadzono " << licznik_plyt << "/50 plyt" << endl;
		if (licznik_plyt >= 50)
		{
			cout << "Mozna dodac maksymalnie " << licznik_plyt << " plyt" << endl;
			goto start;
		}
		wprowadz(plyty);
		goto start;
	case 2:
		wyszukajMenu();
		goto start;
	case 3:
		cout << "Wybrano 3 - Zakonczenie programu" << endl;
		return;
	default:
		system("cls");
		cout << "*************************\n";
		cout << "Dokonano blednego wyboru!\n";
		cout << "*************************\n";
		goto start;
		break;
	}
}

void wprowadz(Plyta plyty[])
{
	cout << "Podaj Id plyty: "; cin >> plyty[licznik_plyt].Id_plyty;
	cout << "Podaj tytul plyty: "; cin >> plyty[licznik_plyt].Tytul;
	cout << "Podaj Zespol plyty: "; cin >> plyty[licznik_plyt].Zespol;
	cout << "Podaj Rok: "; cin >> plyty[licznik_plyt].Rok;
	cout << "Podaj Cene: "; cin >> plyty[licznik_plyt].Cena;
	licznik_plyt++;
}

void wyszukajMenu()
{
start:
	cout << "---------------------------------\n";
	cout << "---- Wyszukaj -----\n";
	cout << "1 - Wyswietl wszystkie dane\n";
	cout << "2 - Wyswietl plyty z podanego zespolu\n";
	cout << "3 - Wyswietl plyty z podanego roku\n";
	cout << "0 - Powrot do menu glownego\n";
	cout << "---------\n";
	cout << "--> ";

	int wybor;
	cin >> wybor;
	if (cin.fail()) {
		system("cls");
		cout << "*****************************\n";
		cout << "Wprowadzono niepoprawne dane!\n";
		cout << "*****************************\n";
		cin.clear();
		cin.ignore(100, '\n');
		goto start;
	}

	switch (wybor)
	{
		case 1:
			wyswietl(plyty);
			goto start;
		case 2:
			char tytul[30];
			cout << "Wprowadz zespol > "; cin >> tytul;
			wyswietl(plyty, tytul);
			goto start;
		case 3:
			int rok;
			cout << "Wprowadz rok > "; cin >> rok;
			wyswietl(plyty, rok);
			goto start;
		case 0:
			system("cls");
			return;
		default:
		system("cls");
		cout << "*************************\n";
		cout << "Dokonano blednego wyboru!\n";
		cout << "*************************\n";
		goto start;
		break;
	}
}

void wyswietl(Plyta plyty[])
{
	if (licznik_plyt == 0)
	{
		system("cls");
		cout << "***************************\n";
		cout << "Brak danych do wyswietlenia\n";
		cout << "***************************\n";
		return;
	}
	for (int i = 0; i < licznik_plyt; i++)
	{
		cout << "Id -> " << plyty[i].Id_plyty << endl;
		cout << "Tytul -> " << plyty[i].Tytul << endl;
		cout << "Zespol -> " << plyty[i].Zespol << endl;
		cout << "Rok -> " << plyty[i].Rok << endl;
		cout << "Cena -> " << plyty[i].Cena << endl << endl;
	}
}

void wyswietl(Plyta plyty[], char zespol[])
{
	bool flaga = false;
	for (int i = 0; i < licznik_plyt; i++)
	{
		if (!strcmp(plyty[i].Zespol, zespol))
		{
			flaga = true;
			cout << "Id -> " << plyty[i].Id_plyty << endl;
			cout << "Tytul -> " << plyty[i].Tytul << endl;
			cout << "Zespol -> " << plyty[i].Zespol << endl;
			cout << "Rok -> " << plyty[i].Rok << endl;
			cout << "Cena -> " << plyty[i].Cena << endl << endl;
		}
	}
	if (!flaga)
	{
		{
			system("cls");
			cout << "***************************\n";
			cout << "Brak danych do wyswietlenia\n";
			cout << "***************************\n";
		}
	}
}

void wyswietl(Plyta plyty[], int rok)
{
	bool flaga = false;
	for (int i = 0; i < licznik_plyt; i++)
	{
		if (plyty[i].Rok == rok)
		{
			flaga = true;
			cout << "Id -> " << plyty[i].Id_plyty << endl;
			cout << "Tytul -> " << plyty[i].Tytul << endl;
			cout << "Zespol -> " << plyty[i].Zespol << endl;
			cout << "Rok -> " << plyty[i].Rok << endl;
			cout << "Cena -> " << plyty[i].Cena << endl << endl;
		}
	}
	if (!flaga)
	{
		{
			system("cls");
			cout << "***************************\n";
			cout << "Brak danych do wyswietlenia\n";
			cout << "***************************\n";
		}
	}
}