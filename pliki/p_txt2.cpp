#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

struct paragon
{
   int lp;
   char ntowar[20];
   float cena;
   float ilosc;
}zm;

void zapis(char[], paragon);
void odczyt(char[]);

int main()
{
   /* cout<<"Podaj lp: "; cin>>zm.lp;
    cout<<"Podaj nazwe towaru: "; cin>>zm.ntowar;
    cout<<"Podaj cene towaru: "; cin>>zm.cena;
    cout<<"Podaj ilosci towaru: "; cin>>zm.ilosc;
    zapis("towar1.txt", zm);*/
    odczyt("towar.txt");
    getch();
    return 0;
}

void zapis(char plik[], paragon t){
   ofstream p;
   p.open(plik, ios_base::app | ios::out);
   p<<t.lp<<" "<<t.ntowar<<": "<<t.cena<<" zl x "<<t.ilosc<<"\n";
   p.close();
}

void odczyt(char plik[]){
   ifstream p(plik);
   string linia;
   if (p.is_open()){
      while(!p.eof()){
         getline(p, linia);
         cout<<linia<<"\n";
      }
   }
   else
   {
       cerr<<"Brak pliku";
   }
   p.close();
}






