/********************************
Author: Sara Hovey  
Date: 5/13/17
Description:
********************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature
{
  private:
  
  protected:
  int armor;
  int strength;

  public:
  Creature(int armor, int strength);
  virtual ~Creature();

  int getArmor();
  int getStrength();
  void setStrength(int strength);
  virtual int attack(Creature* opponent);
  virtual int defend(int attack);
  
};

#endif