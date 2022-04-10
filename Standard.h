#include <string>
#include "Masina.h"

using namespace std;

class Standard: public Masina
{
    string transmisie;
    public:
        Standard(int id, int kil, int an, bool dis, string tra):Masina(id, kil, an, dis),transmisie(tra){}
        float valoare_asigurare(bool);
        friend ostream& operator<<(ostream&, const Standard&);
};