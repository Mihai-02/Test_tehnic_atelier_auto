#pragma once
#include <ctime>
#include <iostream>
using namespace std;

class Masina
{
  protected:
    int ID;
    int kilometri;
    int an_fabricatie;
    bool diesel;

  public:
      Masina(int id, int kil, int an, bool dis):ID(id),kilometri(kil),an_fabricatie(an),diesel(dis){}
      Masina(){ID=-1, kilometri=-1, an_fabricatie=-1, diesel=0;}
      int calc_vechime()
      {
        time_t t = std::time(0);
        tm* now = std::localtime(&t);
        int vechime=now->tm_year+1900 - an_fabricatie;

        return vechime;
      }
      friend ostream& operator<<(ostream& dev, const Masina& mas)
      {
        dev << "ID: " << mas.ID;
        dev << "\nKilometri: " << mas.kilometri;
        dev << "\nAn fabricatie: " << mas.an_fabricatie;
        dev << "\nDiesel: " << (mas.diesel==1 ? "Da" : "Nu") << "\n";

        return dev;
      }
      friend istream& operator>>(istream& dev, Masina& mas)
      {
        cout << "Introduceti detaliile vehiculului:\n";
        cout << "ID:";
        dev >> mas.ID;
        cout << "Numar kilometri:";
        dev >> mas.kilometri;
        cout << "An fabricatie:";
        dev >> mas.an_fabricatie;
        int k;
        do
        {
          cout << "Diesel?(1/0):";
          dev >> k;
        } while (k>1 || k<0);
        mas.diesel=k;
        return dev;
      }
};