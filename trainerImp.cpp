#include <iostream>
#include "pokeClass.h"
using namespace std;
#include "trainer.h"

bool trainer::getdBattle() {
	return dBattle;
}

void trainer :: setFainted(bool b) {
	fainted = b;
}

bool trainer::getFainted() {
	return fainted;
}


int trainer:: getTotalBatPoke(){
	int j = 0;
	for (int i=0; i < 6; ++i) {
		if (pokemon[i] == nullptr) {
			continue;
		}
		if (pokemon[i]->getHealth() > 0) {
			++j;
		}
	}
	if (j == 0) {
		setFainted(true);
	}
	return j;
}

string trainer::getName() {
	return name;
}