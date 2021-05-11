#pragma once
#ifndef H_pokeClass
#define H_pokeClass
//#include "movePoolDef.cpp"
//#include <iostream>
//#include <string>
using namespace std;
//#include "pokeClassImp.cpp"

//typedef string (*functionPtr)(Poke& t);

class Poke {
protected:
	typedef string (*functionPtr)(Poke* t);
	//friend string dummy();

	int health=1;
	
	bool inBattle = false;
	string name;
	string pokemon;
	functionPtr attackList[4] = {nullptr};

public:
	Poke(int h, string n = "", string p = "") : name(n), pokemon(p) { health = h; }

	Poke(functionPtr pF[4], int h , string n = "", string p = "") : name(n), pokemon(p) {
		health = h;
		if (pF[0] != nullptr) {
			for (int i = 0; i < 4 && pF[i] != nullptr; ++i) {
				attackList[i] = pF[i];
			}
		}
	}
	Poke(functionPtr pF, int h, string n = "", string p = "") : name(n), pokemon(p) {
		health = h;
		if (pF != nullptr)
			attackList[0] = pF;
	}

	~Poke() {}

	virtual string attack(Poke* p[], int attNum, int attTarget) = 0;
	
	string getName();
	int getHealth() { return health; }
	void setHealth(int n);
	void setAttacks();
	void displayAttacks();
	string getAttackName(int attNum);
	functionPtr getAttack(int attNum);

};

#endif