#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "NPCtrainer.h"
using namespace std;




Poke* NPCtrainer::startPoke() {//initial pokemon

	if (pokemon[0] != nullptr) { //checks if initial pokemon exists
		if (pokemon[0]->getHealth() > 0) {//checks if pokemon has NOT fainted
			return pokemon[0];
		}
		else {
			for (int i = 1; i < 6 && pokemon[i] != nullptr; ++i) {

				if (pokemon[i]->getHealth() > 0) {

					return pokemon[i];
				}

			}
			cout << "No Pokemon to battle" << endl;
			fainted = true;
			return nullptr;
		}
	}
	else {
		cout << "No Pokemon to battle" << endl;
		fainted = true;
		return nullptr;
	}
}
int NPCtrainer::attack(Poke& myPoke, Poke* inBat[], bool dBat = false) {

	srand(time(NULL));
	int attPik = rand() % 2;
	int tarPik = 0;
	cout << attPik << endl;
	while (myPoke.getAttack(attPik) == nullptr) {
		attPik = rand() % 2;
		cout << "TESTING: " << attPik<<endl;
	}

	if (dBat == false) {
		tarPik = 0;
	}
	else {
		cout << "cant";
	}

	string attName  =myPoke.attack(inBat, attPik, tarPik);
	cout << myPoke.getName() << " " << "used " << attName <<endl;
	string pass;
	cout << "Enter anything to continue: ";
	cin >> pass;
	return 1;
}


	int NPCtrainer::swap(Poke * inBat[]) {
		if (dBattle == false) {
			for (int i = 0; i < 6; ++i) {
				if (pokemon[i] != nullptr) {
					if (pokemon[i]->getHealth() > 0) {
						inBat[1] = pokemon[i];
						return 1;
					}
				}
				else {
					continue;
				}

			}
			cout << "No Pokemon to battle" << endl;
			fainted = true;
			return 0;
		}
		else {
			cout << "can't" << endl;
			return 0;
		}
	
}