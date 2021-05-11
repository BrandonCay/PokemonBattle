
#include <string>
#include <iostream>
using namespace std;
#include "player.h"


Poke* player::startPoke() {//initial pokemon
	
	
			for (int i = 0; i < 6 ; ++i) {	
				if (pokemon[i] != nullptr) {
					if (pokemon[i]->getHealth() > 0) {
						return pokemon[i];
					}
				}
				else {
					continue;
				}

			}
			cout << "No Pokemon to battle" << endl;
			fainted = true;
			return nullptr;
	
	
}




int player::attack(Poke& myPoke, Poke* inBat[], bool dBat = false) {
	int attackNum=0;
	int target=0;
	bool tPicFlg = false;//could skip flag uses and check for number ranges instead
	string attName = "No Attack";

	while (attName == "No Attack") {


		myPoke.displayAttacks();
		cout << "Choose attack (1-4): ";
		cin >> attackNum;

		while (attackNum > 4 || attackNum <= 0) {//pick attack
			cout << "Try again. Choose attack (1-4): " << endl;
			cin >> attackNum;

		}

		if (dBat) {
			cout << "Choose Target (1-4): ";
			cin >> target;
			while (target > 4 || target <= 0) {//pick target
				cout << "Try again. Choose Target (1-4): ";
				cin >> target;
			}
		}
		else {

			cout << "Choose Target (1(self) - 2): ";
			cin >> target;

			while (target > 2 || target <= 0) {//pick target

				cout << "Try again. Choose Target (1-2): ";
				cin >> target;

			}
		}
		attName = myPoke.getAttackName(attackNum - 1);
	}

	myPoke.attack(inBat, attackNum - 1, target - 1);
	cout << myPoke.getName() << " " << "used " << attName << endl;
	string pass;
	cout << "Enter anything to continue: ";
	cin >> pass;

	return 1;
}



void player::displayPokeStatus(int i) {
	cout << pokemon[i]->getHealth();
}




void player:: displayPokeList() {
	for (int i = 0; i < 6 && pokemon[i] != nullptr; ++i) {
		cout << i + 1 << " " << pokemon[i]->getName() << " "; displayPokeStatus(i); cout << endl;
	}
}




int player::swap( Poke* inBat[]) {
	int i;//picking pokemon num
	int j;//picking which to swap
	Poke* sending=nullptr;

	if (sizeof(inBat) <= 0 || sizeof(*inBat)<=0) { //supposed to act as a guard to quell "could be 24 or -4" warnings
		return 0;
	}

	cout << "Pick a pokemon to replace: " << endl;

	for (int i = 0; i < (sizeof(inBat) / sizeof(*inBat)) / 2; ++i) {
		cout << i + 1 << " " << inBat[i]->getName() << endl;
	}

	cin >> j;

	while ((j <= 0) || j > (sizeof(inBat) / sizeof(*inBat) / 2)) {
		cout << "Try Again: ";
		cin >> j;
	}

	j -= 1;

	displayPokeList();
	cout << "Pick which Pokemon to send: ";
	cin >> i;

	while ((i > 6 || i <= 0) || (pokemon[i - 1] == nullptr) || (pokemon[i-1]==inBat[j]) ) {
		cout << "Try again: ";
		cin >> i;
	}
	i -= 1;

	inBat[j] = pokemon[i];
	
	return 1;
}