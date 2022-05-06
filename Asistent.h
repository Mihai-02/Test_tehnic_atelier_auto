#pragma once

#include "Angajat.h"

class Asistent: public Angajat
{
    public:
        Asistent(string, string, Data, Data);
        void afisare() const;
};