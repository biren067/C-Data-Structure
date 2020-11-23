#pragma once
#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;
class FunctionObject;
class MyThreading
{
private:
	mutex m1;
	condition_variable cv;
	int amount = 0;
public:
	MyThreading();
	void condition_variable_initial();
	void diff_way_of_thread();
	void Threading_1(int);
	void static Threading_2(int);
	void deposit(int);
	void withdraw(int);
	~MyThreading();
};

