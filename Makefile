all:	Product.o InventoryItem.o Inventory.o	ProductTest InventoryItemTest InventoryTest p2

Product.o:	Product.h Product.cpp
	g++-6 -g -Wall -c Product.cpp 

InventoryItem.o:	InventoryItem.h InventoryItem.cpp
	g++-6 -g -Wall -c InventoryItem.cpp 

Inventory.o:	Inventory.h Inventory.cpp
	g++-6 -g -Wall -c Inventory.cpp 

ProductTest:	Product.o ProductTest.cpp
	g++-6 -g -Wall -o ProductTest Product.o ProductTest.cpp

InventoryItemTest:	InventoryItem.o Product.o InventoryItemTest.cpp
	g++-6 -g -Wall -o InventoryItemTest Product.o InventoryItem.o InventoryItemTest.cpp

InventoryTest:	Product.o InventoryItem.o Inventory.o InventoryTest.cpp 
	g++-6 -g -Wall -o InventoryTest Product.o InventoryItem.o Inventory.o InventoryTest.cpp

p2:	Product.o InventoryItem.o Inventory.o p2.cpp 
	g++-6 -g -Wall -o p2 Product.o InventoryItem.o Inventory.o p2.cpp

clean:
	rm Product.o; rm InventoryItem.o; rm Inventory.o; rm ProductTest; rm InventoryItemTest; rm InventoryTest; rm p2
