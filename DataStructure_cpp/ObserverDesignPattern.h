#pragma once
#include <string>
#include <iostream>
#include <list>
class Observer{
public:
	virtual void update(std::string) = 0;
};
class Van :public Observer{
public:
	virtual void update(std::string s);
};
class Truck :public Observer{
public:
	virtual void update(std::string s);
};
//================subject
class Subject{
private:
	std::list<Observer *> ob;
public:
	void addVehicle(Observer* obj);
	void updateVehicle(std::string name);
};
class ObserverDesignPattern
{
public:
	ObserverDesignPattern();
	~ObserverDesignPattern();
};

