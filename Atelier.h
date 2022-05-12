#include "Post.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Atelier
{
    string nume;
    vector<Post> posturi;

    public:
        Atelier(string name={}){nume=name;}
        inline void give_title(){cout << "Introduceti un nume pentru atelier: "; getline(cin, nume);}
        inline void print_title() const {cout <<nume<< "\n";}
        void adaugare_angajat();
        inline bool is_open() const {return (posturi.size() > 0);}
        void print_lista_angajati();
        void print_full_info();
        bool insert_new_vehicle();   //Returneaza 1 daca vehiculul e adaugat cu succes si 0 in caz contrar
        friend void remove_vehicles_time_passes(Atelier);
};