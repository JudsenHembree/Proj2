#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <fstream>
#include "Product.h"

using namespace std;

class InventoryItem{
private:
    Product* prod;
    float retail;
    unsigned quantity;


public:
    //const
    InventoryItem();
    explicit InventoryItem(Product *, float, unsigned);

    //dest
    ~InventoryItem();


    //setter
    void setProduct(Product *);
    void setGTIN(const string&);
    void setName(const string&);
    void setWholesale(float);
    void setRetail(float);
    void setDescription(const string&);
    void setQuantity(unsigned);

    //getter
    Product * getProduct() const;
    string getGTIN() const;
    string getName() const;
    float getWholesale() const;
    float getRetail() const;
    string getDescription() const;
    unsigned getQuantity() const;
    
    //funcs

    void edit();
    void showItem();
    bool loadItem(ifstream&);
    bool readItem();
    void saveItem(ofstream&);

};








#endif
