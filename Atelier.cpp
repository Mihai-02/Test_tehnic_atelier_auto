#include "Atelier.h"
#include "Data.h"
#include "Asistent.h"
#include "Mecanic.h"
#include "Director.h"

void Atelier::adaugare_angajat()
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
        return;
    }

    if(type=="Asistent")
        posturi.push_back(Post(num, pre, nast, anga, "Asistent"));
    else if(type=="Mecanic")
        posturi.push_back(Post(num, pre, nast, anga, "Mecanic"));
    else
        posturi.push_back(Post(num, pre, nast, anga, "Director"));

}

void Atelier::print_lista_angajati()
{
    vector<Post>::iterator it;
    for(it=posturi.begin(); it!=posturi.end(); it++)
        it->print_info();

}

void Atelier::print_full_info()
{
    cout << "\n=======================================\n\t\t";
    print_title();
    cout << "=======================================\n";

    vector<Post>::iterator it;
    for(it=posturi.begin(); it!=posturi.end(); it++)
        it->print_full();
}

//Returneaza 1 daca vehiculul e adaugat cu succes si 0 in caz contrar
bool Atelier::insert_new_vehicle()
{
    string tip;
    do
    {
        cout << "Introduceti tipul de vehicul:";
        cin >> tip;
    } while (tip!="Standard" && tip!="Camion" && tip!="Autobuz");

    string employee;
    cout << "Introduceti numele de familie al angajatului la care doriti intrarea(Introduceti \"-\" pentru nicio preferinta):";
    cin >> employee;

    if(employee=="-")
    {
        vector<Post>::iterator it=posturi.begin();
        bool is_ok=0;
        while(it!=posturi.end() && is_ok!=1)
        for (size_t i=0; i<posturi.size(), is_ok!=1; i++)
        {
            if(tip=="Standard")
                is_ok=posturi.at(i).add_masina();
            else if(tip=="Camion")
                is_ok=posturi.at(i).add_camion();
            else
                is_ok=posturi.at(i).add_autobuz();
            
            it++;
        }
        if(it==posturi.end() && is_ok==0)
        {
            cout << "Error: Nu exista nici un angajat liber\nVa rugam reveniti mai tarziu\n";
            return 0;
        }
        cout << "Vehiculul a fost preluat cu succes\n";
        return 1; 
    }
    else
    {
        bool is_ok=1;
        bool exists=0;
        //vector<Post>::iterator it;
        //for (it=posturi.begin(); it!=posturi.end(); it++)
        for (size_t i=0; i<posturi.size(); i++)
        {
            if(posturi.at(i).get_nume_angajat()==employee)
            {
                exists=1;
                if(tip=="Standard")
                    is_ok=posturi.at(i).add_masina();
                else if(tip=="Camion")
                    is_ok=posturi.at(i).add_camion();
                else
                    is_ok=posturi.at(i).add_autobuz();
                break;
            }
        }
        if(is_ok==0)
        {
            cout << "Angajatul dorit nu mai are nici un loc disponibil\n";
            return 0;
        }
            
        if(!exists)
        {
            cout << "Error: Nu exista un angajat cu numele introdus\n";
            return 0;
        }
        cout << "Vehiculul a fost preluat cu succes\n";
        return 1;
    }
}