//Product.h

#ifndef Product_H
#define Product_H

#include <iostream>
#include <string>


using namespace std;
class Product
{
public:
	string id;
	string category;
	string condition;
	string name;
	string availibility;
	string color;
	string price;
	string delineator;

	double priceD;
	
	
	//default contstructor
	Product();

	//consturctor with first and last name
	Product(string, string, string, string, string, string, string, string);

	//get Product ID
	string getId();

	//get Product Category
	string getCategory();

	//get Product Condition
	string getCondition();

	//get name
	string getName();

	//get Product availibility
	string getAvailibility();

	//get Product color
	string getColor();

	//get Product Price
	string getPrice();
	
	//get delineator
	string getDelineator();

	//set Product ID
	void setId(string);

	//set Product Category
	void setCategory(string);

	//set Product Condition
	void setCondition(string);

	//set Product Name
	void setName(string);

	//set Product Availibility
	void setAvailibility(string);

	//set Product color
	void setColor(string);

	//set Product Price
	void setPrice(string);

	//set Delineator
	void setDelineator(string);

};
#endif