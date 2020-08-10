//Utw�rz program realizuj�cy funkcje wyznaczania teoretycznego czasu przebycia wyznaczonej trasy wiedz�c, �e spos�b pokonywania trasy ma wp�yw na pr�dko�� poruszania(c(ch�d) - 4 km / h, r(rower) - 9 km / h, s(samoch�d) - 65 km / h)
//W ramach realizacji zadania utw�rz klas� a w niej :
//*pole S(d�ugo�� tracy)
//* pole t(czas przebycia trasy)
//* pole r(forma przebycia trasy(c, r, s))
//* odpowiednie metody dost�powe do p�l klasy
//* konstruktor jednoargumentowy, kt�rego argumentem jest d�ugo�� pokonywanej trasy, za� spos�b jej pokonywania ustalony jest na c - ch�d
//* konstruktor dwyargumentowy, kt�rego argumentem jest d�ugo�� pokonywanej trasy oraz spos�b jej pokonywania
//* metoda wyliczaj�ca czas pokonania trasy
//
//Uwaga : dla u�atwienia przyjmujemy, �e trac� pokonujemy ze sta�� pr�dko�ci� okre�lon� przez wybrany spos�b pokonywania trasy

#include <iostream>

using namespace std;

class Czas
{
private:
	float s; //dlugosc
	float t; //czas
	char r; // forma przebycia c-chod, r-rower, s, samochod
	void setT(float s, char r) {
		if (r == 'c') {
			this->t = s / 4.0;
		}
		if (r == 'r') {
			this->t = s / 9.0;
		}
		if (r == 's') {
			this->t = s / 65.0;
		}
	}
public:
	Czas(float s) {
		this->s = s;
		this->r = 'c';
	}
	Czas(float s, char r) {
		this-> s = s;
		this->r = r;
	}
	float getT() {
		setT(this->s, this->r);
		return this->t;
	}
};


int main() {

	//sprawdzenie
	Czas czas1(100);
	cout << "Konstruktor 1 parametrowy -- Czas pokonania 100 to: " << czas1.getT() << endl;

	Czas czas2_1(100, 'c');
	cout << "Konstruktor 2 parametrowy -- Czas pokonania 100 dla chodu to: " << czas2_1.getT() << endl;

	Czas czas2_2(100, 'r');
	cout << "Konstruktor 2 parametrowy -- Czas pokonania 100 dla roweru to: " << czas2_2.getT() << endl;

	Czas czas2_3(100, 's');
	cout << "Konstruktor 2 parametrowy -- Czas pokonania 100 dla samochodu to: " << czas2_3.getT() << endl;

	return 0;
}