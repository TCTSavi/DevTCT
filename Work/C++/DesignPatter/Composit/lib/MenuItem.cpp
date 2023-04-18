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
void MenuItem::print(){
	cout << "    "<< getName() << ", ";
	if (isVegetarian()){
		cout << "(V)"<< ", ";
	}
	cout << getPrice()  << ", ";
	cout << getDescription()  << endl;
}

MenuComponent* MenuItem::getComponent(){
	return NULL;
}

Iterator<MenuComponent*>* MenuItem::CreateIterator(){
	Iterator<MenuComponent*> *it = new NullIterator<MenuComponent*>();
	return it;
}

Menu::Menu(string name,string description){
	menuComponents = new list<MenuComponent*>;
	this->description = description;
	this->name = name;
}

string Menu::getName(){
	return	name;
}
string Menu::getDescription(){
	return	description;
}

void Menu::add(MenuComponent *menuComponent) {
	menuComponents->push_back(menuComponent);
}

void Menu::remove(MenuComponent *menuComponent){
	menuComponents->remove(menuComponent);
}

MenuComponent* Menu::getChild(int i){
	list<MenuComponent*>::iterator it= menuComponents->begin();
	advance(it,i);
	if (*it == NULL){
		throw UnsupportedOperationException();	
	}
	return	*it;
}

void Menu::print(){
	cout << endl << getName() << ", ";
	cout << getDescription()  << endl;
	cout << "-----------------------------" << endl;
	Iterator<MenuComponent*> *it = new ListIterator<MenuComponent*>(menuComponents);
	while(!it->IsDone()){
		MenuComponent *menuComponent = it->GetCurrent();
		menuComponent->print();
		it->Next();
	}
}

MenuComponent* Menu::getComponent(){
	return this;
}

Iterator<MenuComponent*>* Menu::CreateIterator(){
	Iterator<MenuComponent*> *it = new CompositeIterator<MenuComponent*>(new ListIterator<MenuComponent*>(menuComponents));
	return it;
}
