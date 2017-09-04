/********************************
Author: Sara Hovey  
Date: 5/14/17
Description:
********************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP


#include "Creature.hpp"

class HarryPotter : public Creature
{
  private:
  bool undead;
  

  public:
  HarryPotter();
  ~HarryPotter();

  int getUndead();
  void setUndead(bool undead);
  virtual int attack(Creature *opponent);
  virtual int defend(int attack);
 
  
};

#endif