#include "Camion.h"

float Camion::valoare_asigurare(bool discount)
{
    int vechime = Masina::calc_vechime();

    float valoare = 300*vechime + 700*(kilometri>800000 ? 1 : 0);

    if(discount==1)
        return 0.85*valoare;
    else
        return valoare;
}

ostream& operator<<(ostream& dev, const Camion& cam)
{
    cout << (Masina)cam;
    dev << "Tonaj: " << cam.tonaj << "\n";

    return dev;
}
