#include "Post.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Atelier
{
    string nume;
    vector<Post> posturi;

    public:
        Atelier(string name={}){nume=name;}
        inline void give_name(){cout << "Introduceti un nume pentru atelier: "; getline(cin, nume);}
        inline void print_info() const {cout << "Numele atelierului: " << nume << "\n";}
        void adaugare_angajat();
        inline bool is_open() const {return (posturi.size() > 0);}
};