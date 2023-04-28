#include	"Capp.h"

class IObserver{
	public:
		virtual 	void 	update(float temp,float humidity,float pressure) =0;
};

class ISubject{
	public:
		virtual 	void 	registerObserver(IObserver *o) =0;
		virtual 	void 	removeObserver(IObserver *o) =0;
		virtual 	void 	notifyObserver() =0;
};

class Subject: public ISubject{
	private:
		static 		list<IObserver*> ListObserver;
					float 	temp;
					float 	humidity;
					float 	pressure;
	public:
		void 	registerObserver(IObserver *o){
				ListObserver.push_back(o);
		}
		void 	removeObserver(IObserver *o){
				ListObserver.remove(o);
		}
		void 	notifyObserver(){
			list<IObserver*>::iterator It= ListObserver.begin();
			while (It != ListObserver.end() )
			{	
				(*It)->update(temp,humidity,pressure);
				It++;
			}
		}
	public:		
					void 	getTemperature();
					void 	getHumidity();
					void 	getPressure();
	public:		
					void	measurementsChanged(float t,float h,float p){
							temp = t;
							humidity = h;
							pressure = p;
							notifyObserver();
					};
};

list<IObserver*> Subject::ListObserver;

class Observer: public IObserver{
	private:
		Subject* Sub_;
		float temp;
		float humidity;
		float pressure;
		static int ObserC;
		int Key;

	public:
		Observer(Subject *Sub):Sub_(Sub){
			this->Sub_->registerObserver(this);
			cout<<"Acabei de me registrar no subject"<<endl;
			Key = ++ObserC;
		}
		void 	update(float temp,float humidity,float pressure){
			this->temp = temp;
			this->humidity = humidity;
			this->pressure = pressure;
			Display();
		}
		void RemoveFromSub(){
			cout<<"Acabei de sair fora do subject"<<endl;
			Sub_->removeObserver(this);
		}
		void Display(){
			cout<<"Ei eu sou o observador" << Key <<", olha:Temperatura->"<<temp<<" humidity->"<<humidity<<" pressure->"<<pressure<<endl;
		}					
};
int Observer::ObserC = 0;

int main(){
	Subject *Sub01 = new Subject;
	Observer Obser01(Sub01);
	Sub01->measurementsChanged(24,10,0.9);
	Observer Obser02(Sub01);
	Sub01->measurementsChanged(20,9,1.1);
	Observer Obser03(Sub01);
	Sub01->measurementsChanged(25,11,1.2);
	Obser01.RemoveFromSub();
	Sub01->measurementsChanged(30,15,2);
	Obser01.Display();
	return 0;
}