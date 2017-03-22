/* 
Sanjiv Shah, CS2363, Spring 2016, Monday (evening class)
Assignment #1 Convert Integers to roman numerals and roman numerals to integer numbers
Due date:Feb.7, 2016

*/
# include <iostream>
#include <string>
using namespace std;

bool convertRomanToInteger(string s, int&  d);
bool convertIntegerToRoman(int d, string & r);
int count_substrings(string substring, string s);


int main()
{
	std::string first_input;
	int d = 0;
	std::string r;
	std::string s;
	std::string s_int;
	
	while (true)

	{
		//Prompt for input
		cout << "Please enter 1 for Roman to Integer Conversion" << endl;
		cout << "Please enter 2 for Integer to Roman Conversion" << endl;
		cout << "Enter any other key to exit" << endl;

		cin >> first_input;

		//Roman numeral to Integer Conversion
		if (first_input == "1")
		{
			cout << "Please enter a valid Roman numeral " << endl;
			cout << "WARNING: THIS PROGRAM WILL FAIL IF YOU ENTER A SINGLE CHARACTER" << endl;
			cin >> s;
			bool out_Integer = convertRomanToInteger(s, d);
			if(out_Integer)
			{
			cout << "(Roman) "<< s << " = " << d << " (Integer)" << endl;
			}
		}
		//Integer to Roman Numeral Conversion
		else if (first_input == "2")
		{
			cout << "please enter an Integer between 1 and 9,999" << endl;
			cin >> s_int;
			d = std::stoi (s_int);
			
			bool out_Roman = convertIntegerToRoman(d, r);
			if(out_Roman)
			{
				cout << d << " (Integer) = "<< r <<" (Roman)" << endl;
			}
		}
		else
		{
			cout << "Thank you for playing Roman Numeral Game" << endl;
			break;
		}
	}

	return EXIT_SUCCESS;
	
}

//Define function "count_substrings"
int count_substrings(string substring, string s)
{
	int count = 0;
	for(int i = 0; i <= s.length() - substring.length()+1; i++)
	{
		if(substring==(s.substr(i, substring.length())))
		{
			count++;
		}
	}
	return count;
}

