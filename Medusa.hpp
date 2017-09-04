/********************************
Author: Sara Hovey  
Date: 5/14/17
Description:
********************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"
#include "Creature.hpp"

class Medusa : public Creature
{
  private:
  

  public:
  //Medusa(int armor, int strength);
  
  Medusa();
  ~Medusa();

  virtual int attack(Creature *opponent);
  virtual int defend(int attack);
 
  
};

#endif