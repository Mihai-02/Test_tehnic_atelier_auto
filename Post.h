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
        bool add_masina();
        bool add_autobuz();
        bool add_camion();
        string get_nume_angajat(){return ang->get_nume_angajat();}
        inline void remove_masina(){if(masini.size()>0) masini.pop();}
        inline void remove_camion(){if(camioane.size()>0) camioane.pop();}
        inline void remove_autobuz(){if(autobuze.size()>0) autobuze.pop();}
        inline bool is_available_masina(){return (masini.size()<3);}
        inline bool is_available_camion(){return (camioane.size()<1);}
        inline bool is_available_autobuz(){return (autobuze.size()<1);}
};