/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description: Implementation file for the Barbarian class. 
Contains virtual attack and defense functions
**************************************/

#include "Barbarian.hpp"
#include "Creature.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Barbarian::Barbarian() : Creature(0, 12)
{

}

Barbarian::~Barbarian()
{

}

int Barbarian::attack(Creature* opponent)
{
    // Simulates 2 6-sided dice
    int attack = (rand() % 6 + 1) + (rand() % 6 + 1); 
    
    // Sends attack in as an arg
    // Returns the damage inflicted
    int damage = opponent->defend(attack);
    return damage;
}

int Barbarian::defend(int attack)
{
	int defense, total, damage;
    // 2 d6 rolls added to make the defense stat
    defense = (rand() % 6 + 1) + (rand() % 6 + 1);
    
    damage = attack - defense;
    total = damage - this->getArmor();

	if (total > 0)
	{
		int remainingStrength = this->getStrength() - total;
		this->setStrength(remainingStrength);
		return damage;
	}

	else
	{
		return 0;
	}
}