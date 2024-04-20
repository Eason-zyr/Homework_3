//Input grades and change into histogram 
#include<iostream>
#include<vector>
using namespace std;

int find_max(vector<int> grades);                        //a function to find max grade

int main(void) {
	vector<int> std_grades;                              //two vector arrays,one for stor grades,another for statistics
	vector<int> histogram;
	int grade, max_grade;                                //stor grade and max grade

	cout << "Input student's grade (-1 means the end) >> ";
	while (true) {                                       //let user to input grades,until -1 then terminate
		cin >> grade;
		std_grades.push_back(grade);
		if (grade == -1) {
			break;
		}
	}

	max_grade = find_max(std_grades);                    //call function to find max grade
	histogram.resize(max_grade + 1);                     //set size to max grade + 1 and elements to 0

	for (int i = 0; i < std_grades.size() - 1; i++) {    //size - 1 means do not count the end
		histogram.at(std_grades.at(i))++;                //calculate how many students each grade 
	}

	cout << "Following is the histogram of grades:" << endl;
	for (int i = 0; i < histogram.size(); i++) {         //output the histogram and the max grade
		if (histogram.at(i) != 0) {
			cout << "grade(s) of " << i << " : " << histogram.at(i) << "  ";
			for (int j = 0; j < histogram.at(i); j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
	cout << "The min grade is 0 " << ",and max grade is " << max_grade << endl;

	system("pause");
	return(0);
}

int find_max(vector<int> grades) {                       //find the max grade the return
	int max = 0;
	for (int i = 1; i < grades.size() - 1; i++) {
		if (grades.at(i) > max) {
			max = grades.at(i);
		}
	}
	return(max);
}