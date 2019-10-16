#include <iostream>

using namespace std;

class wynik
{
public:
    wynik(int N)
    {
        length = N;
        dane = new float[N];
        ilosc_elementow = 0;
    }
    int ilosc()
    {
        return ilosc_elementow;
    }
    void wydrukuj()
    {
        for(int i = 0; i < ilosc(); ++i)
        {
            cout << dane[i] << endl;
        }
        cout << "Ilosc: " << ilosc() << endl;
    }
    int dodaj(float liczba);
    int usun();
private:
    float *dane;
    int length;
    int ilosc_elementow;
};

int wynik::dodaj(float liczba)
    {
        if(ilosc_elementow >= length) {
            cout << "Out of bounds" << endl;
            return 1;
        }
        cout << "Dodano: " << liczba << " na pozycji " << ilosc_elementow << endl;
        dane[ilosc_elementow] = liczba;
        ilosc_elementow++;
        return 0;
    }
int wynik::usun()
    {
        if(ilosc_elementow <= 0) {
            cout << "Out of bounds" << endl;
            return 1;
        }
        cout << "Usunieto pozycje " << ilosc_elementow << endl;
        dane[ilosc_elementow] = '\0';
        ilosc_elementow--;
        return 0;
    }

int main()
{
    int i = 0;

    wynik wyniki(20);

    while(wyniki.dodaj((float)(3.61279346*(i+1))) != 1) i++;

    wyniki.wydrukuj();

    while(wyniki.usun() != 1);

    wyniki.wydrukuj();

    return 0;
}
