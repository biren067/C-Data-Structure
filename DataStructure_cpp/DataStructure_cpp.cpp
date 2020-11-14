// Multithreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <chrono>
#include "Algorithm.h"
using namespace std;
//using namespace Learn_coding;
using namespace std::chrono;
//======================vector Learning
void iterate_reverse();
void normal();
void vectorLearn(){

	//iterate_reverse();
	auto start = chrono::high_resolution_clock::now();
	normal();
}
void normal(){
	vector<int> vec{ 3, 4, 1, 2, 3 };

	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < vec.size(); i++){
		cout << vec.at(i) << " ";
	}
	cout << endl;
	for (auto it = vec.cbegin(); it != vec.cend(); it++){
		cout << *it << " ";
	}

}
void iterate_reverse()
{
	vector<string> vec{ "Biren", "lallu", "Bond" };
	vector<string>::reverse_iterator it;
	for (it = vec.rbegin(); it != vec.rend(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
//======================END Learn vector
void showStack(stack<int> ss){
	while (!ss.empty()){
		cout << ss.top() << " ";
		ss.pop();
	}
	cout << endl;
	cout << "Size in showStack is " << ss.size() << endl;
}
void stackLearn(){
	stack<int> s;
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	stack<int> s1(s);
	s1.push(100);
	s1.swap(s);
	cout << s.empty() << endl;
	cout << s.size() << endl;
	showStack(s);
	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << "Size in " << s.size() << endl;
}
//========================START Queue Learn
void showQueue(queue<int> qq){
	while (!qq.empty()){
		cout << qq.front() << " ";
		qq.pop();
	}
	//qq.push(33);

	cout << "size is " << qq.size() << endl;
}
void queueLearn(){
	queue<int> q({ 4, 3, 2, 1 });
	showQueue(q);
	cout << "size is : " << q.size();
}
//=========================END QUEUE

//=========================START List
bool find_even(const int& n){
	return (n % 2 == 0);
}
void showList(list<int> lst){
	list<int>::iterator it;

	for (it = lst.begin(); it != lst.end(); it++){
		cout << *it << " ";
	}

	cout << endl;
}
void showEvenList(list<int> lst){
	//	lst.remove_if(find_even);
	showList(lst);

}
void find_element(list<int> lst){
	auto it = find(lst.begin(), lst.end(), 33);
	if (it != lst.end())
		cout << "Found";
	else
		cout << "Not Found";
	cout << endl;
}
void insertion(list<int>& lst){
	lst.insert(lst.begin(), 22);
	lst.insert(lst.begin(), 2, 33);
	//lst.insert(lst.begin(), advance(lst, 2), advance(lst, 4));
}
bool fun2(int n){
	return (n % 2 != 0);
}
void listLearn(){
	list<int> lst({ 4, 3, 1, 2, 6 });
	lst.push_back(100);
	lst.push_front(0);
	find_element(lst);
	insertion(lst);
	showList(lst);
	//lst.remove(33);
	lst.remove_if(fun2);
	showList(lst);

}
//=======================END List
//=================SET START
void showSet(set<int>& s);
void setLearn(){
	set<int> ss;
	for (int i = 10; i < 20; i++)
		ss.insert(i);
	ss.insert(13);
	ss.insert(15);
	showSet(ss);
	ss.erase(13);
	cout << ss.count(55);
	cout << endl;
	//showSet(ss);
	auto it = ss.find(10);
	bool b = it != ss.end();
	cout << "Bool is " << b;
	cout << endl;
}
void showSet(set<int>& ss){
	for (auto it = ss.begin(); it != ss.end(); it++){
		cout << *it << " ";
	}
}
//=================SET END
//=================MAP START
void mapLearn(){

	map<int, int> mp;
	int count = 1;
	mp.insert({ 5, 22 });
	mp.insert({ 4, 13 });
	mp.insert({ 3, 14 });
	mp.insert({ 1, 15 });
	mp.insert({ 2, 17 });
	//mp.erase(1);
	//map<int, int>::iterator isExist = mp.find(5);
	//if (isExist != mp.end())
	//{
	//	int i = 9;
	//	mp[5] = mp[5]+i;
	//	cout << mp[5];
	//	cout<<"False";
	//}
	//else 
	//	cout << "True";
	cout << endl;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
		cout << count++ << " " << it->first << "  " << it->second << endl;
	}
}
//=================MAP END
//=================DEQUE START
void dequeLearn(){

	deque<int> dd;
	dd.push_back(22);
	dd.push_back(13);
	dd.push_back(14);
	dd.push_back(32);
	dd.push_back(28);
	deque<int>::iterator it = dd.begin();
	cout << dd.size() << endl;
	dd.erase(it, it + 1);
	for (deque<int>::iterator it = dd.begin(); it != dd.end(); it++){
		cout << *it << " ";
	}
}
//=================DEQUE END 

//=================Singleton class
#include<iostream>
using namespace std;
class Singleton{
private:
	static Singleton* singleton;
	static int count;
	Singleton(){}
public:
	static Singleton* getInstance(){
		if (singleton == NULL)
			singleton = new Singleton();
		count += 1;
		return singleton;
	}
	void print(){
		cout << "no of time singleton object called: " << count << endl;
	}
};

Singleton* Singleton::singleton = NULL;
int Singleton::count = 0;

void Singleton_designPattern(){
	Singleton* s = Singleton::getInstance();
	s->print();
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	s->print();
	s2->print();
}
//=================End singleton

//=================START Observer Design Pattern
class IObserver{

public:
	virtual void update(int) = 0;
};

class Maruti : public IObserver{
private:
	int no_of_feature;
public:
	Maruti(){
		no_of_feature = 0;
	}
	void update(int n){
		no_of_feature += n;
		cout << "MARUTI car get updated, Total Law" << no_of_feature << endl;
	}
};
class Honda : public IObserver{
	int no_of_feature;
public:
	Honda(){
		no_of_feature = 0;
	}
	void update(int n){
		no_of_feature += n;
		cout << "HONDA car get updated, Total Law" << no_of_feature << endl;
	};
};
class Car{
private:
	vector<IObserver*> vec_observer;
	int feature;
public:
	Car(){
		feature = 0;
	};
	void add_observer(IObserver* ob){
		vec_observer.push_back(ob);
	};
	/*void delete_observer(IObserver* ob){
	vec_observer.erase(ob);
	}*/
	void vehicleLawUpdate(int n){
		for (int i = 0; i < vec_observer.size(); i++){
			vec_observer[i]->update(n);
		}

	}
};

void ObserverDesingPattern(){
	Car c;
	Honda *honda = new Honda();
	Maruti *maruti = new Maruti();
	c.add_observer(honda);
	c.add_observer(maruti);
	c.vehicleLawUpdate(1);
	c.vehicleLawUpdate(90);
}
//=================END Observer Desing Pattern
//================START maximum in array with loop
int max_value(int*, int);
void max_in_array_loop(){
	int p[] = { 32, 99, 47, 54, 287, 822, 286, 90 };
	cout << max_value(p, 8) << endl;
}
int max_value(int *arr, int len){
	int max = arr[0];
	for (int i = 1; i < len; i++){
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
//================END maximum in array
//================START maximum in arrary Divide and Conquer(Recursion)
int max_value_recursion(int *, int, int);
void max_in_array_recursion(){
	int p[] = { 32, 99, 47, 54, 227, 22, 286, 90 };
	cout << "Size of Array " << sizeof(p) << endl;
	cout << max_value_recursion(p, 0, 8) << endl;
}
int max_value_recursion(int *p, int begin, int end){
	int max = 0;
	if (begin == end - 2){
		if (p[begin] > p[begin + 1])
			max = p[begin];
		else
			max = p[begin - 1];
		return max;
	}
	else{
		max = max_value_recursion(p, begin + 1, end);
		if (max < p[begin]){
			max = p[begin];
		}
		return max;
	}
}
//================END maximum in arrary Divide and Conquer(Recursion)
//================START power of int recursion
int pow_recursion(int p, int n);
void power_of_int_recursion(){
	cout << pow_recursion(2, 5);
}
int pow_recursion(int p, int n){

	if (n == 1)
		return p;
	else{
		return p * pow_recursion(p, n - 1);
	}
}
//================END power of int
//================START of creating Tree
struct Node
{
	int data;
	struct Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};
struct Node* create_tree(){
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	return root;
}
//========================END of creating tree
//========================START Deepest_right_node_iterative
void deepest_right_node_iterative(){
	struct Node *head = create_tree();
	if (head != NULL){
		for (struct Node* temp = head; temp != NULL; temp = temp->right){
			if (temp->right == NULL)
				cout << temp->data << endl;
		}
	}
}
//========================END Deepest_right_node_iterative
//========================START largest_number_less_than_or_equal_to_N_();
int find_number_less_than_N(struct Node*, int);
void largest_number_less_than_or_equal_to_N_(){
	struct Node* head = create_tree();
	int n = find_number_less_than_N(head, 9);
	cout << "Number less than N is: " << n << endl;
}
int find_number_less_than_N(struct Node *head, int key){

	if (head == NULL){ return 0; }
	if (key < head->data){
		if (head->left != NULL && head->right != NULL){
			//	find_number_less_than_N(head)
		}
	}

}
//========================END largest_number_less_than_or_equal_to_N
//========================START floor_and_ceil_value_from_tree
void floor_and_ceil_value_from_tree(){

}
//========================END floor_and_ceil_value_from_tree
//========================START breath_first_search
void traverse_BFS(struct Node* head);
void breath_first_search(){
	struct Node* head = create_tree();
	traverse_BFS(head);
}
void traverse_BFS(struct Node* head){
	queue<struct Node*> q;
	q.push(head);
	while (!q.empty()){
		struct Node *temp = q.front();
		cout << temp->data << endl;
		q.pop();
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}
//========================END breath_first_search
//======================START construct_binary_search_tree
void constructBST(struct Node* head, int n);
void construct_binary_search_tree(){
	struct Node* head = NULL;
	constructBST(head, 9);
	constructBST(head, 6);
	constructBST(head, 3);
	constructBST(head, 7);
	constructBST(head, 11);
	constructBST(head, 10);
	constructBST(head, 14);
	traverse_BFS(head);
}
void constructBST(struct Node* head, int n){
	struct Node* newNode = new Node(n);
	if (head == NULL){
		head = newNode;
		return;
	}
	if (head->data > n){
		if (head->left == NULL){
			head->left = newNode;
			return;
		}
		constructBST(head->left, n);
	}
	else{
		if (head->right == NULL){
			head->right = newNode;
			return;
		}
		constructBST(head->right, n);
	}
}
//======================END construct_binary_search_tree
//======================START print_level_order_tree_per_line();
void display_BST_perline(struct Node* head);
void print_level_order_tree_per_line()
{
	struct Node* head = create_tree();
	display_BST_perline(head);
}
void display_BST_perline(struct Node* head){
	queue<struct Node*> q;
	if (head == NULL) return;
	q.push(head);
	while (!q.empty()){
		int count = q.size();
		while (count > 0){
			struct Node * temp = q.front();
			cout << temp->data << " ";
			q.pop();
			if (temp->left != NULL)	q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);
			count -= 1;
		}
		cout << endl;
	}
}
//======================END print_level_order_tree_per_line();
//======================START find_width_binary_tree()
void display_binary_tree_width(struct Node*);
void find_width_binary_tree(){
	struct Node* head = create_tree();
	display_binary_tree_width(head);
}
void display_binary_tree_width(struct Node* head){
	if (head == NULL) return;
	queue<struct Node*> q;
	q.push(head);
	int count = 0;
	int result = 0;
	while (!q.empty()){
		count = q.size();
		result = (result > count) ? result : count;
		while (count > 0){
			struct Node *temp = q.front();
			q.pop();
			if (temp->left != NULL) q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);
			count -= 1;
		}
	}
	cout << "Breath is " << result;
}
//======================END find_width_binary_tree()
struct Node* deleteLeaveNode(struct Node* head);
void delete_leave_node(){
	struct Node* head = create_tree();
	display_BST_perline(head);
	deleteLeaveNode(head);
	cout << "After deleting leave node" << endl;
	display_BST_perline(head);
}
struct Node* deleteLeaveNode(struct Node* head){

	if (head == NULL) return NULL;

	if (head->left == NULL && head->right == NULL)
	{
		delete head;
		return NULL;
	}
	head->left = deleteLeaveNode(head->left);
	head->right = deleteLeaveNode(head->right);
	return head;
}
//==============================END of deleting last node
//===========================Start sum of leave node
void sumOfLeaveNode(struct Node*, int*);
void sum_of_leave_node(){
	struct Node * head = create_tree();
	int sum = 0;
	display_BST_perline(head);
	sumOfLeaveNode(head, &sum);
	cout << "Sum of leave node is " << sum;
}
void sumOfLeaveNode(struct Node* head, int* sum){
	if (head == NULL) return;
	if (head->left == NULL && head->right == NULL){
		*sum += head->data;
		return;
	}
	sumOfLeaveNode(head->left, sum);
	sumOfLeaveNode(head->right, sum);
}
//==========================END of sum of leaves
//==========================START of Level_with_maximum_number_of_nodes
void LevelWithMaximumNodes(struct Node*);
void Level_with_maximum_number_of_nodes()
{
	struct Node* head = create_tree();
	display_BST_perline(head);
	LevelWithMaximumNodes(head);
}
void LevelWithMaximumNodes(struct Node*)
{

}
void stringLearn(){
	string str = "birendra kumar";
	//...length
	cout << str.length() << endl;
	//...replace
	str.replace(0,8,"bond");
	cout << str << endl << endl;
	//...substr
	string st1 = str.substr(str.length() - 5);
	cout << str << " " << st1 << endl;
	string st2 = str.substr(str.length() - 5, 3);
	cout << str << " " << st2 << endl;
	//....erase
	str.erase(str.begin(), str.begin() + 4);
	cout << str << endl;
	str.erase(0, 2);
	cout << str << endl;
	//....append
	string str_append = "james k";
	str.append(str_append, 3, str_append.length());
	cout << str << endl;
	//....insert
	string str_insert = "james bond james";
	str.insert(0, str_insert);
	cout << str << endl;
	//....find
	int n = str.find('bond');
	int n2 = str.find('bond',6);
	if (n != 0) cout << "found at " << n; 
	else cout << "not found";
	cout << endl;
	if (n2 != 0) cout << "found at " << n2;
	else cout << "not found";
	cout << endl;
	//...iterate
	for (int i = 0; i < str.length(); i++)
		cout << str.at(i);
	cout << endl;
    //.....clear and empty
	cout << str.empty() << endl; //false->0 true =1
	str.clear();
	cout << str.empty() << endl;
	if (1) cout << 1;
	else cout << 0;
	cout << endl;
}
//*******************************REVISION START Linked List
void show_list(const list<int>&);
void revision_list(){
	/*
		push_back();
		push_front();
		pop_back();
		pop_front();
		insert(it,val);
		empty()
		clear()
		size()
		begin()
		rbegin()
		rend()
		cbegin()
		cend()
		crbegin()
		crend()
		end()
		erase(it)
		erase(it1,it2)
		find() //algo from algorithm library
		front()
		back()
		remove()
		remove_if()
		reverse()
		sort()
	*/
	list<int> lst;
	lst.push_back(20);
	lst.push_back(21);
	lst.push_front(10);
	lst.push_front(15);
	lst.push_back(25);
	auto it = lst.begin();
	advance(it, 1);
	lst.insert(it, 12);
	for (auto it = lst.begin(); it != lst.end(); it++){
		cout << *it << endl;
	}
	cout << "Size is " << lst.size() << endl;
	cout << "is list empty? " << lst.empty() << endl;
	cout << "Clearing the list--" << endl;
	//lst.clear();
	cout << "Size is after clearing: " << lst.size() << endl;
	cout << "===========Reverse iterate========" << endl;
	list<int>::reverse_iterator rit;
	for (rit = lst.rbegin(); rit != lst.rend(); rit++){
		cout << *rit << endl;
	}
	cout << "==========Iterator constant=======" << endl;
	list<int>::const_iterator cit;
	for (cit = lst.cbegin(); cit != lst.cend(); cit++){
		//--Error because it is constant variable
		//*cit = *cit + 10; 
		cout << *cit << endl;
	}
	cout << "==========Reverse Constant Iterator============" << endl;
	list<int>::const_reverse_iterator crit;
	for (crit = lst.crbegin(); crit != lst.crend(); crit++){
		//--Error because it is constant variable
		//*crit = *crit + 10;
		cout << *crit << endl;
	}
	cout << "Reversing the element" << endl;
	lst.reverse();
	show_list(lst);
	cout << "Sort the element" << endl;
	lst.insert(lst.begin(), 30);
	lst.sort();
	show_list(lst);
	cout << "Sort in Decending order" << endl;
	lst.sort([](int a, int b){return a > b; });
	show_list(lst);
	cout << "show the front element " << lst.front() << endl;
	cout << "show the last element " << lst.back() << endl;
	cout << "Finding the element " << endl;
	auto find_it = find(lst.begin(), lst.end(), 20);
	if (find_it != lst.end())
		cout << "Item is present" << endl;
	else
		cout << "Item is Not Present" << endl;
	//lst.erase(find_it);
	list<int>::iterator it2=find_it;
	advance(it2, 2);
	show_list(lst);
	lst.erase(find_it, it2);

	cout << "Erased 20 + 2 item from list" << endl;
	show_list(lst);
	cout << "Remove element" << endl;
	lst.remove(21);
	show_list(lst);
	cout << "Remove_if condition" << endl;
	lst.remove_if([](int a){ return a % 3 == 0;  });
	show_list(lst);
}
void show_list(const list<int>& lst){
	cout << "===Display list elememt===" << endl;
	for (auto it = lst.begin(); it != lst.end(); it++)
		cout << *it << endl;
}
//******************************REVISION END Linked List

//******************************REVISION START VECTOR LIST

//******************************REVISION END VECTOR LIST

//******************************REVISION START String
/*
	length();
	append("bond"),	append("bond",0,2);//bo
	substr(2),substr(2,len);
	erase(it1,it2),erase(i,j);
	push_back(),pop_back()
	front(),back()
	begin(),end()
	replace(0,len,"birendra") //bire
	c_str(); const char*
	[i]
	at(),
	insert(index,"bond");
	clear(),empty()
	find(),find_start)of(),find_last_of(),string::npos
	compare()
	getline();

*/
void revision_string(){
	string name = "birendra kumar";
	cout << "length of string \'birendra kumar\' :" << name.length() << endl;;
	//................insert,find
	cout << "Insert bond as middle name :" << name.insert(name.find(" "), " bond") << endl;
	cout << name << endl;
	//.................substr,find,length
	cout << "substring, fetch bond from name: " << name.substr(name.find("bond"), string("bond").length()) << endl;
	cout << name << endl;
	//.........replace,length
	cout << "Replace \'birendra\' to \'james\' :" << name.replace(0, string("birendra").length(), "James") << endl;
	cout << name << endl;
	//.........Erase,find,length
	name.erase(name.find(" kumar"), string(" kumar").length());
	cout << name << endl;
	//.........append
	name.append(" is back. ");
	cout << name << endl;
	name.append("What do you think", 0, 4);
	cout << name << endl;
	//........erase(it1,it2),begin(),
	name.erase(name.begin(), name.begin() + 2);
	cout << name << endl;
	//.................compare
	string fname("james");
	cout << fname.compare("james") << endl;
	//..............at(),[]
	for (int i = 0; i < fname.length(); i++){
		cout << fname[i] << " " << fname.at(i) << endl;
	}
	//................font,back
	cout << "use front() function on fname : "<<fname.front() << endl;
	cout << "use back() function on fname : "<<fname.back() << endl;
	cout << "is fname empty: " << fname.empty() << endl;
	fname.clear();
	cout << "clear fname  " << fname.length() << endl;
	//...............more on find()
	string last("bond");
	if (last.find("ba") != string::npos)
		cout << "\'ba\' is PRESENT on \'bond\' " << endl;
	else
		cout << "\'ba\' is NOT PRESENT on \'bond\'  " << endl;
}

//******************************REVISION END String



int main()
{
	//vectorLearn();
	//stackLearn();
	//queueLearn();
	//listLearn();
	//setLearn();
	//mapLearn();
	//dequeLearn();
	//Singleton_designPattern();
	//ObserverDesingPattern();
	//max_in_array_loop();
	//max_in_array_recursion();
	//---------------------------STRING
	//stringLearn();
	//---------------------------TREE
	//create_tree();
	//construct_binary_search_tree();  //-------PENDING
	//breath_first_search();
	//power_of_int_recursion();
	//find_width_binary_tree();
	//delete_leave_node();
	//sum_of_leave_node();
	//Level_with_maximum_number_of_nodes(); //.....Pending
	//find_distance_root_to_node(); //---PEINDING
	//print_level_order_tree_per_line(); 
	//Print_k-sum_paths_tree();  //---PENDING
	//Convert_Tree_into_Doubly_Linked_List();  //---PENDING
	//deepest_right_node_iterative();
	//largest_number_less_than_or_equal_to_N_(); //--PENDING
	//floor_and_ceil_value_from_tree()
	//--------------------------GRAPH
	//-------------------------Algorithm in C++
	// advance(it,n);
	// find(it1,it2,val) use in list to find element 

	//------------------------Revision
	//revision_list();
	//revision_string();
	//------------------------Coding problem
	Algorithm algo;

	cin.get();
	return 0;
}
//Heap Sort
//Heap Data Structure    //......PENDING
//Priority Queue         //......PENDING
/*============================================================================================
Array

String
//==============================================================================================*/

/*================================================================================================
vector->push_back(),pop_back(),[],at(),clear(),size(),,empty(),front(),back()
erase(it),erase(it,it2)
list->push_back(),push_front(),pop_back(),pop_front(),size(),empty(),insert(it,val),front(),back(),
erase(it),erase(it1,it2)
remove(val),remove_if()

queue->pop(),push(),front(),back(),size(),

deque->pop_back(),pop_front(),push_back(),push_front(),size(),erase(it),erase(it1,it2),at();

forward_list->

priority_queue->push(),pop(),top(),size(),empty()

stack->pop(),push(),top(),size()

set->insert(),size(),
	erase(key),erase(it),erase(it1,it2)
	iterator::find(val),int count(11);

multiset---> multiple value exit with sorted order     //PENDING
erase(key),erase(it),

unordered_set->

unordered_multiset->

map->insert(dt1,dt2),size(),empty(),mp[],
	erase(key),erase(it),erase(it1,it2)
	find(),,int::count()

multimap->sorted order,
		erase(key),erase(it),erase(it1,it2)
		count(),find(key)

string-> length(), begin,end,rbegin,rend,
		str.copy(ch[80],14,0),
		getline(),push_back,pop_back,
		str.compare(str)::int,
		find(str),find(str,start),find_last_of(str),find_first_of(str),rfind(str),str.find("bond")!=string::npos
		insert(9,"kumar");
		clear(),empty()
		at(index)
		front,back
		c_str::const char*
		append("birendra",0,3);
		substr(start_index=2,length=5)
		erase(2,5)
		erase(it1,it2);
		replace(start=0,len=4,'Birendra");
		
======================================================================================================*/
//10-11-2020
/*
tree: 10
graph: 5
Git
STL
Constructor and destructor
virtual Function
*/