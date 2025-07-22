/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    */

#if !defined(__AGENDA_H__)
#define __AGENDA_H__
#include <string>
#include "coordonnees.h"
#include "dateheure.h"
#include "arbremap.h"


class Agenda{
  public:
    void creer(const std::string& id, const Coordonnees& c, int puissance);
    ArbreMap<std::string, int> trouver(const Coordonnees& c, int rayon=0, int puissancemin=0) const;
    DateHeure reserverI(const std::string& id, DateHeure date, int duree);
    DateHeure reserverC(const Coordonnees& c, int rayon, int puissancemin, DateHeure datemin, int duree, std::string& borneid);
    
  private:
  struct Borne {
    Coordonnees position;
    int puissance;
    ArbreMap<DateHeure, int> reservations;
  };
  mutable ArbreMap<std::string, Borne> bornes;

};

#endif

