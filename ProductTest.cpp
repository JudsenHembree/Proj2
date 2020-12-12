#include <array>
#include <vector>
#include "Product.h" 
using namespace std;

int main() {

   Product beans1("222333444555","Beans", 0.79, "Heinz_Baked_Beans");
	beans1.showProduct();

	Product tuna;
	tuna.setGTIN("123456789123");
	tuna.setName("Tuna");
	tuna.setWholesale(0.72);
	tuna.setDescription("COS_solid_white_7_oz");
	tuna.showProduct();

	Product *corn = new Product("444555666777","Corn",0.89,"WholeKernel_14_oz");
	corn->showProduct();

	Product const milk("111111111111", "Milk", 1.00, "Gallon_milk");
	milk.showProduct();

	// put them in a vector of Product * and iterate/show
	vector<Product *> productVector(0);
	cout << "productVector has " << productVector.size() << " entries " << endl;

	productVector.push_back(&beans1);
	productVector.push_back(&tuna);
	productVector.push_back(corn);
	cout << "productVector has " << productVector.size() << " entries " << endl;

	for (Product * prod: productVector){
		prod->showProduct();
	}

	// put them in a array of Product and iterate/show
	array<Product,4> productArray{beans1, tuna, *corn, milk};
	
	cout << "productArray has " << productArray.size() << " entries " << endl;
	for (Product prod: productArray){
		prod.showProduct();
	}

		
}



