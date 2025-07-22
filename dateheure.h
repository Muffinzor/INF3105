/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    */

#if !defined(__DATEHEURE_H__)
#define __DATEHEURE_H__

#include <iostream>

class DateHeure{
  public:
    
    bool operator<(const DateHeure& dh) const;
    
  private:
  int total_secondes;
  friend std::ostream& operator << (std::ostream&, const DateHeure& dh);
  friend std::istream& operator >> (std::istream&, DateHeure& dh);
};


#endif
