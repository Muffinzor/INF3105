/* Squelette pour classe générique ArbreMap<K, V>.
 * Lab8 -- Dictionnaires et Arbres binaires de recherche
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */
#if !defined(__ARBREMAP_H__)
#define __ARBREMAP_H__
#include "arbreavl.h"

template <class K, class V>
class ArbreMap {

  public:
    bool contient(const K&) const;

    void enlever(const K&);
    void vider();
    bool vide() const;

    const V& operator[] (const K&) const;
    V& operator[] (const K&);

  private:
    struct Entree {
        K cle;
        V valeur;

        Entree(const K& c, const V& v = V()) : cle(c), valeur(v) {}

        bool operator < (const Entree& autre) const {
            return cle < autre.cle;
        }
        bool operator == (const Entree& autre) const {
            return cle == autre.cle;
        }
    };

    ArbreAVL<Entree> entrees;
};

template <class K, class V>
void ArbreMap<K,V>::vider(){
    assert(entrees != nullptr);
    entrees.vider();
}

template <class K, class V>
bool ArbreMap<K,V>::vide() const{
    assert(entrees != nullptr);
    return entrees.vide();
}

template <class K, class V>
void ArbreMap<K,V>::enlever(const K& c)
{
    entrees.enlever(Entree(c));
}

template <class K, class V>
bool ArbreMap<K,V>::contient(const K& c) const
{
    return entrees.contient(Entree(c));
}

template <class K, class V>
const V& ArbreMap<K,V>::operator[] (const K& c)  const
{
    return entrees.rechercher(Entree(c)).valeur;
}

template <class K, class V>
V& ArbreMap<K,V>::operator[] (const K& c) 
{
    Entree e(c);
    if (!entrees.contient(e)) {
        entrees.inserer(e);
    }
    return entrees.rechercher(e).valeur;
}


#endif
