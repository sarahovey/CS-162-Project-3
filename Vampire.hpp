/********************************
Author: Sara Hovey  
Date: 5/14/17
Description:
********************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP


#include "Creature.hpp"

class Vampire : public Creature
{
  private:
  

  public:
  //Vampire(int armor, int strength);  
  
  Vampire();
  ~Vampire();

  virtual int attack(Creature *opponent);
  virtual int defend(int attack);
 
  
};

#endif