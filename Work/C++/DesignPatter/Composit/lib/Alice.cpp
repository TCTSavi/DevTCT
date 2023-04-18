#include "../inc/Alice.h"

Alice::Alice(MenuComponent* allMenus){
	this->allMenus = allMenus;
}	 

void Alice::printMenu(){
	allMenus->print();
}
