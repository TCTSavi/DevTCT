#ifndef	_CAPP_H_
#define	_CAPP_H_

#include <iostream>
#include <vector>
#include <string>
#include "../../mainLib/inc/devCIterator.h"

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

//Cliente
class Alice {
	public:
	Alice(vector <Menu*> *Menus){
		this->Menus = Menus;
	} 
	void printMenu(){
		for(int i =0;i < Menus->size();i++){
			Iterator<MenuItem*>* MenuIterator = (*Menus)[i]->CreateIterator();
			printMenu(MenuIterator);
			cout << endl;
		}
	}
	private:
	//PancakeHouseMenu *LousMenu;
	//DinerMenu *MelsMenu;
	vector <Menu*> *Menus;

	void printMenu(Iterator<MenuItem*>* it){
		while(!it->IsDone()){
			MenuItem *item = it->GetCurrent();
			it->Next();
			cout << item->getName()  << ", ";
			cout << item->getPrice()  << ", ";
			cout << item->getDescription()  << endl;
		}
	}
};


#endif