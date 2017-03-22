#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
const int BASE_CASE = 2;
//method declarations
void exchange(int & , int & );
bool inOrder(int , int );
int smallestNum(int * , int , int );
void exchangeSort(int * , int );
void insertionSort(int * , int );
void selectionSort(int * , int );
void quickSort(int * , int , int );
void quickSort(int * , int );
int partition(int * , int , int );
void setMedianOfThree(int * , int , int );
void displayArray(int * , int );
void displayArray(int * , int , ofstream & );
void reverseArray(int *,int&);


//Global variable Declarations
int noOfExchanges = 0;
int noOfComparisons = 0;



int main()
{
	string userInput;
	string userOutput;
	ifstream infile;
	ofstream outfile;
	vector<int> values;
	stringstream strStream;
	

	//Get the file input names and output and for picking the type of sort
	cout << "Please enter the input file name: " ;
	getline(cin, userInput);
	cout << "Please enter the output file name: ";
	getline(cin, userOutput);
	infile.open(userInput.c_str());
	outfile.open(userOutput.c_str());
	if(infile.fail() || outfile.fail())
	{
		cout << "Error opening your files, Please enter correct file names!" << endl;
	}
	else
	{
		strStream << infile.rdbuf();
		string text = strStream.str();
		 
		int z;
		while (strStream >> z)
		{
			values.push_back(z);
		}
	}
	int &arraySize = values[0];
	int *inputArray =  new int [arraySize];
	
	for (int p = 0; p < arraySize; ++p)
	{
		inputArray[p] = values[p+1];
	}
		
	
	//Display the input array
	displayArray(inputArray, arraySize);

	
		
	//Input for sorting operation
		
	string testType;
	cout << "1. Exchange sort"		<< endl << "2. Insertion sort"		 << endl;
	cout << "3. Selection sort"		<< endl << "4. Quick sort"			 << endl;
	cout << endl;
	cout << "Please input the corrosponding number for the type of sort you would like to test: "<<endl;
	getline(cin, testType);
		
	int sortType = stoi(testType);
	while (sortType != 0)
	{
	int *tempCopy = new int [arraySize];
	for (int v = 0; v < arraySize; ++v)
	{
		tempCopy[v] = inputArray[v];
	}
	
	switch(sortType)
	{
		case 1://Exchange sort
			cout << "Starting exchange Sort..." << endl;
			//Sort the Copy
			noOfComparisons =0;
			noOfExchanges = 0;
			exchangeSort(tempCopy, arraySize);
			//Display sorted array
			cout << "Displaying resutls of Exchange sort" <<endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "Number of comparisons "  << noOfComparisons  << "." << endl;
			cout << "Number of exchanges " << noOfExchanges << "." << endl;
			cout << "Done Sorting the Input Array with Exchange Sort" << endl;
			cout << endl;
			//Reverse the sorted array
			cout << "Now reversing the SORTED Array" << endl;
			reverseArray(tempCopy, arraySize);
			cout << "Now displaying Reversed array (Reverse Sorted)" <<endl;
			displayArray(tempCopy, arraySize);
			cout << endl;
			cout << "Now sorting reserved array"<< endl;
			noOfComparisons =0;
			noOfExchanges = 0;
			exchangeSort(tempCopy, arraySize);
			cout<< "Now displaying re-sorted array" << endl;
			cout << endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "No. of comparisons: "  << noOfComparisons  << "." << endl;
			cout << "No. of exchanges " << noOfExchanges << "." << endl;
			cout << "Having fun yet?  Thank you" << endl;
			delete tempCopy;
			break;

		case 2://Insertion Sort
			cout << "Starting Insertion Sort..." << endl;
			//Sort the Copy
			noOfComparisons =0;
			noOfExchanges = 0;
			insertionSort(tempCopy, arraySize);
			//Display sorted array
			cout << "Displaying resutls of Insertion sort" <<endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "Number of comparisons "  << noOfComparisons  << "." << endl;
			cout << "Number of exchanges " << noOfExchanges << "." << endl;
			cout << "Done Sorting the Input Array with Exchange Sort" << endl;
			cout << endl;
			//Reverse the sorted array
			cout << "Now reversing the SORTED Array" << endl;
			reverseArray(tempCopy, arraySize);
			cout << "Now displaying Reversed array (Reverse Sorted)" <<endl;
			displayArray(tempCopy, arraySize);
			cout << endl;
			cout << "Now sorting reserved array"<< endl;
			noOfComparisons =0;
			noOfExchanges = 0;
			insertionSort(tempCopy, arraySize);
			cout<< "Now displaying re-sorted array" << endl;
			cout << endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "No. of comparisons: "  << noOfComparisons  << "." << endl;
			cout << "No. of exchanges " << noOfExchanges << "." << endl;
			cout << "Having fun yet?  Thank you" << endl;
			delete tempCopy;
			break;
		case 3:// Selection Sort
			cout << "Starting Selection Sort..." << endl;
			//Sort the Copy
			noOfComparisons =0;
			noOfExchanges = 0;
			selectionSort(tempCopy, arraySize);
			//Display sorted array
			cout << "Displaying resutls of Selection sort" <<endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "Number of comparisons "  << noOfComparisons  << "." << endl;
			cout << "Number of exchanges " << noOfExchanges << "." << endl;
			cout << "Done Sorting the Input Array with Selection Sort" << endl;
			cout << endl;
			//Reverse the sorted array
			cout << "Now reversing the SORTED Array" << endl;
			reverseArray(tempCopy, arraySize);
			cout << "Now displaying Reversed array (Reverse Sorted)" <<endl;
			displayArray(tempCopy, arraySize);
			cout << endl;
			cout << "Now sorting reserved array"<< endl;
			noOfComparisons =0;
			noOfExchanges = 0;
			selectionSort(tempCopy, arraySize);
			cout<< "Now displaying re-sorted array" << endl;
			cout << endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "No. of comparisons: "  << noOfComparisons  << "." << endl;
			cout << "No. of exchanges " << noOfExchanges << "." << endl;
			cout << "Having fun yet?  Thank you" << endl;
			delete tempCopy;
			break;
		case 4: //Quick Sort
			cout << "Starting Quick Sort..." << endl;
			//Sort the Copy
			noOfComparisons =0;
			noOfExchanges = 0;
			quickSort(tempCopy, arraySize);
			//Display sorted array
			cout << "Displaying resutls of Quick sort" <<endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "Number of comparisons "  << noOfComparisons  << "." << endl;
			cout << "Number of exchanges " << noOfExchanges << "." << endl;
			cout << "Done Sorting the Input Array with Quick Sort" << endl;
			cout << endl;
			//Reverse the sorted array
			cout << "Now reversing the SORTED Array" << endl;
			reverseArray(tempCopy, arraySize);
			cout << "Now displaying Reversed array (Reverse Sorted)" <<endl;
			displayArray(tempCopy, arraySize);
			cout << endl;
			cout << "Now sorting reserved array"<< endl;
			noOfComparisons =0;
			noOfExchanges = 0;
			quickSort(tempCopy, arraySize);
			cout<< "Now displaying re-sorted array" << endl;
			cout << endl;
			displayArray(tempCopy, arraySize);
			displayArray(tempCopy, arraySize, outfile);
			cout << "No. of comparisons: "  << noOfComparisons  << "." << endl;
			cout << "No. of exchanges " << noOfExchanges << "." << endl;
			cout << "Having fun yet?  Thank you" << endl;
			delete tempCopy;
			break;
		
		default:
			 break;
			
		}
	cout << "1. Exchange sort"		<< endl << "2. Insertion sort"		 << endl;
	cout << "3. Selection sort"		<< endl << "4. Quick sort"			 << endl;
	cout << endl;
	cout << "Please input the corrosponding number for the type of sort you would like to test: "<<endl;
	getline(cin, testType);
	}
}

