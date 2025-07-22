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
class ArbreMap{
    class Entree{
        public:
            Entree(const K& c):cle(c),valeur(){}
            K cle;
            V valeur;
            bool operator< (const Entree& e) const {return cle < e.cle;}
            bool operator> (const Entree& e) const {return cle > e.cle;}
            bool operator== (const Entree& e) const {return cle == e.cle;}
    };
    ArbreAVL<Entree> entrees;
  public:
      class Iterateur{
        public:
          Iterateur(ArbreMap& a) : iter(a.entrees.debut()) {}
          Iterateur(typename ArbreAVL<Entree>::Iterateur i) : iter(i) {}

          operator bool() const {
            return iter.operator bool();
          }

          Iterateur& operator++() {
            ++iter;
            return *this;
          }

          const K& cle() const {
            return (*iter).cle;
          }
          V& valeur() {
            return (V&) (*iter).valeur;
          }
        private:
          typename ArbreAVL<Entree>::Iterateur iter;
      };


      Iterateur debut() {
        return Iterateur(*this);
      }
      Iterateur fin() {
        return Iterateur(entrees.fin());
      }
      Iterateur rechercher(const K& cle) {
        return Iterateur(entrees.rechercher(cle));
      }

      bool contient(const K&) const;
      void enlever(const K&);
      void vider();
      bool vide() const;

      const V& operator[] (const K&) const;
      V& operator[] (const K&);
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
