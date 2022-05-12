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


//returneaza 1 daca se adauga cu succes vehiculul
bool Post::add_masina()
{
    if(!is_available_masina())
        return 0;
    else
    {
        Standard st;
        cin >> st;
        masini.push(st);
        return 1;
    }
}

bool Post::add_camion()
{
    if(!is_available_camion())
        return 0;
    else
    {
        Camion cam;
        cin >> cam;
        camioane.push(cam);
        return 1;
    }
}

bool Post::add_autobuz()
{
    if(!is_available_autobuz())
        return 0;
    else
    {
        Autobuz aut;
        cin >> aut;
        autobuze.push(aut);
        return 1;
    }
}