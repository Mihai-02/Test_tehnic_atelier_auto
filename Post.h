#include <queue>
#include "Angajat.h"
#include "Asistent.h"
#include "Mecanic.h"
#include "Director.h"
#include "Standard.h"
#include "Autobuz.h"
#include "Camion.h"

class Post
{
    Angajat* ang;
    queue<Standard> masini;
    queue<Autobuz> autobuze;
    queue<Camion> camioane;
    unsigned short max_masini=3, max_bus_camion=1;

    public:
        Post(string, string, Data, Data, const string);
        void print_info() const;
        void print_full();
        void add_masina();
        void add_autobuz();
        void add_camion();
        string get_nume_angajat(){return ang->get_nume_angajat();}
        inline void remove_masina(){masini.pop();}
        inline void remove_camion(){camioane.pop();}
        inline void remove_autobuz(){autobuze.pop();}
};