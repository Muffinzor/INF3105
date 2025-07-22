/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    */

#include "dateheure.h"
#include <cstdio>
#include <iomanip>
#include <assert.h>


bool DateHeure::operator<(const DateHeure& dh) const{
    return total_secondes < dh.total_secondes;
}

std::ostream& operator << (std::ostream& os, const DateHeure& dh){
    int secondes = dh.total_secondes;
    int jours = secondes / 86400; // 24*60*60
    secondes %= 86400;
    int heures = secondes / 3600;
    secondes %= 3600;
    int minutes = secondes / 60;
    secondes %= 60;

    char chaine[40];
    sprintf(chaine, "%d_%02d:%02d:%02d", jours, heures, minutes, secondes);
    os << chaine;
    return os;
}

std::istream& operator >> (std::istream& is, DateHeure& dh){
    int jours = 0, heures = 0, minutes = 0, secondes = 0;
    char sep1 = 0, sep2 = 0, sep3 = 0;

    is >> jours >> sep1 >> heures >> sep2 >> minutes >> sep3 >> secondes;
    assert(sep1 == '_');
    assert(sep2 == ':');
    assert(sep3 == ':');

    dh.total_secondes = (((jours * 24 + heures) * 60 + minutes) * 60 + secondes);
    return is;
}


