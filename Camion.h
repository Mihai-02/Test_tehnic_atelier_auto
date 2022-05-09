#pragma once
#include "Masina.h"

class Camion: public Masina
{
    int tonaj;
    public:
        Camion(int id, int kil, int an, bool dis, int tons):Masina(id, kil, an, dis),tonaj(tons){if(tonaj<0) tonaj=0;}
        Camion(){tonaj=0;}
        float valoare_asigurare(bool);
        friend ostream& operator<<(ostream&, const Camion&);
        friend istream& operator>>(istream&, Camion&);
};