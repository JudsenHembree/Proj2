#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

using namespace std;

class Product{
private:
	string GTIN;
	string Name;
	float Wholesale;
	string Description;



public:
    //constructors
    Product();//default
	explicit Product(const string&,const string&,float,const string&);

    //destructors
    ~Product();
    

    //setters
    void setGTIN(const string&);
    void setName(const string&);
    void setWholesale(float);
    void setDescription(const string&);

    //getters
    string getGTIN() const;
    string getName() const;
    float getWholesale() const;
    string getDescription() const;

    //show
    void showProduct() const;

};

#endif
