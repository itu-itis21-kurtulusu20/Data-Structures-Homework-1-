#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "MultiList.h"
using namespace std;
/* @Author
Student Name: Uğurcan Kurtuluş
Student ID : 150200082
Date: 4/22/2023 */

bool perform_operation(char, MultiList*);
void print_menu();
void print_menu() {
	cout << "Choose an operation" << endl;
	cout << "L: List All Departments" << endl;
	cout << "D: Select a Department" << endl;
	cout << "U: Select a Department and University" << endl;
	cout << "E: Exit" << endl;
	cout << "Enter a choice {L,D,U,E}: ";
}
bool perform_operation(char choice, MultiList* departments) {
	bool terminate = false;
	switch (choice) {
		case 'L':
		    departments->listDepartments();
		break;
		case 'D':
		    departments->select_department();
		break;
		case 'U':
		    departments->select_uni();
		break;
		case 'E':
		    exit(0);
		break;
		default:
		        cout << "ERROR: You have entered an invalid choice" << endl << endl;
		print_menu();
		cin >> choice;
		terminate = perform_operation(choice, departments);
		break;
	}
	return terminate;
}
int main() {
	MultiList* new_multilist = new MultiList();
	ifstream inFile;
	inFile.open("hw1.csv");
	if(!inFile.is_open()) {
		cout << "ERROR: The File Cannot be Opened" << endl;
		return EXIT_FAILURE;
	}
	string discount;
	string city;
	string language;
	string scoreLast;
	string rangeLast;
	string scoreFirst;
	string rangeFirst;
	string averageRange;
	string averageScore;
	string departmentName;
	string facultyName;
	string uniName;
	string row;
	string delimiter = ";";
	// If you need change the delimiter
	string afterDelimiter;
	bool header = true;
	// File reading is done in this loop.
	// You can change this while loop if you need
	while(!inFile.eof()) {
		int i = 0 ;
		getline(inFile, row, '\n');
		size_t pos = 0;
		string token;
		while ((pos = row.find(delimiter)) != string::npos) {
			token = row.substr(0, pos);
			// token variable is the string before the delimiter
			afterDelimiter = row.substr(row.find(";") + 1);
			if(token != " ") {
				if(i == 0) departmentName=token; else if(i==1) facultyName = token; else if(i==2) uniName = token; else if(i==3) discount = token; else if(i==4) city = token; else if(i==5) language = token; else if(i==6) scoreLast = (token); else if(i==7) rangeLast = (token); else if(i==8) scoreFirst = (token); else if(i==9) rangeFirst = (token); else if(i==10) {
					averageRange = (token);
					averageScore = afterDelimiter;
					// since the substr() function takes the string before the delimiter averageScore attribute cannot be get from this function
				}
			}
			row.erase(0, pos + delimiter.length());
			i++;
		}
		if(header == false) {
			new_multilist->add_node(departmentName, facultyName, uniName, discount, city, language, scoreLast, rangeLast, scoreFirst, rangeFirst, averageRange, averageScore);
		}
		header = false;
	}
	inFile.close();
	bool end = false;
	char choice;
	while (!end) {
		print_menu();
		cin >> choice;
		end = perform_operation(choice, new_multilist);
	}
	return 0;
}