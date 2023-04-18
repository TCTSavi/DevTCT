#include "Capp.h"

int main(){

	MenuComponent *pancakeHouseMenu = new Menu("Pancake House Menu","Breakfast");
	MenuComponent *dinnerMenu = new Menu("Dinner Menu","Lunch");
	MenuComponent *cafeMenu = new Menu("Cafe Menu","Dinner");
	MenuComponent *dessertMenu = new Menu("Dessert Menu","Dessert of course!");

	MenuComponent *allMenus = new Menu("All Menus","All menus combined");
		allMenus->add(pancakeHouseMenu);
		allMenus->add(dinnerMenu);
		allMenus->add(cafeMenu);

	pancakeHouseMenu->add(new MenuItem("K&B Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99));
	pancakeHouseMenu->add(new MenuItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99));
	pancakeHouseMenu->add(new MenuItem("Regular Pancake Breakfast","Pancakes with fried eggs, sausage",false,2.99));
	pancakeHouseMenu->add(new MenuItem("Blueberry Pancakes","Pancakes made with fresh blueberries",true,3.49));
	pancakeHouseMenu->add(new MenuItem("Waffles","Waffles with your choice of blueberries or strawberries",true,3.59));

	dinnerMenu->add(new MenuItem("Vegetarian BLT","Fakin Bacon with lettuce and tomato on whole wheat",true,2.99));
	dinnerMenu->add(new MenuItem("BLT","Bacon with lettuce and tomato on whole wheat",false,2.99));
	dinnerMenu->add(new MenuItem("Soup of the day","Soup of the day, with a side of potato salad",false,3.29));
	dinnerMenu->add(new MenuItem("Hotdog","A hot dog, with saurkraut, relish, onions, topped with cheese", false,3.05));
		dinnerMenu->add(dessertMenu);		

	cafeMenu->add(new MenuItem("Vegie Burger and Fries","Veggie burger on a whole wheat bun, lettuce, tomato, and fries",true,3.99));
	cafeMenu->add(new MenuItem("Soup of the day","A cup of soup of the day, with a side salad",false,3.69));
	cafeMenu->add(new MenuItem("Burrito","A large burrito, with whole pinto beans, salsa and guacamole",true,4.29));

	dessertMenu->add(new MenuItem("Apple pie","Apple pie with a flakey crust, topped with vanilla ice cream",true,1.59));
	dessertMenu->add(new MenuItem("Banana pie","Banana pie with a flakey crust, topped with vanilla ice cream",true,2.59));
	dessertMenu->add(new MenuItem("Pineapple pie","Pineapple pie with a flakey crust, topped with vanilla ice cream",true,3.59));

	Alice *alice = new Alice(allMenus);
	alice->printMenu();

	Iterator<MenuComponent*> *it = allMenus->CreateIterator();
	//while( !it->IsDone() ){
	//	MenuComponent* component = it->GetCurrent();
	//	cout << component->getName() << endl;
  	//	it->Next();
	//}

	cout << endl << " VEGETARIAN MENU"<< endl << "-------------" <<endl;
	while( !it->IsDone() ){
		MenuComponent* component = it->GetCurrent();
		try{
			if (component->isVegetarian()){
				component->print();
			}
		}catch ( MenuComponent::UnsupportedOperationException ){
		}
  		it->Next();
	}




	return 0;
}
