#include "stdafx.h"
#include "ObserverDesignPattern.h"


ObserverDesignPattern::ObserverDesignPattern()
{
	Subject sb;
	Observer *ob1 = new Van();
	Observer *ob2 = new Truck();
	sb.addVehicle(ob1);
	sb.addVehicle(ob2);
	sb.updateVehicle("Bangalore");
}


ObserverDesignPattern::~ObserverDesignPattern()
{
}

void Van::update(std::string s){
		std::cout << "Van is moved to " << s << std::endl;
}

void Truck::update(std::string s){
		std::cout << "Truck is moved to " << s << std::endl;
}

void Subject::addVehicle(Observer* obj){
	ob.push_back(obj);
}
void Subject::updateVehicle(std::string name){
	std::list<Observer*>::iterator it;
	for (it = ob.begin(); it != ob.end(); it++){
		(*it)->update(name);
	}
}