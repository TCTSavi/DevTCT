#ifndef	_MENUCOMPONENT_H_
#define	_MENUCOMPONENT_H_

//Extern library
#include <iostream>
//Main library
#include "../../../mainLib/inc/devCIterator.h"
#include "../inc/CompositeIterator.h"
//Work library

using namespace std;

//Cliente
class MenuComponent {
	public:
	class UnsupportedOperationException{};
	virtual string getName(){
		throw UnsupportedOperationException();
	}
	virtual string getDescription(){
		throw UnsupportedOperationException();
	}
	virtual double getPrice(){
		throw UnsupportedOperationException();
	}
	//Poderia implementar um retorno padrao false
	virtual bool isVegetarian(){
		throw UnsupportedOperationException();
	}
	virtual void print(){
		throw UnsupportedOperationException();
	}
	virtual void add(MenuComponent *menuComponent) {
		throw UnsupportedOperationException();
	}
	virtual void remove(MenuComponent *menuComponent) {
		throw UnsupportedOperationException();
	}
	virtual MenuComponent* getChild(int i) {
		throw UnsupportedOperationException();
	}
	virtual Iterator<MenuComponent*>* CreateIterator(){
		throw UnsupportedOperationException();
	}
	virtual MenuComponent* getComponent(){
		throw UnsupportedOperationException();
	}	
};

#endif