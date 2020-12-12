#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
#include "InventoryItem.h"

using namespace std;

class Inventory{
    private:
        vector <InventoryItem*> invItems;
        string infile_name;

    public:
        Inventory();
        ~Inventory();

        void list() const;
        void load(const string&);
        void save(const string&);
        void add(InventoryItem*);
        void addItem();
        void editItem();
        void deleteItem();
        unsigned findByGTIN(const string&);
};

#endif 

