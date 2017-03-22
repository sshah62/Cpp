//Sanjiv Shah CS 5005 Summer 2016 (OUID 113180542)
//Developed on PC running windows 10 IDE used: Visual Studio 2015 (community edition)
//Project 3 Hashing

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int hashfn(string);
int find(const vector<list<string>>& v, string);
void remove(const vector<list<string>>& v, string s);
void insert(vector<list<string>>&, string);
void split(vector<list<string>>& v, int n, int p);
vector<list<string>> copy(const vector<list<string>>& v);

list<string> ::const_iterator listit;

//Hashing Function
int hashfn(string s)
{
	int i = s[0] - 'A';
	return i;
}

//Find method
int find(const vector<list<string>>& v, string s)
{
	int f = hashfn(s);
	for (int i = f; i < v.size(); ++i)
	{
		listit = find(v[i].begin(), v[i].end(), s);
		if (listit != v[i].end())
		{
			cout << s << " was found." << endl << endl;
			return 0;
		}
		else 
			{
				i++;
			}
			
	}
	cout << s << " was not found" << endl <<endl;
	return -1;
}

//Remove a list from current vector<list<string>>
void remove(vector<list<string>>& v, string s)
{
	int r = hashfn(s);
	int i = find(v, s);
	if (i == 0)
	{
		v[r].remove(s);
		cout << s << "was removed from myHashTable." << endl << endl;
	}
	

}

//Insert a new string in the vector<list<string>> in its proper location
void insert(vector<list<string>>& v, string s)
{
	int i = find(v, s);
	if (i == 0)
	{
		cout << s << "was not added to myHashTable" << endl << endl;
	}
	else
	{
		int t = hashfn(s);
		list<string> temp;
		temp.assign(1, s);
		v[t].push_back(temp.back());
		cout << "Hash Value of " << s << "is " << t << endl;
		cout << s << " added to myHashTable[" << t << "]" << endl << endl;
	}
}

void split(vector<list<string>>& v, int n, int p)
{
	if (v[n - 1].size() <= p)
	{
		cout << "The list is already smaller than size " << p << endl;
	}
	else
		for (int i = n; i < v.size(); ++i)
		{
			while (v[i - 1].size() > p)
			{
				list<string> temp;
				temp.assign(1, v[i - 1].back());
				v[i - 1].pop_back();
				v[i].push_back(temp.back());
				if (v[v.size() - 1].size() >= p)
				{
					list<string> temp2;
					
					v.push_back(temp2);
				}
		
			}
		}
}
//COPY constructor
vector<list<string>> copy(vector<list<string>>& v)
{
	vector<list<string>> newHashTable;
	newHashTable = v;
	return newHashTable;
}

// Operator= is not overloaded because it is alreay overloaded in the vector STL.  I using vector STL, so no need for overloading method.  DO I STILL GET THE BONUS?

int main()
{
	//Get input data in an array - TEMPORARY STORAGE
	string Names[25] = { "Andy B", "Amy Dean", "Antonio G", "Andy Roberts", "Brian W","Bob Macy", "Brent James", "Buck Muck", "Cannon James",
		"Cart Wright", "Catherine Zeta", "Carl Lewis", "David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith", "Yarda Varda", "Yami Jacob",
		"Yester Louis", "Yukon Oklahoma", "Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen" };
	
	//Print the array
	for (int i = 0; i < 25; i++)
	{
		cout << Names[i] << endl;
	}
	//create a vector of list of size 26 (myHashTable)
	vector<list<string>> myHashTable;
	for (int i = 0; i < 26; i++)
	{
		myHashTable.push_back(list<string>());
	}

	//Populate myHashTable from the array Numbers[] according to each string's hash value
	for (int i = 0; i < 25; i++)
	{
		int hash = hashfn(Names[i]);  //Implementation of Hashing Function
		cout << i << "=" << hash << endl;
		(myHashTable[hash].push_back(Names[i]));
	}
	//Print myHashTable
	for (int i = 0; i < 26; i++)
	{
		if (myHashTable[i].size() > 0)
		{
			cout << "Element at position " << i << "of the hash table " << endl;
			for (listit = (myHashTable[i].begin()); listit != (myHashTable[i].end()); ++listit)
			{
				cout << "*****" <<  *listit << endl;
			}
		}
	}
	
	//Implementation of FIND method
	cout << "Implementation of Find method" << endl;
	find(myHashTable, "Dowd Peter");

	find(myHashTable, "Sanjiv Shah");

	//Implementation of Remove method
	cout << "Implementation of Remove method" << endl;
	remove(myHashTable, "Dowd Peter");
	
	remove(myHashTable, "Sanjiv Shah");

	//Implementation of Insert Method
	cout << endl;
	cout << "Implementation of Insert method" << endl;
	insert(myHashTable, "Dowd Peter");

	insert(myHashTable, "Sanjiv Shah");
	
	
	remove(myHashTable, "Sanjiv Shah"); //Just to get the myHashTable to its original state

	//Implementation of copy constructor.
	vector<list<string>> copyofmyHashTable;
	copyofmyHashTable = copy(myHashTable);
	
	//Print copyofmyHashTable
	for (int i = 0; i < 26; i++)
	{
		if (copyofmyHashTable[i].size() > 0)
		{
			cout << "Element at position " << i << " of the hash table " << endl;
			for (listit = (copyofmyHashTable[i].begin()); listit != (copyofmyHashTable[i].end()); ++listit)
			{
				cout << "*****" << *listit << endl;
			}
		}
	}

	//Implementation of Split method
	//BONUS: WHEN THIS METHOD IS EXECUTED, IT SPLITS LISTS beginning with the index 'n-1' TO THE MAXIMUM SIZE 'p' in split (myHashTable, n, p)
	
	split(myHashTable, 2, 2);
	
	//Printout of myHashTable after "Split"
	cout << endl;
	cout << "Contents of myHashTable after performing split(myHashTable, 2, 2) function" << endl;
	cout << "Please take note that it only splits the lists beginning with 2nd list and ending at the last" << endl<< endl;
	for (int i = 0; i < 26; i++)
	{
		if (myHashTable[i].size() > 0)
		{
			cout << "Element at position " << i << " of the hash table " << endl;
			for (listit = (myHashTable[i].begin()); listit != (myHashTable[i].end()); ++listit)
			{
				cout << "*****" << *listit << endl;
			}
		}
	}
	return 0;
}

