/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    */

#if !defined(__DATEHEURE_H__)
#define __DATEHEURE_H__

#include <iostream>

class DateHeure{
  public:
    bool operator<(const DateHeure& dh) const;
    void ajouterSecondes(int sec) { total_secondes += sec; }
    int totalSecondes() const { return total_secondes; }
    
  private:
    int total_secondes = 0;
    friend std::ostream& operator << (std::ostream&, const DateHeure& dh);
    friend std::istream& operator >> (std::istream&, DateHeure& dh);
};


#endif
