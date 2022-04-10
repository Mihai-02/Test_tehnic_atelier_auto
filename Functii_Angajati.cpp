
#include "Angajat.h"
#include "Asistent.h"
#include "Mecanic.h"
#include "Director.h"
#include <vector>
#include <iostream>

using namespace std;

vector<Angajat*> adaugare_angajat(vector<Angajat*> vec)
{
    string num, pre;
    Data nast, anga;

    string type;

    do
    {
        cout << "Tip angajat(Asistent/Mecanic/Director):";
        cin >> type;
    } while (type!="Asistent" && type!="Mecanic" && type!="Director");
    

    do
    {
        cout << "Nume(max 30 caractere):";
        cin >> num;
    } while (num.length()>30 || num.length()==0);
    do
    {
        cout << "Prenume(max 30 caractere):";
        cin >> pre;
    } while (pre.length()>30 || pre.length()==0);


    cout << "Data nasterii:\n";
    cin >> nast;
    cout << "Data angajarii:\n";
    cin >> anga;
    if(calc_dur_2_date(nast, anga)<18)
    {
        cout << "Persoana are varsta mai mica de 18 ani, nu poate fi un angajat\n";
        return vec;
    }

    if(type=="Asistent")
        vec.push_back(new Asistent(num, pre, nast, anga));
    else if(type=="Mecanic")
        vec.push_back(new Mecanic(num, pre, nast, anga));
    else
        vec.push_back(new Director(num, pre, nast, anga));

    return vec;
}
//DE TESTAT
void modificare_angajat(vector<Angajat*> vec)
{
    int id;
    do
    {
        cout << "Introduceti ID-ul angajatului de modificat:";
        cin >> id;

        vector<Angajat*>::iterator it;
        for(it=vec.begin(); it!=vec.end(); it++)
        if(id == (*it)->ID)
        {
            char select;
            do
            {
                cout << "Doriti modificarea numelui?(Y/N)";
                select=toupper(select);
            } while (select != 'Y' && select != 'N');
            
            if(select == 'Y')
            {
                do
                {
                    cout << "Nume(max 30 caractere):";
                    cin >> (*it)->nume;
                } while ((*it)->nume.length()>30 || (*it)->nume.length()==0); 
            }

            do
            {
                cout << "Doriti modificarea prenumelui?(Y/N)";
                select=toupper(select);
            } while (select != 'Y' && select != 'N');

            if(select == 'Y')
            {
                do
                {
                    cout << "Preume(max 30 caractere):";
                    cin >> (*it)->prenume;
                } while ((*it)->prenume.length()>30 || (*it)->prenume.length()==0); 
            }

            Data nast=(*it)->data_nasterii, anga=(*it)->data_angajarii;

            do
            {
                cout << "Doriti modificarea datei nasterii?(Y/N)";
                select=toupper(select);
            } while (select != 'Y' && select != 'N');

            if(select == 'Y')
            {
                cout << "Data nasterii:\n";
                cin >> nast;
            }

            do
            {
                cout << "Doriti modificarea datei angajarii?(Y/N)";
                select=toupper(select);
            } while (select != 'Y' && select != 'N');

            if(select == 'Y')
            {
                cout << "Data angajarii:\n";
                cin >> anga;
            }

            if(calc_dur_2_date(nast, anga)<18)
                cout << "Persoana are varsta mai mica de 18 ani; cele doua date nu vor fi modificate\n";
            else
            {
                (*it)->data_nasterii=nast;
                (*it)->data_angajarii=anga;
            }
            return;
        }
    cout << "Nu exista nici un angajat cu ID-ul introdus\n";
    } while (1);
}
//DE TESTAT
float calcul_salariu(vector<Angajat*> vec)
{
    int id;
    do
    {
        cout << "Introduceti ID-ul angajatului al carui salariu il calculati:";
        cin >> id;

        vector<Angajat*>::iterator it;
        for(it=vec.begin(); it!=vec.end(); it++)
        if(id == (*it)->ID)
            return (*it)->get_vechime()*(*it)->coef_salariat*1000.0F;

        cout << "Nu exista nici un angajat cu ID-ul introdus\n";
    } while (1);
    
}