/* Roman Numeral to Integer conversion function

*/
bool convertRomanToInteger(string s, int& d)
{
	//Validate Roman Numerals for correct order
	int n = count_substrings("IM", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("im", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("ID", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("id", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("IC", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("ic", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("IL", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("il", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("VM", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("vm", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("VD", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("vd", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("VC", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("vc", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("VL", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("vl", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("XM", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("xm", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	n = count_substrings("XD", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	n = count_substrings("xd", s);
	if (n != 0)
	{
		cout << "Invalid Roman Numeral " << endl;
		return false;
	}
	
	
	//Calculate Integer Value
	//Calculate value from each Roman Numeral in the string
	//Validate Roman Numeral String
	d = 0;
	n = 0;
	int valid_romans = 0;
	n = count_substrings("M", s);
	d += n * 1000;;
	valid_romans += n;

	n = count_substrings("m", s);
	d += n * 1000;
	valid_romans += n;

	n = count_substrings("D", s);
	d += n * 500;
	valid_romans += n;

	n = count_substrings("d", s);
	d += n * 500;
	valid_romans += n;
	
	n = count_substrings("C", s);
	d += n * 100;
	valid_romans += n;

	n = count_substrings("c", s);
	d += n * 100;
	valid_romans += n;
	
	n = count_substrings("L", s);
	d += n * 50;
	valid_romans += n;

	n = count_substrings("l", s);
	d += n * 50;
	valid_romans += n;
	
	n = count_substrings("X", s);
	d += n * 10;
	valid_romans += n;
 
	n = count_substrings("x", s);
	d += n * 10;
	valid_romans += n;

	n = count_substrings("V", s);
	d += n * 5;
	valid_romans += n;
 
	n = count_substrings("v", s);
	d += n * 5;
	valid_romans += n;

	n = count_substrings("I", s);
	d += n * 1;
	valid_romans += n;

	n = count_substrings("i", s);
	d += n * 1;
	valid_romans += n;

	//Check for valid roman characters
	if (valid_romans < s.length())
	{
		cout << "Invalid Roman Numeral Entered" << endl;
		return false;
	}

	//Calculate and subtract value from "reducing" prefixes
	int m = 0;
	n = count_substrings("CCM", s);
	if (n == 0)
	{
		m = count_substrings("CM", s);
		d -= m *200;
	}
	else
	{
		d -= n * 400;
	}
	
	n = count_substrings("ccm", s);
	if (n == 0)
	{
		m = count_substrings("cm", s);
		d -= m *200;
	}
	else
	{
		d -= n * 400;
	}
	
	n = count_substrings("CCD", s);
	if (n == 0)
	{
		m = count_substrings("CD", s);
		d -= m *200;
	}
	else
	{
		d -= n * 400;
	}
		 
	n = count_substrings("ccd", s);
	if (n == 0)
	{
		m = count_substrings("cd", s);
		d -= m *200;
	}
	else
	{
		d -= n * 400;
	}
	
	n = count_substrings("XXC", s);
	if (n == 0)
	{
		m = count_substrings("XC", s);
		d -= m *20;
	}
	else
	{
		d -= n * 40;
	}
	
	n = count_substrings("xxc", s);
	if (n == 0)
	{
		m = count_substrings("xc", s);
		d -= m *20;
	}
	else
	{
		d -= n * 40;
	}
	
	n = count_substrings("XXL", s);
	if (n == 0)
	{
		m = count_substrings("XL", s);
		d -= m *20;
	}
	else
	{
		d -= n * 40;
	}
	
	n = count_substrings("xxl", s);
	if (n == 0)
	{
		m = count_substrings("xl", s);
		d -= m * 20;
	}
	else
	{
		d -= n * 40;
	}
	
	n = count_substrings("IIV", s);
	if (n == 0)
	{
		m = count_substrings("IV", s);
		d -= m *2;
	}
	else
	{
		d -= n * 4;
	}
	
	n = count_substrings("iiv", s);
	if (n == 0)
	{
		m = count_substrings("iv", s);
		d -= m *2;
	}
	else
	{
		d -= n * 4;
	}
	
	n = count_substrings("IIX", s);
	if (n == 0)
	{
		m = count_substrings("IX", s);
		d -= m *2;
	}
	else
	{
		d -= n * 4;
	}
	
	n = count_substrings("iix", s);
	if (n == 0)
	{
		m = count_substrings("ix", s);
		d -= m *2;
	}
	else
	{
		d -= n * 4;
	}
	
	return true;

	
	
}
/* Convert Integer to Roman Numerals
Scope:
		1. Only integers between 1 and 4,999 can be converted to Roman Numerals
		2. Each Roman numeral character can only be used 5 times.
		3. The program will terminate if any character other than a valid roman numeral
			is used.
		4. Allowable characters are "M", "m", "D", "d", "C", "c", "L", "l", "X", "x",
			"V", "v", "I", "i"
Procedure:
---------------------------------------------------------------------
First divide the Integer by 1000
Use switch case to provide roman numerals for #of thousands
Now use remainder function d % 1000 and reduce the integer to 3 digits
divide this new value by 100
Use switch case to provide roman numerals for #of hundreds
Now use remainder function d % 100 and reduce the integer to 2 digits
divide this new value by 10
Use switch case to provide roman numerals for #of tens
Now use remainder function d % 10 and reduce the integer to 1 digit
Use switch case to provide roman numerals for #of ones
-------------------------------------------------------------------------
*/

bool convertIntegerToRoman(int d, string & r)
{
	//Find thousands and convert to Roman
	string r1;
	switch (d / 1000)
	{
	case 0: break;
	case 1: r1 = "M"; break;
	case 2: r1 = "MM"; break;
	case 3: r1 = "MMM"; break;
	case 4: r1 = "MMMM"; break;
	case 5: r1 = "MMMMM"; break;
	case 6: r1 = "MMMMMM"; break;
	case 7: r1 = "MMMMMMM"; break;
	case 8: r1 = "MMMMMMMM"; break;
	case 9: r1 = "MMMMMMMMM"; break;
	default:
		return false;
	}
	//Populate thousands in Roman characters
	r = r1; 
	
	//Find Hunderds and convert to Roman characters
	d = d % 1000;
	string r2;
	switch (d/100)
	{
	case 0: break;
	case 1: r2 = "C";break;
	case 2: r2 = "CC";break;
	case 3: r2 = "CCC";break;
	case 4: r2 = "CD";break;
	case 5: r2 = "D";break;
	case 6: r2 = "DC";break;
	case 7: r2 = "DCC";break;
	case 8: r2 = "DCCC";break;
	case 9: r2 = "DCD";	break;							
	default:
		break;
	
	}
	//Populate Hundreds in Roman characters
	r = r + r2;
	
	// Find tens and convert to Roman characters
	d = d % 100;
	string r3;
	switch (d/10)
	{
	case 0: break;
	case 1: r3 = "X";break;
	case 2: r3 = "XX";break;
	case 3: r3 = "XXX";break;
	case 4: r3 = "XL";break;
	case 5: r3 = "L";break;
	case 6: r3 = "LX";break;
	case 7: r3 = "LXX";break;
	case 8: r3 = "XXC";break;
	case 9: r3 = "XC";	break;							
	default:
		break;
	}
	//Populate tens in Roman characters
	r = r + r3;
	
	//// Find ones and convert to Roman characters
	d = d % 10;
	string r4;
	switch (d)
	{
	case 0: break;
	case 1: r4 = "I"; break;
	case 2: r4 = "II"; break;
	case 3: r4 = "III"; break;
	case 4: r4 = "IV"; break;
	case 5: r4 = "V"; break;
	case 6: r4 = "VI"; break;
	case 7: r4 = "VII"; break;
	case 8: r4 = "VIII"; break;
	case 9: r4 = "IX";	break;							
	default:
		break;
	
	}
	// Populate ones in Roman characters
	r = r + r4;
	
	return true; //boolean true and string r are passed to function
}