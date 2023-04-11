#include "../inc/Alice.h"

Alice::Alice(vector <Menu*> *Menus){
	this->Menus = Menus;
}	 

void Alice::printMenu(){
	for(int i =0;i < Menus->size();i++){
		Iterator<MenuItem*>* MenuIterator = (*Menus)[i]->CreateIterator();
		printMenu(MenuIterator);
		cout << endl;
	}
}

void Alice::printMenu(Iterator<MenuItem*>* it){
	while(!it->IsDone()){
		MenuItem *item = it->GetCurrent();
		it->Next();
		cout << item->getName()  << ", ";
		cout << item->getPrice()  << ", ";
		cout << item->getDescription()  << endl;
	}
}
