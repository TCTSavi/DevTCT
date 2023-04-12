#include "../inc/MenuItem.h"

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

DinerMenu::DinerMenu(){
		numberOfItems = 0;
		addItem("Vegetarian BLT","Fakin Bacon with lettuce and tomato on whole wheat",true,2.99);
		addItem("BLT","Bacon with lettuce and tomato on whole wheat",false,2.99);
		addItem("Soup of the day","Soup of the day, with a side of potato salad",false,3.29);
		addItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese", false,3.05);
		addItem();
}

void DinerMenu::addItem(string name,string description,bool vegetarian,double price){
	MenuItem *tempMenu = new MenuItem(name,description,vegetarian,price);
	if (numberOfItems >= MAX_ITEMS){
		cout << "Sorry, menu is full! Can't add item to menu" << endl;
	}
	else{
		menuitems[numberOfItems] = tempMenu;
		numberOfItems++;
	}
}
void DinerMenu::addItem(){
	MenuItem *tempMenu = NULL;
	if (numberOfItems >= MAX_ITEMS){
		cout << "Sorry, menu is full! Can't add item to menu" << endl;
	}
	else{
		menuitems[numberOfItems] = tempMenu;
		numberOfItems++;
	}
}


Iterator<MenuItem*>* DinerMenu::CreateIterator(){
	Iterator<MenuItem*> *it = new ArrayIterator<MenuItem*>(menuitems);
	return it;
}
