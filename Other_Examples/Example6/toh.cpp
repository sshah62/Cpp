#include <iostream>
#include <ctime>

using namespace std;

void toh(int n, int s1, int s2)
{
	if (n == 1)
	{
		cout << "Move the disk from " << s1 << " to " << s2 << "." << endl;
	}
	else
	{
		toh (n-1, s1, s1^s2);
		toh (1, s1, s2);
		toh(n-1, s1^s2, s2);
	}


}

int main()
{
	clock_t start, finish;
	double elapsedTime;
	cout << "please enter an integer: ";
	int n;
	cin >> n;
	start = clock();
	toh(n, 1, 2);
	finish = clock();
	elapsedTime = (finish - start)/CLOCKS_PER_SEC;
	cout << " Tower of Hanoi took the computer " << elapsedTime << " seconds " << "to move " << n;
	cout << " disks from Spindle 1 to Spindle 2" << endl;
	return 0;
}

