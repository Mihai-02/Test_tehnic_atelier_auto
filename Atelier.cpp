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