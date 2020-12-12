#include <iomanip>
#include <iostream>
#include <string>
#include "InventoryItem.h"

using namespace std;

InventoryItem::InventoryItem(){}//default con

InventoryItem::InventoryItem(Product * prod,float retail,unsigned quantity) :
    prod{prod}, retail{retail}, quantity{quantity}
{
}

InventoryItem::~InventoryItem(){}//destruct

//setters
void InventoryItem::showItem(){
    prod->showProduct();
    cout<<" * "<<retail<<" * "<<quantity;
}

void InventoryItem::setProduct(Product * p){
    prod=p;
}

void InventoryItem::setGTIN(const string& g){
    prod->setGTIN(g);
}

void InventoryItem::setName(const string& n){
    prod->setName(n);
}

void InventoryItem::setWholesale(float w){
    prod->setWholesale(w);
}

void InventoryItem::setRetail(float r){
    retail=r;
}

void InventoryItem::setDescription(const string& d){
    prod->setDescription(d);
}

void InventoryItem::setQuantity(unsigned q){
    quantity=q;
}

//Getters
Product * InventoryItem::getProduct() const{
    return prod;
}

string InventoryItem::getGTIN() const{
    return prod->getGTIN();
}

string InventoryItem::getName() const{
    return prod->getName();
}

float InventoryItem::getWholesale() const{
    return prod->getWholesale();
}

float InventoryItem::getRetail() const{
    return retail;
}

string InventoryItem::getDescription() const{
    return prod->getDescription();
}

unsigned InventoryItem::getQuantity() const{
    return quantity;
}

bool InventoryItem::loadItem(ifstream& in){
    string GTIN;
    string Name;
    float Wholesale;
    float Retail;
    string Description;
    unsigned Quantity;
    
    in>>GTIN>>quoted(Name)>>Wholesale>>Retail>>quoted(Description)>>Quantity;

    if (!in.good()){
        return false;
    }   

    Product *p = new Product(GTIN,Name,Wholesale,Description);
    setProduct(p);
    setRetail(Retail);
    setQuantity(Quantity);
    

    return true;
}

bool InventoryItem::readItem(){

    string GTIN;
    string Name;
    float Wholesale;
    float Retail;
    string Description;
    unsigned Quantity;

    cout<<"Enter: GTIN name wholesale retail description quantity"<<endl;
    cin>>GTIN>>quoted(Name)>>Wholesale>>Retail>>quoted(Description)>>Quantity;    

    if (!cin.good()){
        return false;
    }   

    Product *p = new Product(GTIN,Name,Wholesale,Description);
    setProduct(p);
    setRetail(Retail);
    setQuantity(Quantity);

    return true;
}

void InventoryItem::edit(){
    unsigned choice;

    cout<<" 1 - GTIN: "<<prod->getGTIN()<<endl;
    cout<<" 2 - name: "<<prod->getName()<<endl;
    cout<<" 3 - quantity: "<<quantity<<endl;
    cout<<" 4 - wholesale: "<<prod->getWholesale()<<endl;
    cout<<" 5 - retail: "<<retail<<endl;
    cout<<" 6 - description: "<<prod->getDescription()<<endl;
    cout<<"Enter number for field to update: ";
    cin>>choice;

    
    string G;
    string n;
    unsigned q;
    float w;
    float r;
    string d;
    switch(choice){

        case 1:
            cout<<"Please enter a new GTIN: ";
            cin>>G;
            prod->setGTIN(G);
            break;
        case 2:
            cout<<"Please enter a new name: ";
            cin>>quoted(n);
            prod->setName(n);
            break;
        case 3:
            cout<<"Please enter a new quantity: ";
            cin>>q;
            quantity=q;
            break;
        case 4:
            cout<<"Please enter a new wholesale: ";
            cin>>w;
            prod->setWholesale(w);
            break;
        case 5:
            cout<<"Please enter a new retail: ";
            cin>>r;
            retail=r;
            break;
        case 6:
            cout<<"Please enter a new description: ";
            cin>>quoted(d);
            prod->setDescription(d);
            break;
        default:
            cout<<"Invalid choice input"<<endl;

    }
}



void InventoryItem::saveItem(ofstream& out){
    out<<prod->getGTIN()<<" "<<quoted(prod->getName())<<" "<<prod->getWholesale()<<" "<<retail<<" "<<quoted(prod->getDescription())<<" "<<quantity<<endl;
}

