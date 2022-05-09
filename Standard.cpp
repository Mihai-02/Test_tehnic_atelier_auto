#include "Standard.h"

float Standard::valoare_asigurare(bool discount)
{
    int vechime = Masina::calc_vechime();

    float valoare = 100*vechime + 500*diesel + 500*(kilometri>200000 ? 1 : 0);

    if(discount==1)
        return 0.95*valoare;
    else
        return valoare;
}

ostream& operator<<(ostream& dev, const Standard& sta)
{
    cout << (Masina)sta;
    dev << "Transmisie: " << sta.transmisie << "\n";

    return dev;
}

istream& operator>>(istream& dev, Standard& sta)
{
    dev>>(Masina&)sta;
    do
    {
        cout << "Transmisie:";
        dev >> sta.transmisie;
    } while (sta.transmisie!="Manual" && sta.transmisie!="Automat");
}
