// Sanjiv Shah, Advanced C++, Spring 2016, Homework # 3
//file postfix.cpp

#include <string>
#include <iostream>
#include <iomanip> 
#include <vector>


using namespace std;
string s;
string pi;
vector <int> postfix;

void process_str();


int main()
{
	cout << "** PLEASE READ THESE INSTRUCTIONS BEFORE USING THE PROGRAM:" << endl;
	cout << "**      1. When asked for input, Please enter a complete postfix sequence" << endl;
	cout << "**      2. The Program will process the entire sequence and display the answer" << endl;
	cout << "**      3. This answer will be wiped from memory before next operation " << endl;
	cout << "**         takes place" << endl;
	cout << "**      4. If you want to use this answer in the next operation, you must " << endl;
	cout << "**         enter it when asked to input another string input" << endl;
	cout << "**      5. To quit the program, please enter a string containing '0' by " << endl;
	cout << "**          itself followed by 'enter' key" <<endl;
	cout << " \n\n\n" << endl;
	cout << "Enter postfix sequence: " << endl;
	//Get input string
	getline(cin, s );
	while (s != "0")
	{
		s += " ";
    	int i;
		//Extract individual substrings separated by " "
		for (i = 0;  i < s.length(); i++)
		{
			if (s.at(i) != ' ')
			{
				pi += s.at(i);
			}
			else
			{
				//Use process_str function to process the string
				process_str();	
			}
		}
		//Send final result to the screen
		cout << "The answer is: " << postfix[0] << endl;
		postfix.clear();
		cout <<"Enter a valid postfix string to continue or 0 to terminate the program" <<endl;
		getline(cin, s );
	}
}
// define function process_ctr
void process_str()
{
	//First 2 strings - By definition of postfix, they are always numbers
	if (postfix.size() < 2)
	{
		//Check the numbers longer than one character for unary prefix
		if (pi.length() > 1 )
			{
				//If unary prefix '-' is found, convert resulting number to a -ve integer
				if (pi.at(0) == '-')
				{
					string newPi = pi.substr(1, pi.length()-1);
					int n = -1 * stoi(newPi);
					//add the negative number to the vector postfix
					postfix.push_back(n);
					pi = "";
				}
				//If unary prefix '+' is found, convert resulting number to a +ve integer
				else if (pi.at(0) == '+')
				{
					string newPi = pi.substr(1, pi.length()-1);
					int n = stoi(newPi);
					newPi = "";
					////add the +ve number to the vector postfix
					postfix.push_back(n);
					pi = "";
				}
				else
				{
					//If no unary prefix is found, convert the string to integer and add to the vector
					int n = stoi(pi);
					postfix.push_back(n);
					pi = "";
				}
			}
		//If the string is only one character, convert it to an integer and add to the vector
		else if (pi.length() == 1)
		{
			int n = stoi(pi);
			postfix.push_back(n);
			pi = "";
		}
		
	}
	//Processing alogrithm for successive substrings (after first 2)
	else
	{
		//Check the numbers longer than one character for unary prefix
		if (pi.length() > 1 )
			{
				if (pi.at(0) == '-')
				{
					string newPi = pi.substr(1, pi.length()-1);
					int n = -1 * stoi(newPi);
					postfix.push_back(n);
					pi = "";
				}
				else if (pi.at(0) == '+')
				{
					string newPi = pi.substr(1, pi.length()-1);
					int n = stoi(newPi);
					postfix.push_back(n);
					pi = "";
				}
				else
				{
					int n = stoi(pi);
					postfix.push_back(n);
					pi = "";
				}
			}
		//Process stings of one character length
		else if (pi.length() == 1)
		{
			//Check the string for binary operator
			if (pi.at(0) == '-' || pi.at(0) == '+' || pi.at(0) == '/' || pi.at(0) == '*' || pi.at(0) == '%')
			{
			
				//If a binary operator is found, temporarily store the value of last 2 numbers in the vector
				int m2 = postfix[postfix.size()-1];
				int m1 = postfix[postfix.size()-2];
				
				//remove the last 2 numbers from the vector
				postfix.pop_back();
				postfix.pop_back();
				//Perform binary mathematical operation depending on the operator
				switch (pi.at(0))
				{
				case '-': postfix.push_back(m1 - m2); break;
				case '+': postfix.push_back(m1 + m2); break;
				case '/': postfix.push_back(m1 / m2); break;
				case '*': postfix.push_back(m1 * m2); break;
				case '%': postfix.push_back(m1 % m2); break;
				m1 = 0;
				m2 = 0;
				}
				pi = "";
				
			}
			else
			{
				//If no binary operator found, convert the string to an integer and add it to the vector
				int n = stoi(pi);
				postfix.push_back(n);
				pi = "";
			}
		}
	}
}


