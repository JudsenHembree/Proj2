/*
 * Eileen Kraemer
 * p2.cpp
 * implments the basic stor inventory application
 * in C++
 * Makes use of Inventory class, which uses the 
 * InventoryItem class, which uses the Product class
 * You should not need to make any changes to this file.
 */

#include "Inventory.h"
#include "Menus.h"
#include <string>

using namespace std;

void cont();
void edit_inventory(Inventory& inv);

int main(){
	Inventory myInventory;
	string response;
	string inv_infilename;
	string inv_outfilename;

	Menus::show_menu();
	cin >> response;
	cout << endl;

	while (response[0] != '0'){
		switch(response[0]){
			case '1':myInventory.list();
						cont();
						break;
			case '2':edit_inventory(myInventory);
						break;
			case '3':cout << "Please enter name of inventory file to load: ";
						cin >> inv_infilename;
						myInventory.load(inv_infilename);
						cout << "Inventory " << inv_infilename << " loaded."<< endl;
						break;
			case '4':cout << "Please enter name of inventory file to save to: ";
						cin >> inv_outfilename;
						myInventory.save(inv_outfilename);
						cout << "Inventory " << inv_outfilename << " saved."<< endl;
						break;
			default:	printf("Not a valid choice.\n");
		}// end switch
		Menus::show_menu();
		cin >> response;
	} // end while 
} // end main

void cont(){
	string response;           

   cout << "Enter any character to continue" << endl;
   cin >> response;
   return;
}

void edit_inventory(Inventory &inv){
	string response;	

	Menus::show_edit_menu();
	cin >> response;
	while (response[0] != '0'){
		switch (response[0]){
			case '1':inv.addItem();
						cout << "Item added " << endl;
						break;
			case '2':inv.editItem();
						cout << "Item updated if found " << endl;
						break;
			case '3':inv.deleteItem();
						cout << "Item deleted if found" << endl;
						break;
			default:	cout << "Not a valid choice " << endl;
		} // end switch
		Menus::show_edit_menu();
		cin >> response;
	} // end while

} // end editInventory




