#include "stdafx.h"
#include "Find_Digits.h"


Find_Digits::Find_Digits()
{
	int result = 0;
	cout << "Enter a number " << endl;
	cin >> N;
	result = find_digits(N);
	cout << result << endl;;

}
int Find_Digits::find_digits(int n){
	int result = 0;
	int m = n;
	while (m >= 0){
		int rem = m % 10;
		if( (rem > 0) && (n%rem == 0) ){
			result += 1;
		}
		m = m / 10;
	}
	return result;
}

Find_Digits::~Find_Digits()
{
}
