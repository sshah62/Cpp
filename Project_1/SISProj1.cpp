//SISProj1.
//Software used: Visual Studio 2012 Operting System: Windows 10.


#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "product.h";

using namespace std;

int main(int argc, char *argv[])
{
	string line;
	ifstream myFile;
	LARGE_INTEGER start, stop, frequency;
	double CPUTimeUsed;

	
	if (argc != 2) //argc must me 2. program name and input file name only
	{
		//Error message
		cout << "usage: " << argv[0] << " <filename> \n";
	}
	else
	{
		ifstream myFile (argv[1]);
	}
	//check for file opening success
	if (!myFile.is_open())
	{
		cout << "Could not open file \n" ;
	}
	else
	{
		//start = clock();
		//Calculate number of ticks per second
		QueryPerformanceFrequency(&frequency);

		//Start th tick counter
		QueryPerformanceCounter(&start);
		vector <Product> myProducts;
		int i = 0;
		
		
		while (getline (myFile, line))
		{
			Product aProduct = Product();	

			cout << line << endl;
			aProduct.setId(line);

			getline(myFile, line);
			cout << line << endl;
			aProduct.setCategory(line);

			getline(myFile, line);
			cout << line << endl;
			aProduct.setCondition(line);

			getline(myFile, line);
			cout << line << endl;
			aProduct.setName(line);

			getline(myFile, line);
			cout << line << endl;
			aProduct.setAvailibility(line);

			getline (myFile, line);
			cout << line << endl;
			aProduct.setColor(line);

			getline(myFile, line);
			cout << line << endl;
			aProduct.setPrice(line);

			getline(myFile, line);
			cout << line << endl;
			aProduct.setDelineator(line);
			//throw an exception here for delineator not being **

			myProducts.push_back(aProduct);
		}
		myFile.close();

		//Query 1: Total number of Products
		cout << "There are "<< myProducts.size() << "in the" << myFile << endl << endl;

		// Query 2: Number of Available Products in each Product Condition Type
		//Query 3: Most expensive product in each condition Type
		//These 2 Queries are combined to save program execution time
		
		//Create a vector for each category and populate them
		vector <Product> newProducts; vector <Product> usedProducts; vector <Product> refurbProducts;
		for (int i = 0; i < myProducts.size()-1; ++i)
		{
			if (myProducts[i].getCondition() == "new")
			{
				newProducts.push_back(myProducts[i]);
			}
			else if (myProducts[i].getCondition() == "used")
			{
				usedProducts.push_back(myProducts[i]);
			}
			else if (myProducts[i].getCondition() == "refurbished")
			{
				refurbProducts.push_back(myProducts[i]);
			}
		}
		//Create price (double) vectors for each category
		vector<double> newProductPrices; 
		vector<double> usedProductPrices; 
		vector<double> refurbProductPrices;
		
		//Find Highest Price in "new" using *max_element method

		for (int i = 0; i < newProducts.size()-1; ++i)
		{
			double n = stod(newProducts[i].getPrice());
			newProductPrices.push_back(n);
		}
		double maxNew = *max_element(newProductPrices.begin(),newProductPrices.end());
		string maxNewStr = to_string(maxNew);
		for (int i = 0; i < newProducts.size()-1; ++i)
		{
			if (newProducts[i].getPrice() == maxNewStr)
			{
				cout << "There are " << newProducts.size() << " new items in " << myFile << endl;
				cout << "The highest priced new Product is " << newProducts[i].getName()<< "." << endl;
				cout << "And its price is $" << newProducts[i].getPrice() << "." << endl << endl;
			}
		}

		//Find Highest Price in "used" using *max_element method

		for (int i = 0; i < usedProducts.size()-1; ++i)
		{
			double n = stod(usedProducts[i].getPrice());
			usedProductPrices.push_back(n);
		}
		double maxUsed = *max_element(usedProductPrices.begin(),usedProductPrices.end());
		string maxUsedStr = to_string(maxUsed);
		for (int i = 0; i < usedProducts.size()-1; ++i)
		{
			if (usedProducts[i].getPrice() == maxUsedStr)
			{
				cout << "There are " << usedProducts.size() << " used items in " << myFile << endl;
				cout << "The highest priced used Product is " << usedProducts[i].getName()<< "." << endl;
				cout << "And its price is $" << usedProducts[i].getPrice() << "." << endl <<endl;
			}
		}
		//Find Highest Price in "refurbished" using *max_element method

		for (int i = 0; i < refurbProducts.size()-1; ++i)
		{
			double n = stod(refurbProducts[i].getPrice());
			refurbProductPrices.push_back(n);
		}
		double maxRefurb = *max_element(refurbProductPrices.begin(),refurbProductPrices.end());
		string maxRefurbStr = to_string(maxRefurb);
		for (int i = 0; i < refurbProducts.size()-1; ++i)
		{
			if (refurbProducts[i].getPrice() == maxRefurbStr)
			{
				cout << "There are " << refurbProducts.size() << " refurbished items in " << myFile << endl;
				cout << "The highest priced refurbished Product is " << refurbProducts[i].getName()<< "." << endl;
				cout << "And its price is $" << refurbProducts[i].getPrice() << "." << endl << endl;
			}
		}

		//Query 4: The Title and Price of the least expensive product

		//Find lowest Price in "new" using *min_element method

		double minNew = *min_element(newProductPrices.begin(),newProductPrices.end());
		string minNewStr = to_string(minNew);
		for (int i = 0; i < newProducts.size()-1; ++i)
		{
			if (newProducts[i].getPrice() == minNewStr)
			{
				cout << "The lowest priced new Product is " << newProducts[i].getName()<< "." << endl;
				cout << "And its price is $" << newProducts[i].getPrice() << "." << endl << endl;
			}
		}

		//Find lowest Price in "used" using *min_element method

		double minUsed = *min_element(usedProductPrices.begin(),usedProductPrices.end());
		string minUsedStr = to_string(minUsed);
		for (int i = 0; i < usedProducts.size()-1; ++i)
		{
			if (usedProducts[i].getPrice() == minUsedStr)
			{
				cout << "The lowest priced used Product is " << usedProducts[i].getName()<< "." << endl;
				cout << "And its price is $" << usedProducts[i].getPrice() << "." << endl;
			}
		}
		//Find lowest Price in "refurbished" using *min_element method

		double minRefurb = *min_element(refurbProductPrices.begin(),refurbProductPrices.end());
		string minRefurbStr = to_string(minRefurb);
		for (int i = 0; i < refurbProducts.size()-1; ++i)
		{
			if (refurbProducts[i].getPrice() == minRefurbStr)
			{
				cout << "The lowest priced refurbished Product is " << refurbProducts[i].getName()<< "." << endl;
				cout << "And its price is $" << refurbProducts[i].getPrice() << "." << endl;
			}
		}
		//Query 5: The Average price of all products

		//calculate average price
		double return_value = 0.0;
              
        for ( int i=0; i < newProductPrices.size(); ++i)
        {
            return_value += newProductPrices[i];
        }

		for ( int i=0; i < usedProductPrices.size(); ++i)
        {
            return_value += usedProductPrices[i];
        }

		for ( int i=0; i < refurbProductPrices.size(); ++i)
        {
            return_value += refurbProductPrices[i];
        }
       
        double averagePrice = return_value / (newProductPrices.size() + usedProductPrices.size() + refurbProductPrices.size());
		cout << "Average Product Price (for All Product Categories, All Conditions) is: $" << averagePrice << endl << endl << endl;

		CPUTimeUsed = (stop.QuadPart - start.QuadPart)/(frequency.QuadPart/1000);

		cout << "Total Elapsed Time to execute this program: : " << CPUTimeUsed << " milliseconds" <<endl;
	}
	return 0;
}