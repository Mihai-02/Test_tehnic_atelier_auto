#include <iostream>

using namespace std;

class Data
{
    unsigned int zi;
    unsigned int luna;
    unsigned int an;

    public:
        Data(unsigned int day=1, unsigned int month=1, unsigned int year=1900):zi(day),luna(month),an(year){}
        friend ostream& operator<<(ostream&, const Data&);
        friend istream& operator>>(istream&, Data&);
        bool data_corecta()const;
        friend int calc_dur_2_date(Data, Data);
};