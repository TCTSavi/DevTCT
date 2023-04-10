#include "Capp.h"

MenuItem::MenuItem(string name,string description,bool vegetarian,double price){
	this->description = description;
	this->name = name;
	this->vegetarian= vegetarian;
	this->price = price;
}
string MenuItem::getName(){
	return	name;
}
string MenuItem::getDescription(){
	return	description;
}
bool MenuItem::isVegetarian(){
	return	vegetarian;
}
double MenuItem::getPrice(){
	return	price;
}

PancakeHouseMenu::PancakeHouseMenu(){
	menuitems = new map <string,MenuItem*>;
	addItem("K&B Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99);
	addItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99);
	addItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49);
	addItem("Waffles","Waffles with your choice of blueberries or strawberries",true,3.59);
}

void PancakeHouseMenu::addItem(string name,string description,bool vegetarian,double price){
	MenuItem* tempMenu = new MenuItem(name,description,vegetarian,price);
	(*menuitems)[tempMenu->getName()] = tempMenu;
}

Iterator<MenuItem*>* PancakeHouseMenu::CreateIterator(){
	Iterator<MenuItem*> *it = new MapIterator<string,MenuItem*>(menuitems);
	return it;
}

int main(){
	Menu* LousMenu = new PancakeHouseMenu;
	vector <Menu*> Menus;
	Menus.push_back(LousMenu);
	Alice Ali01(&Menus);
	Ali01.printMenu();
	int i;
	return 0;
}
