#include "Director.h"

Director::Director(string name, string prename, Data nastere, Data angajare):Angajat(global_id, name, prename, nastere, angajare, 2){}

void Director::afisare() const
{
    cout << "\n------------------\nDirector\n------------------\n";
    Angajat::afisare();
}