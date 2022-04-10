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
};