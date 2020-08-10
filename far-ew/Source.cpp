#include<iostream>
using namespace std;

class Temperatura {
protected:
    float temp;
public:
    void setTemp(float temp) {
        this->temp = temp;
    }
    float getTemp() {
        return this->temp;
    }

};

class Kelvin : public Temperatura {
public:
    float k_f()
    {
        return (temp * 1.8) - 459.67;

    }
    float k_c()
    {
        return temp - 273.15;
    }
};

class Fahrenheit : public Temperatura {
public:
    float f_k()
    {

        return (temp + 459.67) * 5 / 9;

    }
    float f_c()
    {
        return (temp - 32.00) / 1.8;

    }
};
class Celsjusz : public Temperatura {
public:

    float c_k()
    {
        return temp + 273.15;
    }
    float c_f()
    {
        return (temp * 1.8) + 32;
    }
};

int main()
{
    char znak_K_F_C;
    int menu = 1;
    while (menu != 0) {
        cout << "-----------MENU------------" << endl;
        cout << "-Wybierz skale temperatury-" << endl;
        cout << "-1.--------Kelvin----------" << endl;
        cout << "-2.-------Fahrenheit-------" << endl;
        cout << "-3.------ Celsjusz---------" << endl;
        cin >> menu;
        float temp;
        switch (menu) {
        case 1:
            cout << "Podaj wartosc temperatury w Kelvinach ";
            cin >> temp;
            Kelvin kelvin;
            kelvin.setTemp(temp); 
            cout << " Wybierz docelowa skale temperatury. " << endl << " 'K' - Kelvin (ponowne wyswietlenie), 'F' - Fahrenheit, 'C' - Celsjusz. " << endl;
            cin >> znak_K_F_C;
            
                if (znak_K_F_C == 'K')
                {
                    cout << "Juz wybrales skale Kalwina. Wcisnij F lub C, aby dokonac konwersji na inna skale";

                }
                else if (znak_K_F_C == 'F')
                {
                    cout << kelvin.getTemp() << " stopni K to " << kelvin.k_f() << " Fahrenheitow" << endl;
                }
                else if (znak_K_F_C == 'C')
                {
                    cout << kelvin.getTemp() << " stopni K to " << kelvin.k_c() << " Celsjuszy" << endl;
                }
            
                break;
        case 2:
            cout << "Podaj wartosc temperatury w Fahrenheitach ";
            cin >> temp;
            Fahrenheit fahrenheit;
            fahrenheit.setTemp(temp);
            cout << " Wybierz docelowa skale temperatury. " << endl << " 'K' - Kelvin, 'F' - Fahrenheit (ponowne wyswietlenie), 'C' - Celsjusz. " << endl;
            cin >> znak_K_F_C;
            
                if (znak_K_F_C == 'K')
                {
                    cout << fahrenheit.getTemp() << " stopni F to " << fahrenheit.f_k() << " Kelvinów" << endl;
                }
                else if (znak_K_F_C == 'F')
                {
                    cout << "Juz wybrales skale Fahrenheita. Wcisnij K lub C, aby dokonac konwersji na inna skale";
                }
                else if (znak_K_F_C == 'C')
                {
                    cout << fahrenheit.getTemp() << " stopni F to " << fahrenheit.f_c() << " Celsjuszy" << endl;

                }
                break;
        case 3:
            cout << "Podaj wartosc temperatury w Celsjuszach ";
            cin >> temp;
            Celsjusz celsjusz;
            celsjusz.setTemp(temp);
            cout << " Wybierz docelowa skale temperatury: " << endl << " 'K' - Kelvin, 'F' - Fahrenheit, 'C' - Celsjusz (ponowne wyswietlenie). " << endl;
            cin >> znak_K_F_C;

            
                if (znak_K_F_C == 'K')
                {
                    cout << celsjusz.getTemp() << " stopni C to " << celsjusz.c_k() << " Kelwinow" << endl;
                }
                else if (znak_K_F_C == 'F')
                {
                    cout << celsjusz.getTemp() << " stopni C to " << celsjusz.c_f() << " Fahrenheitow" << endl;

                }
                else if (znak_K_F_C == 'C')
                {
                    cout << "Juz wybrales skale Celsjusza. Wcisnij K lub F, aby dokonac konwersji na inna skale";

                }
                break;
        
        default:
            cout << "bledny wybor";
            return 0;

        }
    }
}