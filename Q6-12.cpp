//random box and change the item
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

class BoxOfProduce {                  //a class named BoxOfProduce
public:
	void setbox(string list[]);       //functions of the class,such as
	void changebox(string list[]);    //asseccor, mutator, change ,and output 
	void output();
	string getbox(int i);
private:
	string fruits[3];                 //an array store three items in the box
};

int main(void) {
	srand(time(NULL));                //every random result would be different 
	BoxOfProduce CSA_box;             //declare a class
	char choice;                      //user's choice
	string list[5];                   //an array store the list
	
	ifstream in;                      //file input stream
	in.open("F_or_V.txt");            //open and check the file
	if (in.fail()) {                  
		cout << "Failed to open the file!" << endl;
		exit(1);
	}
	for (int i = 0; i < 5; i++) {     //read the file into list and show
		in >> list[i];
	}
	cout << "Following is the list:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << list[i] << endl;
	}

	CSA_box.setbox(list);             //randomly put three items into box and show
	CSA_box.output();                 //ask user to change or not
	cout << "Do you wamt to change any of them? (Y/y(yes) or N/n(no) >> " << endl;
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		do {
			CSA_box.changebox(list);
			CSA_box.output();
			cout << "Change again? (Y/y or N/n) >> ";
			cin >> choice;
		} while (choice == 'Y' || choice == 'y');
	}

	cout << endl << "The final box to be delivered:" << endl;    //show the final result
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ". " << CSA_box.getbox(i) << endl;
	}

	system("pause");
	return(0);
}

void BoxOfProduce::setbox(string list[]) {                       //randomly set the box
	for (int i = 0; i < 3; i++) {
		fruits[i] = list[rand() % 5];
	}
}

void BoxOfProduce::output() {                                    //show current box
	cout << "Three types of vegetables or fruits now in box:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ". " << fruits[i] << endl;
	}
}

void BoxOfProduce::changebox(string list[]) {                       //change item
	int change, list_item;
	cout << "Which one you want to change? (1, 2,or 3) >> ";        //which to change
	cin >> change;
	cout << "Which item of list you want to put in?(1 ~ 5) >> ";    //which to put in
	cin >> list_item;
	switch (change) {
	case 1:
		fruits[0] = list[list_item - 1];
		break;
	case 2:
		fruits[1] = list[list_item - 1];
		break;
	case 3:
		fruits[2] = list[list_item - 1];
		break;
	default:                            //error message
		cout << "Input error!" << endl;
		exit(1);
	}
}

string BoxOfProduce::getbox(int i) {    //get item in box
	return(fruits[i]);
}