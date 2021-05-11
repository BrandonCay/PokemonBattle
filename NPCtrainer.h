#pragma once
#include "trainer.h"
#ifndef NPCt_H
#define NPCt_H


class NPCtrainer :public trainer {

public:

	NPCtrainer(): trainer("blue") {
	}
	NPCtrainer(Poke* pArr[6], string n = "blue") :trainer(pArr, n) {

	}
	NPCtrainer(Poke& p, string n="blue") :trainer(p, n) {

	}

	Poke* startPoke();//used for choosing pokemon at the start of battle
	int attack(Poke& myPoke, Poke* inBat[], bool dBat);
	int bag() { cout << "nothing happened" << endl; return 0; }
	void displayPokeList();
	void displayPokeStatus(int i);
	int swap(Poke* inBat[]);

	virtual ~NPCtrainer() {}
};

#endif
