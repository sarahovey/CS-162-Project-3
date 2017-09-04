/********************************
Author: Sara Hovey  
Date: 5/14/17
Description:
********************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include "Creature.hpp"
#include "Creature.hpp"

class BlueMen : public Creature
{
  private:
  

  public:
  //BlueMen(int armor, int strength);
  BlueMen();
  ~BlueMen();
  
  virtual int attack(Creature *opponent);
  virtual int defend(int attack);
 
  
};

#endif