#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include "pokeClass.h"
#include "charmanderClass.h"
#include "player.h"
#include "NPCtrainer.h"
#include "movePool.h"
using namespace std;
typedef string(*functionPtr)(Poke& t);


bool checkHealth(Poke* inBat[]); 
int pTurn(trainer& t, trainer& t2, Poke& currPoke, Poke* inBat[], int tCnt, int t2Cnt); 
int NPCturn(trainer& t, trainer& t2, Poke& currPoke, Poke* inBat[], int tCnt, int t2Cnt); 
void DnSup();
void healthDisplayBat(Poke* pInBat[]);
bool checkdbattleNPC(trainer& oppNPC);
void NPCbattle(trainer& p1, trainer& oppNPC);


	//while () {
	//Fight sequence/exchanging data
	
	//}
	//p1.attack=



/*
Upcasting derived obj only allows access to the methods of the derivedwhile the data members are the baseclass'. To overcome this, I recognized that a derived class' 
object has seperate base class members because ,to put it simply, a derived object is also base class obj in the sense that there are two objects from the base and 
derived that make up the derived object therefore to apply changes to the derived class' members one must use the base class' members instead that are within the derived obj.
Now one can apply changes to individual objects generally while using the derived class' methods
*/

int re() {
	int a;
	cout << "inp" << endl;
	cin >> a;
	return a;
}
void be(int a) {
	cout << a << endl;
}

void te1(int* p[], int &a) {
	p[0] = &a;
}

int main() {
	
	Charmander obj(tackle, 100, "Charmander", "Charmander");
	Charmander obj2(tackle, 100, "Charmander", "Charmy");
	player r(obj);
	NPCtrainer n(obj2);
	NPCbattle(r, n);


	/*
	functionPtr p = dummy;
	Charmander obj(dummy, 100, "Charmander", "Charmander");
	int am = 1, bm = 2;
	int* a = nullptr , * b=nullptr;
	int* q[2] = {a,b};
	int*& p1 = q[0];
	*/
	//int* p[1];




	/* returns array size
	if (sizeof(p) / sizeof(*p) == 1) {
		cout << "same" << endl;
	}
	*/
	/* sending array to function works like reference b/c it sends base address
	int b = 1;
	int c = 3;
	p[0] = &b;
	te1(p, c);
	cout << *p[0] << endl;
	*/


	/*
	//These work
	
	battle(obj);
	obj.attack1();
	battle(obj);
	Poke* p = &obj;
	p->attack1();
	be(re());
	*/
	

	return 0;
}

/*bool checkHealth(Poke* inBat[]) {
	for (int i = 0; i < sizeof(inBat) / sizeof(*inBat); ++i) {
		if (inBat[i]->getHealth() < 0) {
			return true;
		}
	}
	return false;
}*/



int pTurn(trainer& t, trainer& t2, Poke& currPoke, Poke* inBat[], int tCnt, int t2Cnt) {

	int c = 0;

	cout << "1. Attack" << endl;
	cout << "2. Bag" << endl;
	cout << "N/A" << endl;
	cout << "N/A" << endl<<endl;
	cout << "What will you do (enter either 1-2): ";
	cin >> c;

	while (c <= 0 || c > 2) {
		cout << "Try again: ";
		cin >> c;
	}

	switch (c) {
	case 1:
		t.attack(currPoke, inBat);
		//cout << currPoke.getName() << "used" << currPoke.;
		break;
	case 2:
		t.bag();
		break;
	}

	if (inBat[0]->getHealth() == 0) {//player pokemon faints
		cout << inBat[0]->getName() << " has " << "fainted" << endl;
		tCnt -= 1;
		if (tCnt != 0) {
			cout << "Choose which pokemon to send out: " ;
				t.swap(inBat);
			cout << t.getName() << " chose " << inBat[0]->getName() << endl;
			string pass;
			cout << "Enter Anything to Pass: ";
			cin >> pass;
			return 1;
		}

		cout << t.getName() << " no more pokemon to battle." << t2.getName() << " wins" << endl;
		string pass;
		cout << "Enter Anything to Pass: ";
		cin >> pass;
		return 0;
	}
	else if (inBat[1]->getHealth() == 0) {//NPCopp pokemon faints
		t2Cnt -= 1;
		cout << inBat[1]->getName() << " has " << "fainted" << endl;

		if (t2Cnt != 0) {
			t2.swap(inBat);
			cout << t2.getName() << " chose " << inBat[1]->getName() << endl;
			string pass;
			cout << "Enter Anything to Pass: ";
			cin >> pass;
			return 1;
		}
		cout << t2.getName() << " no more pokemon to battle." << t.getName() << " wins" << endl;
		string pass;
		cout << "Enter Anything to Pass: ";
		cin >> pass;
		return 0;
	}
	else {//none faint. battle continues
		return 1;
	}
	
}



