#include <queue>
#include "Angajat.h"
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
        Post(const Angajat);
};