/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description: Implementation file for the
HarryPotter class. Contains virtual attack and defense functions
**************************************/

#include "HarryPotter.hpp"
#include "Creature.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

HarryPotter::HarryPotter() : Creature(0, 10)
{
	this->undead = false;
}

HarryPotter::~HarryPotter()
{

}

int HarryPotter::getUndead()
{
	return undead;
}

void HarryPotter::setUndead(bool undead)
{
	this->undead = undead;
}

int HarryPotter::attack(Creature *opponent)
{
    // 2 d6
    int attack = (rand() % 6 + 1) + (rand() % 6 + 1);
	int damage = opponent->defend(attack);

	return damage;
}

int  HarryPotter::defend(int attack)
{
    // 2 d6
	int defense, damage, total, remainingStrength;
    defense = (rand() % 6 + 1) + (rand() % 6 + 1); 
    damage = attack - defense;
    total = damage - this->getArmor();

	if (total > 0)
	{
		remainingStrength = this->getStrength() - total;
		this->setStrength(remainingStrength);

		int currentStrength;

		currentStrength = this->getStrength();

		// If Harry dies,  he comes back, 
		// and strength is reset to 20
		// but only once, hence the bool variable
		if (this->getUndead() == false)
		{
			if (currentStrength <= 0)
			{
				// Activate Hogwarts
				cout << "Harry activated his HOGWARTS ability! He's back with 20 strength" << endl;
				this->setStrength(20);
				this->setUndead(true);
			}
		}

		return damage;
	}

	else
	{
		return 0;
	}

}