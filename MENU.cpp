#include "Atelier.h"
#include <iostream>


void remove_vehicles_time_passes(Atelier at)
{
    vector<Post>::iterator it;
    for(it=at.posturi.begin(); it!=at.posturi.end(); it++)
    {
        it->remove_masina();
        it->remove_autobuz();
        it->remove_camion();
    }
}

void MENU(Atelier at)
{
    char selection;

    do
    {
        cout << "1. Afisare nume atelier\n";
        cout << "2. Verificare status atelier\n";
        cout << "3. Afisare lista angajati\n";
        cout << "4. Afisare lista angajati extinsa\n";
        cout << "5. Adaugare angajat atelier\n";
        cout << "6. Client nou\n";
        cout << "7. Eliminare vehicule din coada(trecerea timpului)\n";
        cout << "8. Inchidere\n";

        cout << "\n\nIntroduceti o optiune(1-8):";
        cin >> selection;

        switch(selection)
        {
            case '1':
                cout << "\n=======================================\n\t\t";
                print_title();
                cout << "=======================================\n";
                break;
            case '2':
                if(at.is_open())
                    cout << "Atelierul este deschis\n";
                else
                    cout << "Atelierul nu este deschis\n";
                break;
            case '3':
                at.print_lista_angajati();
                break;
            case '4':
                at.print_full_info();
                break;
            case '5':
                at.adaugare_angajat();
                break;
            case '6':
                at.insert_new_vehicle();            //De facut caz angajat ocupat + schimbare angajat / plecare
                break;
            case '7':
                remove_vehicles_time_passes(at);    //NU MERGE
                break;
            case '8':
                cout << "La revedere!\n";
                break;

            default:
                cout << "Optiune invalida; va rugam alegeti o optiune din cele de mai sus\n";       
        }
    } while (selection!='8');

    return;
    
}