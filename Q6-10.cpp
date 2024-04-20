//store and output user's weught in pounds
#include<iostream>
#include<cstdlib>
using namespace std;

class Weight {                                                            //a class named weight
public:
	void setWeightPounds(double user_weight) { weight = user_weight; }    //functions to set weight
	void setWeightKilograms(double user_weight) { weight = user_weight * 2.21; }
	void setWeightOunces(double user_weight) { weight = user_weight / 16; }
	double getweightP() { return(weight); }                               //functions to return weight
	double getweightK() { return(weight / 2.21); }
	double getweightO() { return(weight * 16); }
private:
	double weight;                                                        //store weight in pounds
};

int main(void) {
	Weight User;                                                          //declare a class
	double weight;                                                        //store input
	int choice;                                                           //store user's choice
	
	cout << "Which way do you want to enter your weight?" << endl;        //let user input
	cout << "1 means in pounds, 2 maens in kilograms, 3 means ounces: ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Input your weight >> ";
		cin >> weight;
		User.setWeightPounds(weight);                                            //call a function to set
		cout << "Your weight is " << User.getweightP() << " pounds." << endl;    //output message
		break;
	case 2:
		cout << "Input your weight >> ";
		cin >> weight;
		User.setWeightKilograms(weight);
		cout << "Your weight is " << User.getweightK() << " kilograms." << endl;
		break;
	case 3:
		cout << "Input your weight >> ";
		cin >> weight;
		User.setWeightOunces(weight);
		cout << "Your weight is " << User.getweightO() << " ounces." << endl;
		break;
	default:                                                                     //if error 
		cout << "Input,error!" << endl;                                          //error message
		exit(1);
	}

	system("pause");
	return(0);
}