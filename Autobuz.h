#include "Masina.h"

class Autobuz: public Masina
{
    unsigned int nr_locuri;
    public:
        Autobuz(int id, int kil, int an, bool dis, unsigned int  loc):Masina(id, kil, an, dis),nr_locuri(loc){}
        float valoare_asigurare(bool);
        friend ostream& operator<<(ostream&, const Autobuz&);
};