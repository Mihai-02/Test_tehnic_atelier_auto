#include "Asistent.h"

Asistent::Asistent(string name, string prename, Data nastere, Data angajare):Angajat(global_id, name, prename, nastere, angajare, 1){}

void Asistent::afisare() const
{
    cout << "\n------------------\nAsistent\n------------------\n";
    Angajat::afisare();
}