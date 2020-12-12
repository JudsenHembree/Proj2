#include <iostream>
#include "Inventory.h"

Inventory::Inventory(){}//default con

//destruct
Inventory::~Inventory(){
    for(unsigned i = 0; i < invItems.size(); i++){
        delete invItems[i];
    }
}

//load
void Inventory::load(const string& infile_name){
    ifstream infile(infile_name, ios::in);
	if (!infile){
		cerr << "Could not open inventory file" << endl;
		exit(EXIT_FAILURE);
    }
    while (infile){
        InventoryItem* item = new InventoryItem();
        bool result = item->loadItem(infile);
        if(result) invItems.push_back(item);
    }
    infile.close();
}

void Inventory::list() const{
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"# -GTIN   -name -quantity -wholesale -retail  -description"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    for(unsigned i = 0; i < invItems.size(); i++){
        cout<<i<<" ";
        if(invItems[i]){
            invItems[i]->showItem();
        }
        cout<<endl;
    }
    cout<<"-----------------------------------------------------------------------"<<endl;
}

void Inventory::save(const string& outfile){

    ofstream out(outfile, ios::out);
	if (!out){
		cerr << "Could not open save file" << endl;
		exit(EXIT_FAILURE);
    }

    for(unsigned i = 0; i < invItems.size(); i++){
        if(invItems[i]){
            invItems[i]->saveItem(out);
        }
    }
}


unsigned Inventory::findByGTIN(const string& GTIN){
    for(unsigned i = 0; i < invItems.size(); i++){
        if(GTIN==invItems[i]->getGTIN()){
            return i;
        }
    }
    return invItems.size();
}

void Inventory::editItem(){
    string potentialGTIN;
    unsigned index;

    cout<<"Enter GTIN of item to edit: ";
    cin>>potentialGTIN;

    index=findByGTIN(potentialGTIN);
    invItems[index]->edit();

}

void Inventory::addItem(){
    InventoryItem* item=new InventoryItem();
    item->readItem();
    invItems.push_back(item);
}

void Inventory::deleteItem(){
    string potentialGTIN;
    unsigned index;

    cout<<"Enter GTIN of item to edit: ";
    cin>>potentialGTIN;

    index=findByGTIN(potentialGTIN);
    if(index==invItems.size()){
        return;
    }
    delete invItems[index];
    invItems[index]=nullptr;

}

