//SIS_Factorial_Loop.cpp
//Sanjiv Shah
// CS 2363, Spring 2016

#include <iostream>
#include <ctime>
using namespace std;

__int64 factorial_loop(int n);

int main()
{
	clock_t start, finish;
	double elapsedTime;
	cout <<"Please enter an integer:" << endl;
	__int64 n;
	cin >> n;
	cin.ignore();
	start = clock();
	factorial_loop(n);
	finish = clock();
	elapsedTime = (finish - start)/CLOCKS_PER_SEC;

	cout << n << " ! = " << factorial_loop(n) << " Time = " << elapsedTime << " seconds" <<endl;
	//cout << CLOCKS_PER_SEC << endl;
	return 0;



}

__int64 factorial_loop(int n)
{
	__int64 result = 1;
	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}