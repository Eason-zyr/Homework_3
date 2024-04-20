//calculate hot dog stands total sold of hot dogs
#include<iostream>
using namespace std;

class HotDogStand {                                       //a class named HotDogStand
public:
	HotDogStand(int id, int hd_sold);                     //self-defined constructor
	HotDogStand();                                        //default constructor
	void set_id(int id) { this->id = id; }                //id,sold get and set functions
	void set_sold(int sold) { this->hd_sold = sold; }
	int get_id() const { return(id); }
	int get_sold() const { return(hd_sold); }
	void JustSold() { hd_sold++, total_sold++; }          //to calculate how many hot dogs sold today
	static int gettotal() { return(total_sold); }         //return total sold;
private:
	static int total_sold;                                //static variable:total sold
	int id;                                               //private variable:id ,and hot dogs sold
	int hd_sold;
};

int HotDogStand::total_sold = 0;                          //initialize to 0

int main(void) {
	int id1, id2, id3, sold1, sold2, sold3;               //stand's informations and new sold today
	int new_sold1, new_sold2, new_sold3;
	cout << "Input three stand's id and how many hot dogs each sold." << endl;
	cout << "Ex.(4 42 6 23 8 12) >> ";
	cin >> id1 >> sold1 >> id2 >> sold2 >> id3 >> sold3;

	HotDogStand stand1(id1, sold1);                       //call constructors to establish 3 objects
	HotDogStand	stand2(id2, sold2);
	HotDogStand stand3(id3, sold3);

	cout << "Stand " << stand1.get_id() << " has sold " << stand1.get_sold() << endl;    //output results
	cout << "Stand " << stand2.get_id() << " has sold " << stand2.get_sold() << endl;
	cout << "Stand " << stand3.get_id() << " has sold " << stand3.get_sold() << endl;
	cout << "You have sold " << HotDogStand::gettotal() << " hot dogs now." << endl << endl;

	cout << "Input three stand's new sold today." << endl;
	cout << "Ex.(15 38 26) >> ";
	cin >> new_sold1 >> new_sold2 >> new_sold3;           //input today's new sold

	for (int i = 0; i < new_sold1; i++) {                 //call JustSold to calculate 
		stand1.JustSold();
	}
	for (int i = 0; i < new_sold2; i++) {
		stand2.JustSold();
	}
	for (int i = 0; i < new_sold3; i++) {
		stand3.JustSold();
	}
	
	cout << "Stand " << stand1.get_id() << " has sold " << stand1.get_sold() << endl;    //output results
	cout << "Stand " << stand2.get_id() << " has sold " << stand2.get_sold() << endl;
	cout << "Stand " << stand3.get_id() << " has sold " << stand3.get_sold() << endl;
	cout << "You have sold " << HotDogStand::gettotal() << " hot dogs today." << endl;

	system("pause");
	return(0);
}

HotDogStand::HotDogStand():id(0),hd_sold(0) {             //default constructor
}

HotDogStand::HotDogStand(int id,int hd_sold) {            //self-defined constructor
	this->id = id;
	this->hd_sold = hd_sold;
	total_sold += hd_sold;
}