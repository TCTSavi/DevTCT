#ifndef	_CAPP_H_
#define	_CAPP_H_

#include <iostream>
#include <vector>
#include <string>
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
#include "inc/devCIterator.h"

template class Iterator<MenuItem*>;

typedef Container<MenuItem*> Menu;
//Agregado concreto(Coleção de objetos)
class PancakeHouseMenu:public Menu{
	public:
	vector <MenuItem*> *menuitems;
	public:
	PancakeHouseMenu();
	void addItem(string name,string description,bool vegetarian,double price);
	Iterator<MenuItem*>* CreateIterator();
};

#endif