void reverseArray(int * a, int &s)
{
	int temp;
	for (int i = 0; i < s/2; ++i)
	{
      temp = a[s-i-1];
      a[s-i-1] = a[i];
      a[i] = temp;
	}
}
void displayArray(int * a, int s)
{
	if (s <= 200)
	{
		for(int i = 0; i < s; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for(int i = 0; i < 100; i++)
		{
			cout << a[i] << " ";
		}
		for(int j = s - 100; j < s; j++)
		{
			cout << a[j] << " ";
		}
	}
}

void displayArray(int * a, int s, ofstream & fout)
{
	if (s <= 200)
	{
		for(int i = 0; i < s; i++)
		{
			fout << a[i] << " ";
		}
		fout << endl;
	}
	else
	{
		for(int i = 0; i < 100; i++)
		{
			fout << a[i] << " ";
		}
		for(int j = s - 100; j < s; j++)
		{
			fout << a[j] << " ";
		}
	}
	fout << endl;
}

void exchangeSort(int * a, int s)//size as sepearte para
{//not local
	for (int k = 0; k < s - 1; k ++)
	{
		for (int i = (k + 1); i < s; i ++)
		{
			if (inOrder(a[i], a[k]))
			{
				exchange(a[k], a[i]);
			}
		}
	}
}
void exchange(int & i, int & j)//works
{
	int t = i;
	i = j;
	j = t;
	noOfExchanges++;
}

bool inOrder(int i, int j)//works
{
	noOfComparisons++;
	return (i <= j);
}
void insertionSort(int * a, int s)
{
	/*this will look through the array starting at index 0 and compare that
	value to all the "left" values in the array, it will swap if necessary*/
	int j;
	for(int i = 1; i < s; i++)
	{
		j = i;
		for(j; j > 0; j--)
		{
			if(inOrder(a[j], a[j-1]))
			{
				exchange(a[j], a[j-1]);
			}
		}
	}
}
void selectionSort(int * a, int s)
{
	for(int i = 0; i < s-1; i++)
	{
		int small = smallestNum(a, i, s-1);
		if(small != i)
		{
			exchange(a[small], a[i]);
		}
	}

}
int smallestNum(int * a, int i, int j)
{
	int s = i;
	for(int k = s+1; k <= j; k++)
	{
		if(inOrder(a[s], a[k]) == false)
		{
			exchange(a[s], a[k]);
		}
	}
	return s;
}
void quickSort(int *a , int s)
{
	quickSort(a, 0, s-1);
}
void quickSort(int *a, int f, int l)
{
	if (l-f < BASE_CASE)
	{
		insertionSort(a,l-1);
	}
	else
	{
		//setMedianOfThree(a,f,l);
		int p = partition(a,f,l);
		quickSort(a,f,p-1);
		quickSort(a, p+1, l);
	}
}

void setMedianOfThree(int *a,  int f, int l)
{
	int m = (f + l)/2;
	if (!inOrder(a[f], a[m]))
	{
		noOfComparisons++;
		swap(a[f], a[m]);
		noOfExchanges++;
	}
	if (!inOrder(a[m], a[l]))
	{
		noOfComparisons++;
		swap (a[m], a[l]);
		noOfExchanges++;
	}
	if(!inOrder(a[f], a[m]))
	{
		noOfComparisons++;
		swap(a[f], a[m]);
		noOfExchanges++;
	}
}
int partition(int * a, int i, int j)
{
	setMedianOfThree(a, i, j);
	return i;

}