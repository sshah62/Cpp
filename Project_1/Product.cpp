//Product.cpp

#include "Product.h"
//#include <iostream>
//#include <string>

using namespace std;

//default constructor
Product::Product()
{
	id = "None";
	category = "None";
	condition = "None";
	name = "None";
	availibility = "None";
	color = "None";
	price = "None";
}

// Constructor with all parameters
Product::Product(string id, string category, string condition, string name, string availibility, string color, string price, string delieator)
{
	this -> id = id;
	this -> category = category;
	this -> condition = condition;
	this -> name = name;
	this -> availibility = availibility;
	this -> color = color;
	this -> price = price;
	this -> delineator = delineator;
}

//get Product ID
string Product::getId()
{
	return id;
}

//get Product Category
string Product::getCategory()
{
	return category;
}

//get Product Condition
string Product::getCondition()
{
	return condition;
}

//get name
string Product::getName()
{
	return name;
}

//get Product availibility
string Product::getAvailibility()
{
	return availibility;
}

//get Product color
string Product::getColor()
{
	return color;
}

//get Product Price
string Product::getPrice()
{
	return price;
}

//get Product Delineator
string Product::getDelineator()
{
	return delineator;
}

//set Product ID
void Product::setId(string pid)
{
	id = pid;
}

//set Product Category
void Product::setCategory(string cat)
{
	category = cat;
}

//set Product Condition
void Product::setCondition(string cnd)
{
	condition = cnd;
}

//set Product Name
void Product::setName(string nm)
{
	name = nm;
}

//set Product Availibility
void Product::setAvailibility(string aval)
{
	availibility = aval;
}

//set Product color
void Product::setColor(string clr)
{
	color = clr;
}

//set Product Price
void Product::setPrice(string pr)
{
	price = pr;
}

//set Product Delineator
void Product::setDelineator(string dln)
{
	delineator = dln;
}