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