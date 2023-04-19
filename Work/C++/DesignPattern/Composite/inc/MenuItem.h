#ifndef	_MENUITEM_H_
#define	_MENUITEM_H_

#include <iostream>
#include "../../../mainLib/inc/devCIterator.h"
#include "../inc/MenuComponent.h"
#include "../inc/CompositeIterator.h"
#include "../inc/NullIterator.h"
using namespace std;

class MenuItem:public MenuComponent{
	private:
	string name;
	string description;
	bool vegetarian;
	double price;
	public:
	MenuItem(string name,string description,bool vegetarian,double price);
	string getName();
	string getDescription();
	bool isVegetarian();
	double getPrice();
	void print();
	MenuComponent* getComponent();
	Iterator<MenuComponent*>* CreateIterator();
};

class Menu:public MenuComponent{
	private:
	list<MenuComponent*>* menuComponents;
	string name;
	string description;
	public:
	Menu(string name,string description);
	void print();
	string getName();
	string getDescription();
	void add(MenuComponent *menuComponent);
	void remove(MenuComponent *menuComponent);
	MenuComponent* getChild(int i);
	MenuComponent* getComponent();
	Iterator<MenuComponent*>* CreateIterator();
};
#endif