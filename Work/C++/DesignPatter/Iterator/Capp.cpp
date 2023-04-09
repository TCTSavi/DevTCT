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
	menuitems = new vector <MenuItem*>;
	addItem("K&B Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99);
	addItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99);
	addItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49);
	addItem("Waffles","Waffles with your choice of blueberries or strawberries",true,3.59);
}

void PancakeHouseMenu::addItem(string name,string description,bool vegetarian,double price){
	MenuItem* tempMenu = new MenuItem(name,description,vegetarian,price);
	menuitems->push_back(tempMenu);
}

Iterator<MenuItem*>* PancakeHouseMenu::CreateIterator(){
	Iterator<MenuItem*> *it = new VectorIterator<MenuItem*>(menuitems);
	return it;
}

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

int main(){
	Menu* LousMenu = new PancakeHouseMenu;
	vector <Menu*> Menus;
	Menus.push_back(LousMenu);
	Alice Ali01(&Menus);
	Ali01.printMenu();
	return 0;
}
