/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    */

#include "dateheure.h"
#include <cstdio>
#include <iomanip>
#include <assert.h>


bool DateHeure::operator<(const DateHeure& dh) const{
    // ...
    return true;
}

std::ostream& operator << (std::ostream& os, const DateHeure& dh){
    int jours=0, heures=0, minutes=0, secondes=0;
    // ...
    // jours = dh. ...;
    // ...




    char chaine[40];
    sprintf(chaine, "%d_%02d:%02d:%02d", jours, heures, minutes, secondes);
    os << chaine;
    return os;
}

std::istream& operator >> (std::istream& is, DateHeure& dh){
    int jours=0, heures=0, minutes=0, secondes=0;
    char seperateurlu1=0, seperateurlu2=0, seperateurlu3=0;
    is >> jours >> seperateurlu1 >> heures >> seperateurlu2 >> minutes >> seperateurlu3 >> secondes;
    assert(seperateurlu1=='_');
    assert(seperateurlu2==':');
    assert(seperateurlu3==':');
    // ...
    // dh. = ...;
    // ...
    return is;
}


