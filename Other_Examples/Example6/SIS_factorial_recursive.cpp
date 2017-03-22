//SIS_Factorial_recursive.cpp
//Sanjiv Shah
// CS 2363, Spring 2016

#include <iostream>
#include <ctime>
using namespace std;

__int64 factorial_recursive(int n);

int main()
{
	clock_t start, finish;
	double elapsedTime;
	cout <<"Please enter an integer:" << endl;
	int n;
	cin >> n;
	cin.ignore();
	start = clock();
	factorial_recursive(n);
	finish = clock();
	elapsedTime = ((finish - start)/CLOCKS_PER_SEC)*1000000;

	cout << n << " ! = " << factorial_recursive(n) << " Time = " << elapsedTime << " micro-seconds" <<endl;
	//cout << CLOCKS_PER_SEC << endl;
	return 0;
}

__int64 factorial_recursive(int n)
{
	__int64 result = 1;
	if (n == 0)
	{
		result = 1;
	}
	else 
	{
		result = n * factorial_recursive(n-1);	
	}
	return result;
}