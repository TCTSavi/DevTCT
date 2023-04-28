#include "CApp.h"

enum {
	CHEESE = 0,
	GREEK,
	PEPPERONI,
};

class Pizza{
	public:
		virtual void prepare(){}
		virtual void bake(){}
		virtual void cut(){}
		virtual void box(){}
};

class CheesePizza:public Pizza{
		void prepare(){
			cout <<"Prepara CheesePizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha CheesePizza"<<endl;
		}
		void cut(){
			cout <<"Corta CheesePizza"<<endl;
		}
		void box(){
			cout <<"Embala CheesePizza"<<endl;
		}
};

class GreekPizza:public Pizza{
		void prepare(){
			cout <<"Prepara GreekPizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha GreekPizza"<<endl;
		}
		void cut(){
			cout <<"Corta GreekPizza"<<endl;
		}
		void box(){
			cout <<"Embala GreekPizza"<<endl;
		}
};

class PepperoniPizza:public Pizza{
		void prepare(){
			cout <<"Prepara PepperoniPizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha PepperoniPizza"<<endl;
		}
		void cut(){
			cout <<"Corta PepperoniPizza"<<endl;
		}
		void box(){
			cout <<"Embala PepperoniPizza"<<endl;
		}
};

class SimplePizzaFactory{
	public:
	Pizza* CreatePizza(int type){
		Pizza *pizza =NULL;
		switch (type){
			case CHEESE:
				pizza = new CheesePizza();
			break;
			case GREEK:
				pizza = new GreekPizza();
			break;
			case PEPPERONI:
				pizza = new PepperoniPizza();
			break;
			default:
			break;
		}
		return pizza;
	}	
};

class PizzaStore{
	private:
		SimplePizzaFactory *PizzaFactory_ = NULL;
	public:
		PizzaStore(SimplePizzaFactory *PizzaFactory):PizzaFactory_(PizzaFactory){}
		Pizza* OrderPizza(int type){
			Pizza *pizza = NULL;
			pizza = PizzaFactory_->CreatePizza(type);
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			pizza->box();
			return pizza;
		}
};

int main(){
	SimplePizzaFactory Factory;
	PizzaStore Store(&Factory);
	Pizza *pizza = NULL;
	pizza = Store.OrderPizza(CHEESE);
	return 0;
}