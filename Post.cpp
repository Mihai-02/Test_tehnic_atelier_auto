#include "Post.h"

Post::Post(string name, string prename, Data nastere, Data angajare, const string pozitie)
{
    if(pozitie=="Asistent")
        ang=new Asistent(name, prename, nastere, angajare);
    else if(pozitie=="Mecanic")
        ang=new Mecanic(name, prename, nastere, angajare);
    else if(pozitie=="Director")
        ang=new Director(name, prename, nastere, angajare);
    else
        cout << "Pozitie invalida\n";
}

void Post::print_info() const
{
    ang->afisare();
}

void Post::print_full()
{
    ang->afisare();
    cout << "Masini standard luate in primire:\n";
    queue<Standard> mtemp=masini;
    while(mtemp.size()>0)
    {
        cout << mtemp.front();
        mtemp.pop();
    }
    cout << "Autobuz luat in primire:\n";
    if(autobuze.size()!=0)
        cout << autobuze.front();
    cout << "Camion luat in primire:\n";
    if(camioane.size()!=0)
        cout << camioane.front();
}

void Post::add_masina()
{
    if(masini.size()==3)
    {
        cout << "Angajatul dorit nu mai are locuri pentru masini disponibile\n";
        return;
    }
    else
    {
        Standard st;
        cin >> st;
        masini.push(st);
    }
}

void Post::add_camion()
{
    if(masini.size()==1)
    {
        cout << "Angajatul dorit nu mai are loc pentru camion disponibil\n";
        return;
    }
    else
    {
        Camion cam;
        cin >> cam;
        camioane.push(cam);
    }
}

void Post::add_autobuz()
{
    if(masini.size()==1)
    {
        cout << "Angajatul dorit nu mai are loc pentru autobuz disponibil\n";
        return;
    }
    else
    {
        Autobuz aut;
        cin >> aut;
        autobuze.push(aut);
    }
}