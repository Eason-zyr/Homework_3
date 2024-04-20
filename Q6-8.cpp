//Show two moneytary amounts
#include<iostream>
#include<cstdlib>
using namespace std;

class Money {                                //a class named Money
public:
	int getdollars() { return(dollars); }    //accessor functions of private variabls
	int getcents() { return(cents); }
	void setdollars(int dollar) {            //mutator functions of private variabls
		dollars = dollar;
	}
	void setcents(int cent) {
		cents = cent;
	}
	double amount();                         //change moneytary amount into double
private:
	int dollars;                             //two private variables,dollars and cents
	int cents;
};

int main(void) {
	Money USD1, USD2;                                      //two Money objects
	int dollar, cent;                                      //store dollar and cent
	double amount;                                         //store moneytary amount
	
	cout << "Show two moneytary amount (USD):" << endl;    //let User input 
	cout << "USD1:" << endl;
	cout << "How many dollars and cetns (EX.8 45) >> ";
	cin >> dollar >> cent;
	USD1.setdollars(dollar);                               //call functions to set
	USD1.setcents(cent);
	
	cout << "USD2:" << endl;
	cout << "How many dollars and cetns (EX.4 65) >> ";
	cin >> dollar >> cent;
	USD2.setdollars(dollar);
	USD2.setcents(cent);

	amount = USD1.amount();                                //call the function to calculate 
	cout << "USD1: $" << amount << endl;                   //show the result
	amount = USD2.amount();
	cout << "USD2: $" << amount << endl;

	system("pause");
	return(0);
}

double Money::amount() {                                   //use functions to get variable then calculate
	return(getdollars() + double(getcents()) / 100);
}