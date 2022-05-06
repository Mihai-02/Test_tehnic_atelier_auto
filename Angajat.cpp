#include "Angajat.h"
#include <ctime>

Angajat::Angajat(int id, string name, string prename, Data nastere, Data angajare, float coeficient)
{
    ID=global_id;
    nume=name;
    prenume=prename;
    data_nasterii=nastere;
    data_angajarii=angajare;
    coef_salariat=coeficient;
    global_id++;
}

void Angajat::afisare() const
{
    cout << "ID: " << ID << "\n";
    cout << "Nume: " << nume << "\n";
    cout << "Prenume: " << prenume << "\n";
    cout << "Data nasterii: " << data_nasterii;
    cout << "Data angajari: " << data_angajarii;
    cout << "Coeficient: " << coef_salariat << "\n\n";
}

int Angajat::get_vechime()
{
    time_t t = std::time(0);
    tm* now = std::localtime(&t);
    Data prezent(now->tm_year+1900, now->tm_mon+1, now->tm_mday);

    return calc_dur_2_date(data_angajarii, prezent);
}

float Angajat::get_salariu()
{
    return this->get_vechime()*coef_salariat*1000.0F;
}