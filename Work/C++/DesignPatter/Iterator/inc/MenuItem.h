#ifndef	_MENUITEM_H_
#define	_MENUITEM_H_

#include <iostream>
#include "../../../mainLib/inc/devCIterator.h"
using namespace std;

class MenuItem{
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
};

typedef Container<MenuItem*> Menu;
//Agregado concreto(Coleção de objetos)
class PancakeHouseMenu:public Menu{
	public:
	map <string,MenuItem*> *menuitems;
	public:
	PancakeHouseMenu();
	void addItem(string name,string description,bool vegetarian,double price);
	Iterator<MenuItem*>* CreateIterator();
};

//Agregado concreto(Coleção de objetos)
class DinerMenu:public Menu{
	public:
	static const int MAX_ITEMS = 6;
	MenuItem* menuitems[MAX_ITEMS];
	public:
	DinerMenu();
	void addItem(string name,string description,bool vegetarian,double price);
	Iterator<MenuItem*>* CreateIterator();
};


#endif