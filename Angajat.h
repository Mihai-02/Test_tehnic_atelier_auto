#pragma once
#include "Data.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

static int global_id=0;

class Angajat
{
    int ID;
    string nume;
    string prenume;
    Data data_nasterii;
    Data data_angajarii;
    float coef_salariat;

    public:
        Angajat(int, string, string, Data, Data, float);
        virtual void afisare() const;
        float get_salariu();
        int get_vechime();
        friend void modificare_angajat(vector<Angajat*>);
        friend float calcul_salariu(vector<Angajat*>);

};