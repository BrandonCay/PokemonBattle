#pragma once



#ifndef charC_H
#define charC_H

class Charmander :public Poke {
	/*
		int health;
		string name;
		string pokemon;
		*/
	public:
		Charmander(int h = 0, string n = "", string p = ""):Poke(h,n,p)/*,health(h), name(n), pokemon(p)*/ {}
		Charmander(functionPtr pF[4], int h = 0, string n = "", string p = "") :Poke(pF,h,n,p) {}
		Charmander(functionPtr pF, int h = 0, string n = "", string p = "") : Poke(pF,h,n,p){}


		string attack(Poke* p[], int attNum, int attTarget);
		int getHealth();
		virtual ~Charmander() {}
	};

#endif