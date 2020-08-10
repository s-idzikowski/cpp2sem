//Utwórz program realizuj¹cy funkcje wyznaczania teoretycznego czasu przebycia wyznaczonej trasy wiedz¹c, ¿e sposób pokonywania trasy ma wp³yw na prêdkoœæ poruszania(c(chód) - 4 km / h, r(rower) - 9 km / h, s(samochód) - 65 km / h)
//W ramach realizacji zadania utwórz klasê a w niej :
//*pole S(d³ugoœæ tracy)
//* pole t(czas przebycia trasy)
//* pole r(forma przebycia trasy(c, r, s))
//* odpowiednie metody dostêpowe do pól klasy
//* konstruktor jednoargumentowy, którego argumentem jest d³ugoœæ pokonywanej trasy, zaœ sposób jej pokonywania ustalony jest na c - chód
//* konstruktor dwyargumentowy, którego argumentem jest d³ugoœæ pokonywanej trasy oraz sposób jej pokonywania
//* metoda wyliczaj¹ca czas pokonania trasy
//
//Uwaga : dla u³atwienia przyjmujemy, ¿e tracê pokonujemy ze sta³¹ prêdkoœci¹ okreœlon¹ przez wybrany sposób pokonywania trasy

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