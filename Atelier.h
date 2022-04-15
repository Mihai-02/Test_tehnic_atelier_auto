#include "Post.h"
#include <string>
#include <vector>

using namespace std;

class Atelier
{
    string nume;
    vector<Post> posturi;

    public:
        Atelier(string name={}){nume=name;}
        void give_name(){cout << "Introduceti un nume pentru atelier: "; getline(cin, nume);}
        void print_info() const
        {
            cout << "Numele atelierului: " << nume << "\n";
        }
};