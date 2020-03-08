#include<iostream>
#include<conio.h>
#include<fstream>


using namespace std;

struct cos
{
       int id;
       char nazwa[20];
};
cos zm;

void zapis(char *, cos *);
void odczyt_p(char *, cos *, int);
void odczyt(char *, cos *);

int main()
{
    zapis("plik.dat", &zm);
    int rekord=0; cout<<"Ktory rekord: "; cin>>rekord;
    //odczyt_p("plik.dat",&zm, rekord);
    odczyt("plik.dat",&zm);
    getch();
    return 0;
}

void zapis(char * p, cos *r)
{
     cout<<"Podaj id: ";
     cin>>r->id;
     cout<<"Podaj nazwe: ";
     cin>>r->nazwa;
     
     ofstream z;
     z.open(p, ios::binary | ios_base::app);
     z.write((char*)r, sizeof(*r));
     z.close();
}

void odczyt_p(char *p, cos *r, int k)
{
     ifstream z(p, ios_base::binary );
     int ktory =(k-1)*sizeof(*r);
     z.seekg(ktory);
     z.read((char*)r, sizeof(*r));
     cout<<r->id<<" - "<<r->nazwa<<"\n";
     z.close();
}

void odczyt(char *p, cos *r)
{
     ifstream z(p, ios_base::binary );
     z.seekg(0,ios::end );
     int dl = z.tellg();
       
     int ktory =0;
     z.seekg(ktory);
     
    while(ktory<dl)/*!z.fail()*/{
         z.read((char*)r, sizeof(*r));
         cout<<r->id<<" - "<<r->nazwa<<"\n";
         ktory +=sizeof(*r);
        z.seekg(ktory);
    }
     z.close();
}
