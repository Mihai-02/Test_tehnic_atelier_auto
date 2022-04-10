#include "Autobuz.h"

float Autobuz::valoare_asigurare(bool discount)
{
    int vechime = Masina::calc_vechime();

    float valoare = 200*vechime + 1000*diesel + 500*(kilometri>200000 ? 2 : kilometri>100000 ? 1 : 0);

    if(discount==1)
        return 0.9*valoare;
    else
        return valoare;
}

ostream& operator<<(ostream& dev, const Autobuz& aut)
{
    cout << (Masina)aut;
    dev << "Numar locuri: " << aut.nr_locuri << "\n";

    return dev;
}
