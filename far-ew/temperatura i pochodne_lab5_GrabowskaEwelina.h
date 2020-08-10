#pragma once // header
class Temperatura {
protected:
    float temp;
public:
    void setTemp(float T);
    float getTemp(float temp);
};
class Kelvin : public Temperatura {

public:
    float k;
    Kelvin(float temp, float k);
    float k_f(float k, float f);
    float k_c(float k, float c);
};
class Fahrenheit : public Temperatura {
public:
    float f;
    Fahrenheit(float temp, float f);
    float f_k(float f, float k);
    float f_c(float f, float c);

};
class Celsjusz : public Temperatura {
public:
    float c;
    Celsjusz(float temp, float c);
    float c_k(float c, float k);
    float c_f(float c, float f);


};
