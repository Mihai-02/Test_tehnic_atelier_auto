#include "Mecanic.h"

Mecanic::Mecanic(string name, string prename, Data nastere, Data angajare):Angajat(global_id, name, prename, nastere, angajare, 1.5){}

void Mecanic::afisare() const
{
    cout << "\n-----------------\nMecanic\n------------------\n";
    Angajat::afisare();
}