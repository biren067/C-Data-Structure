#include "stdafx.h"
#include "Stl.h"


Stl::Stl()
{
	add_element();
	show_vector();
	iterate_vector();
	find_count_vector();
	erase_element();
	insert_middle();
	clear_empty_size();
}

void Stl::add_element(){
	//.....Add element by push_back operation
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);
	vec.push_back(14);
	vec.push_back(15);
	vec.push_back(16);
	
}
void Stl::iterate_vector(){
	vector<int>::reverse_iterator rit = vec.rbegin();
	for (; rit != vec.rend(); rit++)
		cout << *rit << " ";

	cout << endl << "Iterate cBegin and cend()" << endl;
	vector<int>::const_iterator cit;
	for (cit = vec.cbegin(); cit != vec.cend(); cit++)
		cout << *cit << " ";
	cout << endl << "Iterte crbigin() and crend()" << endl;
	vector<int>::const_reverse_iterator crit;
	for (crit = vec.crbegin(); crit != vec.crend(); crit++)
		cout << *crit << " ";
	cout << endl;
}
void Stl::clear_empty_size()
{
	//........empty,clear,size
	cout << "is vector empty: " << vec.empty() << endl;//0
	cout << "Size of vector is " << vec.size() << endl;
	vec.clear();
	cout << "size of vector is " << vec.size() << endl;
}
void Stl::insert_middle(){
	//......use of insert function
	cout << "Use insert function to insert element" << endl;
	vec.insert(vec.begin(), 10);
	//.......update a element
	vec[1] = 100;
	show_vector();
}
void Stl::erase_element(){
	cout << "Erase elements " << endl;
	vec.erase(vec.begin());
	vec.erase(vec.begin(), vec.begin() + 2);
	show_vector();
}
void Stl::show_vector(){
	//.........below code working
/*	cout << "Display element :" << endl;
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << " " << vec.at(i) << endl;
	}
	cout << "Display element via iterator " << endl;
	*/
	for (auto it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
}
void Stl::find_count_vector(){
	vector<int>::iterator it_find=find(vec.begin(), vec.end(), 12);
	if (it_find != vec.end())
		cout << "Element found in Vector" << endl;
	else
		cout << "Element not found in vector" << endl;
}
Stl::~Stl()
{
}
