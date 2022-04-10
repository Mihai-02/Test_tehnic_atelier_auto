#include "Angajat.h"

class Director: public Angajat
{
    public:
        Director(string, string, Data, Data);
        void afisare() const;
};