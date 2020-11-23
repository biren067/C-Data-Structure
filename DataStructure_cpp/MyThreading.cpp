#include "stdafx.h"
#include "MyThreading.h"


MyThreading::MyThreading()
{
	//condition_variable_initial();
	diff_way_of_thread();
}
void MyThreading::Threading_1(int n){
	for (int i = 1; i <= n; i++)
		cout << i << " ";
	cout << endl;
}
void MyThreading::Threading_2(int m){
	int l = m + 100;
	for (int i = 100; i < l; i++)
		cout << i << " ";
	cout << endl;
}
//....................Thread Initialization START
class FunctionObject{
public:
	void operator()(int x){
		cout << "Functor: operator() get overloaded" << x << endl;
		cout << endl;
	}
};
void funPointer(int x){
	for (int i = 0; i < x; i++)
		cout << i << " ";
	cout << endl;
}
void MyThreading::diff_way_of_thread(){
	//1. Create thread by function pointer
	cout << "1. Create thread by function pointer" << endl;
	thread t1(&MyThreading::Threading_1,this,10);
	t1.join();
	//2. Create Thread by function pointer
	cout << "2. Create Thread by function pointer" << endl;
	thread t2(&MyThreading::Threading_2, 5);
	t2.join();
	//3. Create Thread by lambda function
	cout << "3. Create Thread by Lambda Function" << endl;
	thread t3([](int param){ for (int i = 0; i < param; i++) cout << param << " "; cout << endl; }, 10);
	t3.join();
	//4. Create Thread by Functor
	cout << "4. Create FunctionObject" << endl;
	thread t4(FunctionObject(), 5);
	t4.join();
	//5. Create Thread by function pointer
	cout << "5. Create Thread by function pointer" << endl;
	thread t5(funPointer, 10);
	t5.join();
}
//.................Threding initialization END
void MyThreading::withdraw(int money){
	//unique_lock<mutex> ul(m1);
	//cv.wait(ul, [](int amount,int  money){ return (amount > money ? true : false); });
	//if (money < amount){
	//	amount -= money;
	//}
	//else{
	//	cout << "Money is not available to withdraw";
	//}
	//cout <<endl<< "Withdraw done" << endl;
}
void MyThreading::deposit(int money){
	//lock_guard<mutex> lg(m1);
	//amount += money;
	//cout << "Money is deposited" << endl;
	//cout << "Deposit" << endl;
	//cv.notify_one();
}
void MyThreading::condition_variable_initial(){
	int amount = 500;
	thread t1(&MyThreading::withdraw,this, amount);
	thread t2(&MyThreading::deposit,this, amount);
	t1.join();
	t2.join();
}
MyThreading::~MyThreading()
{
}
