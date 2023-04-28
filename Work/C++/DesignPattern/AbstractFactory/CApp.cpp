#include "CApp.h"

enum {
	CHEESE = 0,
	GREEK,
	PEPPERONI,
};


class Cheese{
	public:
		virtual string StyleCheese()=0;
};

class ChicagoStyleCheesePizza:public Cheese{
	public:
		string StyleCheese(){
			return "queijo de Chicago";
		}
};

class NYStyleCheesePizza:public Cheese{
	public:
		string StyleCheese(){
			return "queijo de NY";
		}
};

class Souce{
	public:
		virtual string StyleSouce()=0;
};

class ChicagoStyleSoucePizza:public Souce{
	public:
		string StyleSouce(){
			return "molho de Chicago";
		}
};

class NYStyleSoucePizza:public Souce{
	public:
		string StyleSouce(){
			return "molho de NY";
		}
};

class PizzaIngredientFactory{
	public:
	virtual Cheese* CreateCheese() = 0;
	virtual Souce* CreateSouce() = 0;
};

class Pizza{
	public:
		Cheese* chesse;
		Souce* souce;
	public:
		virtual void prepare(){}
		virtual string bake(){
			return "Assa a pizza de "+ chesse->StyleCheese() + " com "+ souce->StyleSouce();
		}
		virtual string cut(){
			return "Corta a pizza de "+ chesse->StyleCheese() + " com "+ souce->StyleSouce();
		}
		virtual string box(){
			return "Embala a pizza de "+ chesse->StyleCheese() + " com "+ souce->StyleSouce();
		}
};

class ChicagoPizzaIngredientFactory:public PizzaIngredientFactory{
	public:
	Cheese* CreateCheese(){
		return new ChicagoStyleCheesePizza;
	}
	Souce* CreateSouce(){
		return new ChicagoStyleSoucePizza;
	}
};

class NyPizzaIngredientFactory:public PizzaIngredientFactory{
	public:
	Cheese* CreateCheese(){
		return new NYStyleCheesePizza;
	}
	Souce* CreateSouce(){
		return new NYStyleSoucePizza;
	}
};

//Classe cliente
class PizzaStore:public Pizza{
	private:
		PizzaIngredientFactory *Factory_; 
	public:
		PizzaStore(PizzaIngredientFactory *Factory ):Factory_(Factory){}
	public:
	void prepare(){
		chesse = Factory_->CreateCheese();
		souce = Factory_->CreateSouce();
	}
};

int main(){
//Aqui tbm acabou sendo parte do codigo cliente
	PizzaIngredientFactory *Factory = new ChicagoPizzaIngredientFactory;
	PizzaStore *Store = new PizzaStore(Factory);
	Store->prepare();
	cout << Store->bake() << endl;
	cout << Store->cut() << endl;
	cout << Store->box() << endl;


	return 0;
}