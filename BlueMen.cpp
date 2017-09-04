/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description: Implementation file for the BlueMen class. 
Contains virtual attack and defense functions
**************************************/

#include "BlueMen.hpp"
#include "Creature.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

BlueMen::BlueMen() : Creature(3, 12)
{

}

BlueMen::~BlueMen()
{

}

int BlueMen::attack(Creature* opponent)
{
    // 2 d6 
    int attack = (rand() % 6 + 1) + (rand() % 6 + 1);
    int damage = opponent->defend(attack);
    
    return damage;
}

int  BlueMen::defend(int attack)
{
    // Blue Men lose 1 defense die for every
    // 4 points of damage they take
    
    int currentStrength = this->getStrength();
    
	int defense;
	int remainingStrength;
	int total;
	int damage;
    
    if(currentStrength <= 12 && currentStrength > 8)
    {
        // Use all 3 dice
		// Their defense is 3 d6
		cout << "The Blue Men are at full power!" << endl;
        defense = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
    }  
    else if(currentStrength <= 8 && currentStrength > 4)
    {
        // use 2 dice
		cout << "The Blue Men have lost 1/3 of their power!" << endl;
        defense = (rand() % 6 + 1) + (rand() % 6 + 1);
    }   
    else if(currentStrength <= 4)
    {
        // use 1 die
		cout << "The Blue Men have lost 2/3 of their power!" << endl;
        defense = (rand() % 6 + 1);
    }
    
    damage = attack - defense;
    total = damage - this->getArmor();

	if (total > 0)
	{


		remainingStrength = this->getStrength() - total;
		this->setStrength(remainingStrength);

		return damage;

	}

	else
	{
		return 0;
	}
   
}