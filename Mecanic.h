#include "Angajat.h"

class Mecanic: public Angajat
{
    public:
        Mecanic(string, string, Data, Data);
        void afisare() const;
};