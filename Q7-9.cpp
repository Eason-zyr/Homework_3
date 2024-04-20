//zipcode encode and decode
#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std;

class zip_code {                                                         //a class named zip_code
public:
	zip_code() :zipcode() {};
	zip_code(int integer) { zipcode = encode(integer); }                 //default and self-defined constructor
	zip_code(string bar_code) :zipcode(bar_code){}
	void set_code(const int integer) { zipcode = encode(integer); }            //accessor and mutator functions
	void set_code(const string barcode) { zipcode = barcode; }
	int get_code_integer(string zipcode) { return(decode(zipcode)); }
	string get_code_string() const { return(zipcode); }
private:
	string zipcode;                                                      //private variable to stor code
	int decode(string barcode);                                          //private helper function (encode and decode)
	string encode(int integer);
};

int main(void) {
	int integer, choice;                                                 //store integer and user's choice
	string barcode;                                                      //stor barcode
	
	cout << "Choose you want to encode or decode:" << endl;              //choose encode or decode
	cout << "1. Input an integer as zip code and encode." << endl;
	cout << "2. Input a string as zip code and decode." << endl;
	cout << "Enter 1 or 2 to choose >> ";
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "Input an integer (5 digits) >> ";
		cin >> integer;
		zip_code zipcode(integer);                                       //constuct by integer
		barcode = zipcode.get_code_string();                             //get encoded result
		cout << "After encoded,the bar code is: " << barcode << endl;
		break;
	}
	case 2: {
		cout << "Input an barcode (27 digits) >> ";
		cin >> barcode;
		zip_code zipcode(barcode);                                       //constuct by barcode
		integer = zipcode.get_code_integer(barcode);                     //get decoded result
		cout << "After decoded,the bar code is: " << integer << endl;
		break;
	}
	default:
		cout << "Input error!" << endl;                                  //error message
		exit(1);
	}

	system("pause");
	return(0);
}

int zip_code::decode(string barcode) {                                   //decode then return 
	int integer = 0, digit = 0;                                          //store result and each digit
	for (int i = 1; i <= 21; i = i+5) {
		digit += ((barcode.at(i) - '0') * 7 + (barcode.at(i + 1) - '0') * 4
			+ (barcode.at(i + 2) - '0') * 2 + (barcode.at(i + 3) - '0') * 1);
		if (digit == 11) {
			digit = 0;
		}
		integer = integer * 10 + digit;
		digit = 0;
	}
	return(integer);
}

string zip_code::encode(int integer) {                                   //encode then return
	string barcode = "1";                                                //first letter must be 1
	string group;                                                        //store every 5 letters group
	int digit;                                                           //store each digit
	for (int i = 4; i >=0; i--) {
		digit = (integer / int(pow(10, i))) % 10;
		switch (digit) {
		case 0:
			group = "11000";
			break;
		case 1:
			group = "00011";
			break;
		case 2:
			group = "00101";
			break;
		case 3:
			group = "00110";
			break;
		case 4:
			group = "01001";
			break;
		case 5:
			group = "01010";
			break;
		case 6:
			group = "01100";
			break;
		case 7:
			group = "10001";
			break;
		case 8:
			group = "10010";
			break;
		case 9:
			group = "10100";
			break;
		default:
			cout << "Input error!" << endl;                              //error message
			exit(1);
		}
		barcode += group;
	}
	return(barcode + "1");
}