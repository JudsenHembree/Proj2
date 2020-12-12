#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Product.h"

using namespace std;

Product::Product(string& GTIN, string& Name, float Wholesale, string& Description) :
    GTIN{GTIN}, Name{Name}, Wholesale{Wholesale}, Description{Description}
{
}

void Product::setGTIN(string& g){
    /*if(g.length()!=13){
        throw invalid_argument("Sorry GTINs must be 12 characters long. \
                Please enter a valid GTIN.");
    }else{
        GTIN=g;
    }
    */
    GTIN=g;
}

void Product::setName(string& n){
    Name=n;
}

void Product::setWholesale(float w){
    Wholesale=w;
}


void Product::setDescription(string& d){
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

void Product::showProduct(){
    cout<<GTIN<<Name<<Wholesale<<Description<<endl;
}

