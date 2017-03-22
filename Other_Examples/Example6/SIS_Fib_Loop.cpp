#include <iostream>
#include <ctime>
using namespace std;

unsigned __int64 fib_loop(int n)
{
	__int64 result = 1;
	__int64 a = 1;
	__int64 b = 1;
		for (int i = 3; i <=n; ++i)
	{
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main()
{
	__int64 number, result;
	clock_t start, finish;
	double elapsedTime;
	cout << "enter a positive integer: " << endl;
	cin >> number;
	cin.ignore();
	start = clock();
	result = fib_loop(number);
	finish = clock();
	elapsedTime = finish - start;
	cout << "Fib(" << number << ") = " << result << endl;
	cout << "It took " << elapsedTime << " seconds to generate " << number << " fibonacci numbers" << endl;	

}