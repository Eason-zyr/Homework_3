//Calculate price and show your pizza
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Pizza {                                  //a class named Pizza
public:
	int gettype() { return(type); }            //members of type,size,two toppings,
	int getsize() { return(size); }            //and its accessor function
	int getpeps() { return(pepperoni); }
	int getches() { return(cheese_toppings); }
	void settype(int new_type) {               //members of type,size,two toppings,
		type = new_type;                       //and its mutator function
	}
	void setsize(int new_size) {
		size = new_size;
	}
	void setpeps(int new_peps) {
		pepperoni = new_peps;
	}
	void setches(int new_ches) {
		cheese_toppings = new_ches;
	}
	double computePrice();                     //compute price
	void outputDescription();                  //output function
private:
	int type;
	int size;
	int pepperoni;
	int cheese_toppings;
};

int main(void) {
	Pizza pizza = {};                                                        //initialize pizza
	int type, size, peps, ches;                                              //store informations

	cout << "Enter informatons of your pizza:" << endl << "type:" << endl;   //input informations
	cout << "1 means deep dish, 2 means hand tossed, 3 means pan." << endl;
	cout << "Enter the type of pizza >> ";
	cin >> type;
	pizza.settype(type);                                                     //call the function

	cout << "size:" << endl;
	cout << "10 means Small, 14 means Medium, 18 means Large." << endl;
	cout << "Enter the size of pizza >> ";
	cin >> size;
	pizza.setsize(size);

	cout << "How many pepperonis? >> ";
	cin >> peps;
	pizza.setpeps(peps);

	cout << "How many cheese toppings? >> ";
	cin >> ches;
	pizza.setches(ches);

	pizza.outputDescription();                     //output user's pizza

	system("pause");
	return(0);
}

double Pizza::computePrice() {                     //compute pizza price by the rule
	return(getsize() + 2 * (getpeps() + getches()));
}

void Pizza::outputDescription() {                  //descriptions of pizza
	string type, size;
	cout << endl << "The price of your pizza: $" << computePrice() << endl;
	cout << "The following is your pizza:" << endl;
	switch (gettype()) {
	case 1:
		type = "deep dish";
		break;
	case 2:
		type = "hand tossed";
		break;
	case 3:
		type = "pan";
		break;
	default:                                        //if error,output error message
		cout << "Input error";
		exit(1);
	}
	cout << "A " << type << " type,";
	switch (getsize()) {
	case 10:
		size = "small";
		break;
	case 14:
		size = "medium";
		break;
	case 18:
		size = "large";
		break;
	default:
		cout << "Input error";
		exit(1);                                    //if error,output error message
	}
	cout << "a " << size << " size,";
	cout << "has " << getpeps() << " pepperonis,";
	cout << "and " << getches() << " chesse toppings." << endl;
}