#include"temperatura i pochodne_lab5_GrabowskaEwelina.h"
#include<iostream>
#include<string>
using namespace std;


void Temperatura::setTemp(float T)
{
    this->temp = T;
}
float Temperatura::getTemp(float temp)
{
    return this->temp;
}

Kelvin::Kelvin(float temp, float k) : Temperatura()
{
    temp = k;
    float k_c();
    float k_f();

}
float Kelvin::k_f(float k, float f)
{
    f = (k - 273, 15) * 1.800 + 32.000;
    return f;

}
float Kelvin::k_c(float k, float c)
{
    c = k - 273.150;
    return c;
}

Fahrenheit::Fahrenheit(float temp, float f) : Temperatura()
{

    temp = f;
    float f_k();
    float f_c();

}
float Fahrenheit::f_k(float f, float k)
{

    k = (f - 32.000) / 1.800 + 273.150;
    return k;

}
float Fahrenheit::f_c(float f, float c)
{
    c = (f - 32.000) / 1.800;
    return c;
}

Celsjusz::Celsjusz(float temp, float c) : Temperatura()
{
    temp = c;

    float c_k();
    float c_f();

}
float Celsjusz::c_k(float c, float k)
{
    k = c + 273.150;
    return k;
}
float Celsjusz::c_f(float c, float f)
{
    f = c * 1.800 + 32.000;
    return f;
}