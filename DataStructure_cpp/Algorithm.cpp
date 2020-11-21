#include "stdafx.h"
#include "Algorithm.h"


Algorithm::Algorithm()
{
	//find_closest();
	//find_min_sum(); //in matrix --Good one
	//max_range_of_sum();
	//second_highest_in_array();
	//union_of_two_array(); //.....wrong
	zeros_at_end();
}
void Algorithm::zeros_at_end(){
	int ar[] = { 1, 0, 4, 0, 0, 9, 0, 8 };
	int len = 8;
	int last_index = 7;
	int count = 0;
	int i = 0;
	while (i < (len - count)){
		if (ar[i] == 0){
			count += 1;
			int temp = ar[i];
			for (int j = i; j < last_index; j++){
				ar[j] = ar[j + 1];
			}
			ar[last_index] = temp;
			continue;
		}
		i += 1;
	}
	for (int i = 0; i < 8; i++)
		cout << ar[i] << " ";
	cout << endl;
	cout << "Total no of shifted zeros is  : " << count;
}
void Algorithm::second_highest_in_array(){
	int a[] = { 2, 17, 6, 2, 9, 5, 1 };
	int max = a[0] < a[1] ? a[1] : a[0];
	int sm = a[0] > a[1] ? a[1] : a[0];
	cout << max << " " << sm << endl;
	for (int i = 2; i < sizeof(a)/sizeof(int); i++){
		if (max < a[i])
		{
			sm = max;
			max = a[i];
		}
		else{
			if (sm < a[i])
				sm = a[i];
		}
	}
	cout << "Max   :" << max << endl;
	cout << "small :" << sm;

}
void Algorithm::union_of_two_array(){
	int a1[] = { 1, 3, 4, 5, 7 };
	int a2[] = { 2, 3, 5, 6 };
	int *max, *sm;
	if ( sizeof(a1) > sizeof(a2) ){
		max = a1;
		sm = a2;
	}
	else{
		max = a2;
		sm = a1;
	}
	int s = 4;// sizeof(sm);
	int m = 5;// sizeof(max);
	int len = sizeof(max);//+ sizeof(sm);
	cout << len << endl;
	cout << "{ ";
	int j = 0;
	int i = 0;
	while(1)
	{
		if (max[i] > sm[j])
		{
			cout << sm[j] << ", "; j++;
		}else if (max[i] < sm[j])
		{
			cout << max[i] << ", "; i++;
		}else if (max[i] == sm[i])
		{	
			cout << max[i] << ", "; i += 1; j += 1;
		}

		
		if( s <= j - 1 || m <= i - 1)
			break;
	}
	while (i < sizeof(max)){
		cout << max[i] << ", ";
	}
	cout << "}";
}
void Algorithm::max_range_of_sum(){

	int ar[] = { 4, 5, 6, 1, 4, 6, 5 };
	int res = 0;
	for (int i = 0; i < 7; i++){
		res = res ^ ar[i];
		cout << res << endl;
	}
	cout << endl << endl<< "Unique Element is " << res;

}
//========================START min sum
void Algorithm::find_min_sum(){
	int input[3][3] = { { 1, 3, 2 }, { 2, 4, 1 }, { 1, 9, 2 } };
	cout << "Original Matrix" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
	int result[3][3] = { 0 };
	for (int i = 0; i < 3; i++){
		int r1 = 0;
		int r2 = 0;
		int min = 0;
		for (int j = 0; j < 3; j++){
			if (i>0 && j>0)
			{
				r1 = result[i - 1][j];
				r2 = result[i][j - 1];
				min = r1 < r2 ? r1 : r2;
			}
			else if (j == 0 && i!=0 ) {
				min = result[i-1][j];
			}
			else if (i == 0 && j!=0 ){
				min = result[i][j - 1];
			}
			
			result[i][j] = min + input[i][j];
		}
	}
	cout << endl<< "Output result" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
//========================END min sum
//========================START find the closest value of a given number
// eg: for n= 25, output :24 and 26

tuple<int, int> Algorithm::find_closest_value(vector<int> vec1, vector<int> vec2, int N){
	tuple<int, int> tup{ 11, 22 };
	set<int> ss(vec1.begin(), vec1.end());
	/*for (auto it = ss.begin(); it != ss.end(); it++){
		cout << *it << endl;
	}*/
	for (auto itt = vec2.begin(); itt != vec2.end(); itt++){
		int rem = N - *itt;
		if (ss.count(rem) == 1){
			cout << "(" << rem << "," << *itt << ")" << endl;
		}
	}
	return tup;
}

void Algorithm::find_closest(){
	vector<int> vec1{ 11, 3, 6, 21, 17, 5 };
	vector<int> vec2{ 22, 13, 8, 23, 7, 9 };
	int a, b;
	tie(a, b) = find_closest_value(vec1, vec2, 14);
}//========================END of closest value





Algorithm::~Algorithm()
{
}
