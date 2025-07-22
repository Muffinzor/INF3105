/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    */

#include "agenda.h"
#include <cmath>


void Agenda::creer(const std::string& id, const Coordonnees& c, int puissance){
    Borne b;
    b.position = c;
    b.puissance = puissance;
    bornes[id] = b;
    std::cout << "OK" << std::endl;
}

ArbreMap<std::string, int> Agenda::trouver(const Coordonnees& c, int rayon, int puissancemin) const{
    ArbreMap<std::string, int> resultat;
    for(auto it = bornes.debut(); it; ++it){
        const std::string& id = it.cle();
        const Borne& b = it.valeur();
        if(b.puissance >= puissancemin){
            int d = std::round(c.distance(b.position));
            if(d <= rayon){
                resultat[id] = d;
            }
        }
    }
    return resultat;
}

DateHeure Agenda::reserverI(const std::string& id, DateHeure date, int duree){
    Borne& b = bornes[id];
    auto it = b.reservations.debut();

    DateHeure debut = date;

    while(it){
        DateHeure r_debut = it.cle();
        int r_duree = it.valeur();
        DateHeure r_fin = r_debut;
        r_fin.ajouterSecondes(r_duree);


        if(debut < r_debut && (debut.totalSecondes() + duree) <= r_debut.totalSecondes()){
            break;
        }

        if(debut < r_fin){
            debut = r_fin;
        }

        ++it;
    }

    b.reservations[debut] = duree;
    std::cout << debut << std::endl;
    return debut;
}

DateHeure Agenda::reserverC(const Coordonnees& c, int rayon, int puissancemin, DateHeure datemin, int duree, std::string& borneid){
    DateHeure meilleur_debut;
    bool premiere = true;
    double meilleure_distance = 0.0;

    for(auto it = bornes.debut(); it; ++it){
        const std::string& id = it.cle();
        Borne& b = bornes[id];
        if(b.puissance < puissancemin)
            continue;

        double d = c.distance(b.position);
        if(d > rayon)
            continue;

        DateHeure debut = reserverI(id, datemin, duree);

        if(premiere || debut < meilleur_debut || (debut.totalSecondes() == meilleur_debut.totalSecondes() && d < meilleure_distance)){
            meilleur_debut = debut;
            meilleure_distance = d;
            borneid = id;
            premiere = false;
        } else {
            b.reservations.enlever(debut);
        }
    }

    std::cout << borneid << " " << meilleur_debut << std::endl;
    return meilleur_debut;
}

