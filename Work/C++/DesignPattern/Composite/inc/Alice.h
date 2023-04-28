#ifndef	_ALICE_H_
#define	_ALICE_H_

//Extern library
#include <iostream>
//Main library
#include "../../../mainLib/inc/devCIterator.h"
//Work library
#include "../inc/MenuItem.h"
#include "../inc/MenuComponent.h"

using namespace std;

//Cliente
class Alice {
	private:
	MenuComponent* allMenus;
	public:
	Alice(MenuComponent* allMenus);
	void printMenu();
};

#endif