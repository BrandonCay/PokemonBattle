#pragma once
#include "trainer.h"
#ifndef player_H
#define player_H



class player : public trainer {

public:
	player(string n = "red") : trainer(n) {
	}
	player(Poke* pArr[6], string n = "red") :trainer(pArr, n) {

	}
	player(Poke& p, string n ="red") :trainer(p, n) {
		
	}

	Poke* startPoke();//used for choosing pokemon at the start of battle
	int attack(Poke& myPoke, Poke* inBat[], bool dBat);
	int bag() { cout << "nothing happened" << endl; string pass; cout << "Enter anything to continue: "; cin >> pass; return 1; }
	void displayPokeList();
	void displayPokeStatus(int i);
	int swap(Poke* inBat[]);
	virtual ~player() {}
};


#endif