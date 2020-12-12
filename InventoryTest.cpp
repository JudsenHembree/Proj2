#include "InventoryItem.h"
#include "Inventory.h"

int main(){

	string inv_infilename;
	string inv_outfilename;

	cout << "In Inventory Test" << endl;
	Inventory inv;

	cout << "Please enter name of inventory file " << endl;
	cin >> inv_infilename;

	inv.load(inv_infilename);
	cout << "load completed " << endl;

	cout << "Inventory contains: " << endl;
	inv.list();

	cout << "Now try editing: (uses findByGTIN) " << endl;
	inv.editItem();
	
	cout << "List it again with updates: " << endl;
	inv.list();

	cout << "Now save it out to new inventory file " << endl;
	cout << "Please enter name of new inventory file " << endl;
	cin >> inv_outfilename;

	inv.save(inv_outfilename);
	cout << "save completed " << endl;

	return 0;

}
