#include <iostream>
# include <ctime>

using namespace std;


__int64 fib_recursive(int n)
{
	__int64 result =1;
	if (n <= 2)
	{
		return 1;
	}
	else
	{
			return fib_recursive(n-1) + fib_recursive (n-2);
	}
}

int main()
{
	clock_t start, finish;
	double elapsedTime;
	cout <<"Please enter an integer:" << endl;
	int n;
	cin >> n;
	cin.ignore();
	start = clock();
	fib_recursive(n);
	finish = clock();
	elapsedTime = (finish - start)/CLOCKS_PER_SEC;

	cout << n << " fib_recursive = " << fib_recursive(n) << " Time = " << elapsedTime << " seconds" <<endl;
	
	return 0;
}