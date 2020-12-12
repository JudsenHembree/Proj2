#include <array>
#include <vector>
#include "InventoryItem.h" 
using namespace std;

int main() {

	/*
    * create Product beans1, an example product 
    * populate the fields with example data
    * display with the Product member function showProduct
    */
	Product beans1("222333444555","Beans", 0.79, "Heinz_Baked_Beans");
	cout << "1. Displaying beans1 with showProduct " << endl;
	beans1.showProduct();
	cout << endl;

	/*
    * create an Inventory Item, item1
    * and populate it with the beans1 product
    * the retail price and the quantity
    * via the constructor
    * display with the InventoryItem member function showItem()
    */
   InventoryItem item1(&beans1,1.23, 30);
	cout << "2. Displaying item1 with showItem " << endl;
	item1.showItem();
	cout << endl;

	/*
    * create Product tuna with the no-argument constructor
    * create InventoryItem item2 with 3 arg constructor
    * update fiels InventoryItem setter member functions
    */
	Product *tunaPtr = 
		new Product("123456789123","Tuna",0.72,"COS_solid_white_7_oz");
   InventoryItem item2(tunaPtr,1.19,40 );
	cout << "3. Displaying item2 with showItem " << endl;
	item2.showItem();
	cout << endl;

	string newGTIN{"444444555555"};
	string newDescription{"Starkist "};
	item2.setGTIN(newGTIN);
	item2.setDescription(newDescription);
	item2.setRetail(1.29);
	item2.setWholesale(0.88);

	cout << "4. Displaying item2's updated values with showItem " << endl;
	item2.showItem();
	cout << endl;

	/*
    * create new InventoryItem with dynamic memory allocation
    * using construtor that takes an existing product and 
    * the retail price and quantity
    * Display the InventoryItem that item2Ptr points to 
    * using the InventoryItem showItem() member function
    */
	InventoryItem * item2Ptr = new InventoryItem(tunaPtr, 1.19, 44);
	cout << "5. Displaying item2Ptrs content: " << endl;
	item2Ptr->showItem();
	cout << endl;

	/*
    * create the Product corn via dynamic memory allocation
    * Invoke the Product member function showProduct()
    */
	cout << "6. Displaying Product corn: " << endl;
	Product *corn = new Product("444555666777","Corn",0.89,"WholeKernel_14_oz");
	corn->showProduct();
	cout << endl;

	/*
    * Dynamically allocate a new Inventory Item
    * and display the contents
    */
	cout << "7. Displaying item3Ptr values : " << endl;
	InventoryItem * item3Ptr = new InventoryItem(corn, 1.12, 144);
	item3Ptr->showItem();
	cout << endl;

	/*
	 * read in InventoryItems from the inventory.txt file
    */

	/* open the file; report error & exit on failure */	
	ifstream inventoryFile("inventory.txt", ios::in);
	if (!inventoryFile){
		cerr << "Could not open inventory file" << endl;
		exit(EXIT_FAILURE);
	}

	/* 
	 * create an empty InventoryItem
    * fill it with values ready from the file
    * by invoking the InventoryItem member function loadItem
    */
	InventoryItem * item4Ptr = new InventoryItem();
	item4Ptr->loadItem(inventoryFile);

	/*
    * create an empty vector of Inventory Items
	 * and report the size using the vector class's size() function
    */
	vector<InventoryItem *> inventoryVector;
	cout << "8. inventoryVector now has : " 
		<< inventoryVector.size() << " entries " << endl;
	cout << endl;

	/*
    * place items into the vector
    * and again report the size
    */
	inventoryVector.push_back(&item1);
	inventoryVector.push_back(item2Ptr);
	inventoryVector.push_back(item3Ptr);
	inventoryVector.push_back(item4Ptr);
	cout << "9. Now inventoryVector now has : " 
		<< inventoryVector.size() << " entries " << endl;
	cout << endl;
	
/*
    * use the vector's iterator capabilities 
    * to visit each InventoryItem in the vector and 
    * display content using the InventoryItem member function showItem()
    */
	cout << "10. Display content of inventoryVector : " << endl;
	for (InventoryItem * item: inventoryVector){
		item->showItem();
	}
	cout << endl;


	/*
    * create another empty InventoryItem
    * and read in the values interactively
    * by using the InventoryItem readItem() member function
	 * then add it to the vector
    */

	InventoryItem * item5Ptr = new InventoryItem();
	item5Ptr->readItem();
	inventoryVector.push_back(item5Ptr);
	
	/*
    * again use the vector's iterator capabilities 
    * to visit each InventoryItem in the vector and 
    * display content using the InventoryItem member function showItem()
    */
	cout << "11. Display content of inventoryVector after readItem: " << endl;
	for (InventoryItem * item: inventoryVector){
		item->showItem();
	}
	cout << endl;

	/*
    * put the InventoryItems in an array and iterate
    * through and show them 
    */
 	array<InventoryItem,3> invArray{item1, *item2Ptr, *item3Ptr};
	
	cout << "12. invArray has " << invArray.size() << " entries " << endl;
	for (InventoryItem item: invArray){
		item.showItem();
	}
	cout << endl;

	/*
    * edit the content of item1
    */
	item1.edit();

	/*
    * count up the total items in inventory
    * and display the inventory one more time
    */
   int num_items{0};
	cout << "13. After editing item 1, the vector contains: " << endl;
	for (InventoryItem * item: inventoryVector){
		item->showItem();
		num_items += item->getQuantity();
	}
	cout << "for a total inventory of " << num_items
		  << " items " << endl;

	/*
    * Open a file and write out all the inventory items
    */

	ofstream outfile("inventory2.txt", ios::out);

    /* check for success */
   if(!outfile){
      cerr << "File could not be opened " << endl;
      exit(EXIT_FAILURE);
   }

	for (InventoryItem * item: inventoryVector){
		item->saveItem(outfile);
	}

	/* 
    * from the command line, visually inspect the content of inventory2.txt
    */


	// just to be tidy
	delete item2Ptr;  
	delete item3Ptr;
	delete item4Ptr;
	delete item5Ptr;

	// should we delete corn and tuna?  If so -- when? where?

	return 0;
		
}



