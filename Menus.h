#ifndef MENUS_H
#define MENUS_H

#include<iostream>
using namespace std;

class Menus{
public:
static void show_menu(){
	cout << "*************************************"<< endl;
	cout << "*                                   *"<< endl;
	cout << "* Enter the number of the desired   *"<< endl;
	cout << "* menu choice or enter 0 to exit.   *"<< endl;
	cout << "*                                   *"<< endl;
	cout << "* Store Manager: manual operations  *"<< endl;
	cout << "*   1 -  List inventory             *"<< endl;
	cout << "*   2 -  Edit inventory             *"<< endl;
	cout << "*                                   *"<< endl;
	cout << "* Store Manager: batch operations   *"<< endl;
	cout << "*   3 - Load inventory file         *"<< endl;
	cout << "*   4 - Save inventory file         *"<< endl;
	cout << "*                                   *"<< endl;
	cout << "*************************************"<< endl;
	cout << "Choice: ";
   return;
}

static void show_edit_menu(){
	cout << "*-----*-----*-----*-----*-----*----*"<< endl;
	cout << "*                                  *"<< endl;
	cout << "* * Inventory Editing Operations * *"<< endl;
	cout << "*                                  *"<< endl;
	cout << "* Enter menu choice or 0 to exit.  *"<< endl;
	cout << "*                                  *"<< endl;
	cout << "*   1 - Add new item               *"<< endl;
	cout << "*   2 - Edit item content          *"<< endl;
	cout << "*   3 - Delete item                *"<< endl;
	cout << "*                                  *"<< endl;
	cout << "************************************"<< endl;
	cout << "Choice: ";
   return;

}

};

#endif
