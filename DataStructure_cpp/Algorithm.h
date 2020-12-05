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
	void max_range_of_sum();
	void second_highest_in_array();
	void second_highest_in_array2();
	void union_of_two_array();
	void zeros_at_end();
	void zeros_at_end_2();
	void longestConsecutiveCharacter();
	void reverseString();
	void reverseString1(char *,int n);
	~Algorithm();
};

