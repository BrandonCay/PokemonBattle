//#include "pokeClass.h"
#include <iostream>
#include <string>
//#include "pokeClass.h"
using namespace std;
#include "pokeClass.h"

//int Poke::getHealth() {

//}
typedef string(*functionPtr)(Poke* t); 


string Poke::attack(Poke* inBat[], int attNum, int attTarget) {
	if (attackList[attNum] == nullptr) {
		return "No Attack";
	}
	else {
		return attackList[attNum](inBat[attTarget]);//receives the objects info
	}
}

void Poke::setHealth(int n) {
	health = n;
}

string Poke::getName() {
	return name;
}

void Poke::displayAttacks() {
	cout << endl;
	for (int i=0; i < 4 && attackList[i]!=nullptr; ++i) {
		cout << i+1<<". " << attackList[i](nullptr) << endl;
	}
	cout << endl;
}
string Poke::getAttackName(int attNum) {
	try {
		if (attackList[attNum] == nullptr) {
			throw 1;
		}

		return attackList[attNum](nullptr);
	}

	catch (int x) {
		cout << "Not an attack. Try again: ";
		cin >> attNum;
		while (attackList[attNum-1] == 0) {
			cout << "Try again: ";
			cin >> attNum;
		}
	}

	return attackList[attNum-1](nullptr);
}

functionPtr Poke::getAttack(int attNum) {
	return attackList[attNum];
}
