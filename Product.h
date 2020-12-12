#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

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
	explicit Product(string&,string&,float,string&);

    //destructors
    ~Product();
    

    //setters
    void setGTIN(string&);
    void setName(string&);
    void setWholesale(float);
    void setDescription(string&);

    //getters
    string getGTIN() const;
    string getName() const;
    float getWholesale() const;
    string getDescription() const;

    //show
    void showProduct();

};

#endif
