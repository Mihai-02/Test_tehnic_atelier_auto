#include "Asistent.h"
#include "Director.h"
#include "Mecanic.h"
#include "Standard.h"
#include "Autobuz.h"
#include "Camion.h"
#include "Functii_Angajati.h"
#include "Atelier.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


int main()
{
    /* vector<Angajat*> angajati;

    angajati=adaugare_angajat(angajati);
    angajati=adaugare_angajat(angajati);
    angajati=adaugare_angajat(angajati);

    modificare_angajat(angajati);

    vector<Angajat*>::iterator it;
    for(it=angajati.begin(); it!=angajati.end(); it++)
        (*it)->afisare(); */

    
    Atelier at;
    at.give_name();

    at.print_info();

    



   /*  Standard sta(123, 123456, 2015, 0, "Manual");
    Autobuz aut(456, 102555, 2000, 1, 40);
    Camion cam(789, 1234560, 1995, 1, 5);

    cout << sta << "\n" << sta.valoare_asigurare(0);
    cout << aut << "\n" << aut.valoare_asigurare(0);
    cout << cam << "\n" << cam.valoare_asigurare(1);

    Data d1(2, 1, 2312), d11(12, 22, 2222);
    Data d2(2, 1, 2000), d22(12, 22, 2);
    Data d3(2, 1, 2777), d33(12, 22, 45);
    
    Mecanic mec("Marcel", "Marcel", d1, d11);
    Director dir("Marc", "Mark", d2, d22);
    Asistent asis("Markkill", "Markkil", d3, d33);

    mec.afisare();
    dir.afisare();
    asis.afisare(); */
 
    return 0;
}