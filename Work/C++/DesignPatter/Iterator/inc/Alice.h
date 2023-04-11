#ifndef	_ALICE_H_
#define	_ALICE_H_

//Extern library
#include <iostream>
//Main library
#include "../../../mainLib/inc/devCIterator.h"
//Work library
#include "../inc/MenuItem.h"

using namespace std;

//Cliente
class Alice {
	public:
	Alice(vector <Menu*> *Menus);
	void printMenu();
	private:
	vector <Menu*> *Menus;
	void printMenu(Iterator<MenuItem*>* it);
};

#endif