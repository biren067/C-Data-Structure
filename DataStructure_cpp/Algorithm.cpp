#include "stdafx.h"
#include "Algorithm.h"


Algorithm::Algorithm()
{
	//find_closest();
	find_min_sum(); //in matrix --Good one
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
