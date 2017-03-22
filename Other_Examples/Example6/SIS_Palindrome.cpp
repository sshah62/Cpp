//SIS_Palindrome.cpp

#include <iostream>
#include <string>


using namespace std;

string pal_str_copy(string& s);
void convert(string& s);
bool is_palindrome(string& s2);

int main()
{
	cout << "Welcome to Palindrome Checking Program developed by Mr. Sanjiv Shah" << endl;
	cout << "Please enter the string you would like to check: " << endl;
	string s;
	string s2;
	getline (cin, s);

	s2 = pal_str_copy(s);
	convert(s2);
	
	if (is_palindrome(s2))
	{
		cout << "String: " << s << " is a Palindrome" << endl;
	}
	else
	{
		cout << "String: " << s << " is NOT a Palindrome" << endl;
	}
	return 0;
}	

//create a scrubbed string - remove punctuations, remove spaces, only alphanumeric characters
string pal_str_copy(string& s)
{
	int i = 0;
	string copy ="";
	while (s[i] != NULL)
	{
				if (isalnum(s[i]))
		{
			copy += s[i];
			i++;
		}
		else
		{
			i++;
		}
	}
	return copy;
}

// convert scrubbed string to all uppercase

void convert(string& s2)
{
for (int i = 0; i < s2.length(); i++)
	{
		s2[i] = toupper(s2[i]);
	}
}

//check if scrubbed string is a palindrome
// create a temporary string s3 by adding charcters from the string s2 - from right to left
// Then compare charcters in two strings with the same index
// If they all match, it is a palindrome, if not, it is not a palindrome
bool is_palindrome(string& s2)
{
	string s3 = "";
	for (int i = s2.size()-1; i >= 0; i--)
	{
		s3 += s2[i];
	}
	for (int i = 0; i < s2.length(); i++)
	{
		if (s2[i] == s3[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}