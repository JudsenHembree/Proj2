#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product{
private:
	string GTIN{""};
	string Name{""};
	float Wholesale{0};
	string Description{""};



public:
	//explicit Product(string= " ",string= " ", float=0,string " ");

        //setters
        void setProduct(string, string, float, string);
        void setGTIN(string);
        void setName(string);
        void setWholesale(float);
        void setDescription(string);

        //getters
        string getGTIN() const;
        string getName() const;
        float getWholesale() const;
        string getDescription() const;

        //show
        string showProduct();

    

};

#endif
