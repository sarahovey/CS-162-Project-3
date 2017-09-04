/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description: Implementation file for the Vampire class. 
Contains virtual attack and defense functions
**************************************/

#include "Creature.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void fight(Creature *f1, Creature *f2);
bool validateInt(int data, int min, int max)
{
	if(data<min || data > max)
	{
		cout << "Please enter a number between " << min << " and " << max << endl;
		return false;
	}
	
	return true;
}

int main()
{
	Creature *f1;
	Creature *f2;

    bool done = false;
	
	while(done==false)
	{
		bool valid = false;
		int input;
		while (valid == false)
		{
			cout << "Welcome to knock-off DnD" << endl;
            cout << "Pick your first fighter:" << endl;
			cout <<"1. Vampire" << endl;
			cout <<"2. Barbarian" << endl;
			cout <<"3. BlueMen" << endl;
            cout <<"4. Medusa" << endl;
            cout <<"5. HarryPotter" << endl;
			cout <<"6. Exit" << endl;
		
			if(cin >> input)
			{
				// Validate range
				valid = validateInt(input, 1, 6);
				
			}
			else
			{
				cout << "Please select an option" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				
			}
		}
         
         // This isn't going to work
         // can I make a new Creature, and then
         // give assign it to a subclass in an if statement?
         
		// Vampire
		if(input == 1)
		{
           f1 = new Vampire;
		   cout << "You picked Vampire" << endl;
		}
		
		// Barbarian
		else if(input == 2)
		{
            f1 = new Barbarian;
			cout << "You picked Barbarian" << endl;
		}
		
		// BlueMen
		else if(input == 3)
		{
            f1 = new BlueMen;
			cout << "You picked BlueMen" << endl;
		}
        //Medusa
        else if(input == 4)
		{
            f1 = new Medusa;
		}
        //HarryPotter
        else if(input == 5)
		{
            f1 = new HarryPotter;
		}
		
		// Exit
		else if(input == 6)
		{
			delete f1;
			delete f2;
			done = true;
			return 0;
		}
        
        
        // Choose second fighter  
        bool valid2 = false;
		int input2;
		while (valid2 == false)
		{
            cout << "Pick your second fighter:" << endl;
			cout <<"1. Vampire" << endl;
			cout <<"2. Barbarian" << endl;
			cout <<"3. BlueMen" << endl;
            cout <<"4. Medusa" << endl;
            cout <<"5. HarryPotter" << endl;
			cout <<"6. Exit" << endl;
		
			if(cin >> input2)
			{
				// Validate range
				valid2 = validateInt(input2, 1, 6);
				
			}
			else
			{
				cout << "Please select an option" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				
			}
		}

		//Vampire
		if(input2 == 1)
		{
			f2 = new Vampire;
			cout << "You picked Vampire" << endl;
		}
		
		// 
		else if(input2 == 2)
		{
			f2 = new Barbarian;
		}
		
		// Bluemen
		else if(input2 == 3)
		{
			f2 = new BlueMen;
		}
        
		//Medusa
        else if(input2 == 4)
		{
			f2 = new Medusa;
		}
        
		//Harry Potter
        else if(input2 == 5)
		{
			f2 = new HarryPotter;
		}
		
		// Exit
		else if(input2 == 6)
		{
			done = true;
		}
		
        
        // Fight
        fight(f1, f2);
        
        
        //Ask if they want to play again
	}
		
	delete f1;
	delete f2;
    
	return 0;
}

void fight(Creature *f1, Creature *f2)
{
    // Will return how much damage the opponent took
    // They need to take turns attacking each other, but 
    // also a dead character shouldn't fight


	// Random start
	int randTurn = rand() % 2 + 1;

	//f1 goes first in a fight to KO
	if (randTurn == 1)
	{
		// This condition checks for a dead character
		while (f1->getStrength() > 0 && f2->getStrength() > 0)
		{
			cout << "Fighter 1 is attacking" << endl;
			cout << "Fighter 1 did " << f1->attack(f2) << " damage"<< endl;
			cout << "After effects and armor, the opponent fighter 2 has " << f2->getStrength() << " health left" << endl;
			cout << "" << endl;

			if(f2->getStrength() > 0)
			{
				// Fight
				cout << "Fighter 2 is attacking" << endl;
				cout << "Fighter 2 did " << f2->attack(f1) << " damage" << endl;
				cout << "After effects and armor, the opponent fighter 1 has " << f2->getStrength() << " health left" << endl;
				cout << "" << endl;

			}

			else
			{

			}

		}
	}

	else if (randTurn == 2)
	{
		// This condition checks for a dead character
		while (f1->getStrength() > 0 && f2->getStrength() > 0)
		{

			cout << "Fighter 2 is attacking" << endl;
			cout << "Fighter 2 did " << f2->attack(f1) << " damage" << endl;
			cout << "After effects and armor, the opponent fighter 1 has " << f2->getStrength() << " health left" << endl;
			cout << "" << endl;

			if (f2->getStrength() > 0)
			{
				// Fight player 1
				cout << "Fighter 1 is attacking" << endl;
				cout << "Fighter 1 did " << f1->attack(f2) << " damage" << endl;
				cout << "After effects and armor, the opponent fighter 2 has " << f2->getStrength() << " health left" << endl;
				cout << "" << endl;

			}

			else
			{

			}

		}
	}

	else
	{
		cout << "well" << endl;
	}
	
	//Checking win

	if (f1->getStrength() <= 0)
	{
		cout << "Fighter 2 has won!" << endl; 
		cout << "*****************" << endl;
		cout << "" << endl;
	}

	if (f2->getStrength() <= 0)
	{
		cout << "Fighter 1 has won!" << endl;
		cout << "*****************" << endl;
		cout << "" << endl;
	}

   
}