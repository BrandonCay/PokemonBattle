

#include <iostream>
#include <string>
#include "pokeClass.h"
using namespace std;
#include "charmanderClass.h"

int Charmander::getHealth() {
	try {
		
			return health;
		
			throw 1;
	}
	catch (...) {
		return 1;
	}
}
string Charmander::attack(Poke* inBat[], int attNum, int attTarget) {
	if (attackList[attNum] == nullptr) {
		return "No Attack";
	}
	else {
		return attackList[attNum](inBat[attTarget]);//receives the objects info
	}
}


