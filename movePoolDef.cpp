#include <string>
#include <iostream>
using namespace std;
#include"pokeClass.h"
#include "movePool.h"



string tackle(Poke* t1) {
	if (t1 == nullptr) {
		return "tackle";
	}
	int dmg = 10;
	int newHealth = t1->getHealth() - dmg;
	
	if (t1->getHealth() < 0) {
		t1->setHealth(0);
	}
	else {
		t1->setHealth(newHealth);
	}
	return "tackle";
}
string scratch(Poke* t1) {
	return "scratch";
}
string dummy(Poke* t1) {
	return "dummy";
}