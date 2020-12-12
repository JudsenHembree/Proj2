#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Product.h"

using namespace std;

Product::Product(){}//default con

Product::Product(const string& GTIN,const string& Name, float Wholesale,const string& Description) :
    GTIN{GTIN}, Name{Name}, Wholesale{Wholesale}, Description{Description}
{
}
Product::~Product(){}//destructor

void Product::setGTIN(const string& g){
    /*if(g.length()!=13){
        throw invalid_argument("Sorry GTINs must be 12 characters long. \
                Please enter a valid GTIN.");
    }else{
        GTIN=g;
    }
    */
    GTIN=g;
}

void Product::setName(const string& n){
    Name=n;
}

void Product::setWholesale(float w){
    Wholesale=w;
}


void Product::setDescription(const string& d){
    Description=d;
}

string Product::getGTIN() const{
    return GTIN;
}

string Product::getName() const{
    return Name;
}

float Product::getWholesale() const{ 
    return Wholesale;
}

string Product::getDescription() const{
    return Description;
}

void Product::showProduct() const{
    cout<<GTIN<<" * "<<Name<<" * "<<Wholesale<<" * "<<Description;
}