int NPCturn(trainer& t, trainer& t2, Poke& currPoke, Poke* inBat[], int tCnt, int t2Cnt) {
	srand(time(NULL));
	int rng = rand();
	cout << "RNG" << rng << endl;
	int c = 1 + rng % 2;
	cout <<endl<< "c"<<c << endl;

	switch (c) {
	case 1:
		t2.attack(currPoke, inBat);
		cout << endl << "NPC attacked" << endl;
		break;
	case 2:
		cout << endl << "NPC checked bag" << endl;
		t2.bag();
		break;
	}

	if (inBat[0]->getHealth() == 0) {//player pokemon faints
		cout <<inBat[0]->getName() << " has " << "fainted" << endl;
		tCnt -= 1;
		if (tCnt != 0) {
			cout << "Choose which pokemon to send out: ";
			t.swap(inBat);
			cout << t.getName() << " chose " << inBat[0]->getName() << endl;
			string pass;
			cout << "Enter Anything to Pass: ";
			cin >> pass;
			return 1;
		}

		cout << t.getName()<<" no more pokemon to battle."<< t2.getName()<<" wins"<< endl;
		string pass;
		cout << "Enter Anything to Pass: ";
		cin >> pass;
		return 0;
	}
	else if (inBat[1]->getHealth() == 0) {//NPCopp pokemon faints
		t2Cnt -= 1;
		cout << inBat[1]->getName() << " has " << "fainted" << endl;

		if (t2Cnt != 0) {
			t2.swap(inBat);
			cout << t2.getName() << " chose " << inBat[1]->getName() << endl;
			string pass;
			cout << "Enter Anything to Pass: ";
			cin >> pass;
			return 1;
		}
		cout << t2.getName()<<" no more pokemon to battle."<< t.getName()<<" wins"<< endl;
		string pass;
		cout << "Enter Anything to Pass: ";
		cin >> pass;
		return 0;
	}
	else {//none faint. battle continues
		return 1;
	}
}


void DnSup() {
	cout << "double battle not supported" << endl;
}
void healthDisplayBat(trainer &t1, trainer &t2, Poke* pInBat[]) {

	if (sizeof(pInBat) / sizeof(*pInBat) < 4) {
		cout << "Trainer: " << t1.getName()<<endl;
		cout <<"1. "<< pInBat[0]->getName() << " " << pInBat[0]->getHealth() << endl;
		cout << "Trainer: " << t2.getName() << endl;
		cout <<"2. "<< pInBat[1]->getName() << " " << pInBat[1]->getHealth() << endl<<endl;
	}
	else {
		DnSup();
	}

}
bool checkdbattleNPC(trainer& oppNPC) {
	if (oppNPC.getdBattle() == true) {
		return true;
	}
	return false;

}
void NPCbattle(trainer& p1, trainer& oppNPC) {//1.needs to choose whether to attack or do something 2.continue until all of the player's pokemon are defeated
	int dbatflg = checkdbattleNPC(oppNPC);
	cout << "Trainer " << oppNPC.getName() << " challenges " << p1.getName()<<endl;
	if (dbatflg == false) {
		Poke* inBattle[2] = { nullptr };
		inBattle[0] = p1.startPoke();
		inBattle[1] = oppNPC.startPoke();
		int totalBatPokeP1 = p1.getTotalBatPoke();
		int totalBatPokeNPC = oppNPC.getTotalBatPoke();



		while (p1.getFainted() == false && oppNPC.getdBattle() == false) {
			healthDisplayBat(p1, oppNPC, inBattle);
			if (!(pTurn(p1, oppNPC, *inBattle[0], inBattle, totalBatPokeP1, totalBatPokeNPC))) {
				healthDisplayBat(p1, oppNPC, inBattle);
				break;
			}
			system("cls");
			healthDisplayBat(p1, oppNPC, inBattle);
			if (!(NPCturn(p1, oppNPC, *inBattle[0], inBattle, totalBatPokeP1, totalBatPokeNPC))) {
				healthDisplayBat(p1, oppNPC, inBattle);
				break;
			}
			system("cls");






		}




	}
	else {

		DnSup();
		return;

	}
	//while () {
	//Fight sequence/exchanging data

	//}
	//p1.attack=

}