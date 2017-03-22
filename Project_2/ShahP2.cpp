//SISP2.cpp
//This program will run in terminal mode
//It is designed to run by itself (no preloading of file)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "ArrayClass.cpp"
#include "String.cpp"
#include "Vector.cpp"
#include "Matrix.cpp"
#include "LinkedList.cpp"

using namespace std;

void split(const string& s, char c, vector<string>& v);
int index(vector<string>& name, string s);


int main()
{
	string fileName;

	cout << "Please enter the input data filename (including extension):" << endl;
	cout << "Please make sure the input data file is in the same direcotry as this program" << endl;

	cin >> fileName;

	ifstream InputFile(fileName);
	//throw an exception here if (InputFile

	string line;
	getline(InputFile, line);

	int noRows = stoi(line.substr(0, 1));
	int noAttributes = stoi(line.substr(2, 3));

	ArrayClass<string> inputArray(noRows);

	for (int i = 0; i < noRows; ++i)
	{
		getline(InputFile, line);
		inputArray[i] = line;
	}

	cout << "Results of Task 1: Input Array" << endl;
	cout << "Total number of records in input file: " << noRows << endl;
	for (int i = 0; i < noRows; ++i)
	{
		cout << "Line " << i + 1 << " : " << inputArray[i] << endl;
	}
	cout << "Task 1 Complete" << endl;
	cout << endl;

	
	//Task 2 create array of unique attribute values 

	ArrayClass<vector<string>> inputArrayofVector(noRows);
	for (int i = 0; i < noRows; ++i)
	{
		split(inputArray[i], ' ', inputArrayofVector[i]);
	}

	ArrayClass<vector<string>> uniqueAttrValues(noAttributes);
	string s_temp = "";
	for (int i = 0; i < noRows; ++i)
	{
		for (int j = 0; j < noAttributes; ++j)
		{
			s_temp = inputArrayofVector[i][j];
			if (uniqueAttrValues[j].empty() || !(find(uniqueAttrValues[j].begin(), uniqueAttrValues[j].end(), s_temp) != uniqueAttrValues[j].end()));
			//Above find method adopted from http://stackoverflow.com/questions/571394/how-to-find-if-an-item-is-present-in-a-stdvector
			{
				uniqueAttrValues[j].push_back(s_temp);
			}
		}
	}

	//Task3 Create a Matrix
	Matrix<int> tableValues(noRows, noAttributes+1, 0)  ;
	
	for (int i = 0; i < noRows; i++)
	{
		for (int j = 0; j < noAttributes; j++)
		{
			s_temp = inputArrayofVector[i][j];
			tableValues[i][j] = index(uniqueAttrValues[j], s_temp);
		}
		tableValues[i][noAttributes] = stoi(inputArrayofVector[i][noAttributes]);
	}
	for (int i = 0; i < noRows; i++)
	cout << tableValues[i] << endl;
}


//Following method is adopted from c++ cookbook, Safaribooksonline.com
void split(const string& s, char c,vector<string>& v)
{
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) 
	{
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

int index(vector<string>& name, string s)
{
	For(int i = 0; i < name.size(); ++i)
	{
		if (name[i] == s)
		return i;
	}
}