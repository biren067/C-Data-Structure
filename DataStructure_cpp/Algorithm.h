#pragma once
#include <tuple>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Algorithm
{
private:	

public:
	Algorithm();

	tuple<int, int> find_closest_value(vector<int>, vector<int>, int);

	void find_closest();
	void find_min_sum();

	~Algorithm();
};
