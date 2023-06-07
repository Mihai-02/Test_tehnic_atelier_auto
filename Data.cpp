#include <iostream>
#include <ctime>
using namespace std;

#include "Data.h"


bool Data::data_corecta() const
{
    time_t t = time(0);
    tm* now = localtime(&t);
    Data prezent(now->tm_mday, now->tm_mon+1, now->tm_year+1900);

    if(zi < 0 || luna < 0 || luna > 12)
        return 0;

    if(an < prezent.an || ((an == prezent.an) && (luna < prezent.luna)) || ((an == prezent.an) && (luna == prezent.luna) && (zi<=prezent.zi)))
        return 1;
    else
        return 0;

}

ostream& operator<<(ostream& dev, const Data& date)
{
    dev << date.zi << "." << date.luna << "." << date.an << "\n";
    return dev; 
}
istream& operator>>(istream& dev, Data& date)
{
    do
    {
        cout << "\tZi:";
        dev >> date.zi;
        cout << "\tLuna:";
        dev >> date.luna;
        cout << "\tAn:";
        dev >> date.an;
    } while (!date.data_corecta());

    return dev;
}

int calc_dur_2_date(Data nast, Data anga)
{
    int an=anga.an-nast.an;
    if(anga.luna < nast.luna || (anga.luna == nast.luna && anga.zi < nast.zi))
        an--;

    return an;
}