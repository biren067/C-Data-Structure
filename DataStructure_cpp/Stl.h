#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Stl
{
private:
	vector<int> vec;
public:
	Stl();
	void add_element();
	void show_vector();
	void find_count_vector();
	void erase_element();
	void insert_middle();
	void iterate_vector();
	void clear_empty_size();
	~Stl();
};

