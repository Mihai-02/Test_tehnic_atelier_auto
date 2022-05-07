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
    cout << "Autobuz luate in primire:\n";
    if(autobuze.size()!=0)
        cout << autobuze.front();
    cout << "Camion luate in primire:\n";
    if(camioane.size()!=0)
        cout << camioane.front();
}