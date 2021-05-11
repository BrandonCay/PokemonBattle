#pragma once
//#ifndef trainer_H
//#define trainer_H
#include "pokeClass.h"

class trainer {
protected:
	Poke* pokemon[6] = {nullptr};
	string name;
	bool dBattle=false;
	bool fainted = false;

public:
	trainer(string n="red") {
		name = n;
	}
	trainer(Poke* pArr[6], string n = "red") {
		name = n;
		for (int i = 0; i < 6 && pArr[i]!=nullptr; ++i) {
				pokemon[i] = pArr[i];	
		}
	
	}
	trainer(Poke& p, string n="red") {
		pokemon[0] = &p;
		name = n;
	}


	virtual Poke* startPoke()=0;
	virtual int swap(Poke* inBat[]) = 0;
	int bag() { cout << "nothing happened" << endl; string pass; cout << "Enter anything to continue: "; cin >> pass; return 0; }
	virtual int attack(Poke& myPoke, Poke* inBat[], bool dBat = false)=0;
	int getTotalBatPoke();
	bool getdBattle();
	void setFainted(bool b);
	bool getFainted();
	string getName();
};

//#endif