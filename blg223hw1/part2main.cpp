#include <iostream>

#include <string>

#include <fstream>

#include <cstring>

using namespace std;
/* @Author
Student Name: Uğurcan Kurtuluş
Student ID : 150200082
Date: 4/22/2023 */
int rows = 0;

bool perform_operation(char, string ** );
void print_menu();

void print_menu() {
  cout << "Choose an operation" << endl;
  cout << "L: List All Departments" << endl;
  cout << "D: Select a Department" << endl;
  cout << "U: Select a Department and University" << endl;
  cout << "E: Exit" << endl;
  cout << "Enter a choice {L,D,U,E}: ";
}

void sort_departments(string** arr){
     for (int i = 0; i < rows - 2; i++) {
      for (int j = 0; j < rows - i - 2; j++) {
        if (arr[j][0] > arr[j + 1][0]) {
          for (int k = 0; k < 12; k++) {
            string temp = arr[j][k];
            arr[j][k] = arr[j + 1][k];
            arr[j + 1][k] = temp;
          }
        }
      }
    }
}



bool perform_operation(char choice, string ** arr) {
  bool terminate = false;

  switch (choice) {
  case ('L'): {
    // First we'll sort the list. 
   sort_departments(arr);
    int uni_count = 0;
    // we'll find the number of university that department has.
    for (int m = 0; m < rows - 2; m++) {
      while (arr[m][0] == arr[m + 1][0]) {
        if (arr[m][2] == arr[m + 1][2]) {
          uni_count++;
        }
      }
      // to not print the same named department twice we'll use this if loop.
      if (arr[m] != arr[m + 1]) {
        cout << "Department: " << arr[m][0] << endl;
        cout << "Number of universities of department: " << uni_count << endl;
        cout << "--------------" << endl;
      } else {
        m = m + 1;
      }

    }
  }
  break;
  case ('D'): {
    int uni_count;
    int dep_number;
    cout << "To review a department, enter a number between 0 and the department number: " << endl;
    cin >> dep_number;
    sort_departments(arr);

      cout << "Department: " << dep_number << endl;

      // we will find the number of university  of this department
      while (arr[dep_number][0] == arr[dep_number + 1][0]) {
        if (arr[dep_number][2] == arr[dep_number + 1][2]) {
          uni_count++;
        }
      }
      // and print the universities.
      for (int y = 0; y < 12; y++) {
        cout << y << " : " << arr[dep_number][y] << endl;
      }
    }

  break;
  case ('U'): {
    int uni_number;
    int dep_number;
    cout << "To review a department, enter a number between 0 and the department number: " << endl;
    cin >> dep_number;
    sort_departments(arr);
    cout << "Department: " << dep_number << endl;
    cout << "To review a university of the selected department, enter a number between 0 and the university number: " << endl;
    cin >> uni_number;

    // we'll print the selected university
    for (int m = 0; m < 12; m++) {
      cout << "arr[dep_number+uni_number][i]" << endl;
    }
  }
  break;
  case 'E':
    exit(0);
    break;
  default:
    cout << "ERROR: You have entered an invalid choice" << endl << endl;
    print_menu();
    cin >> choice;
    terminate = perform_operation(choice, arr);
    break;
  }
  return terminate;
}

int main() {

  ifstream inFile;

  inFile.open("hw1.csv");
  if (!inFile.is_open()) {
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
  string delimiter = ";"; // If you need change the delimiter
  string afterDelimiter;
  bool header = true;
  string ** arr;
  int count = 0;
  const int columns = 12;
  // Count the number of rows in the file
  while (!inFile.eof()) {
    getline(inFile, row, '\n');
    if (!row.empty()) {
      rows++;
    }
  }
  arr = new string * [rows];
  for (int i = 0; i < rows; i++) {
    arr[i] = new string[columns];
  }
  // File reading is done in this loop.
  // You can change this while loop if you need
  inFile.close();
  inFile.open("hw1.csv");

  while (!inFile.eof()) {
    int i = 0;
    getline(inFile, row, '\n');

    size_t pos = 0;
    string token;
    while ((pos = row.find(delimiter)) != string::npos) {
      token = row.substr(0, pos); // token variable is the string before the delimiter
      afterDelimiter = row.substr(row.find(";") + 1);
      if (token != " ") {
        if (i == 0) departmentName = token;
        else if (i == 1) facultyName = token;
        else if (i == 2) uniName = token;
        else if (i == 3) discount = token;
        else if (i == 4) city = token;
        else if (i == 5) language = token;
        else if (i == 6) scoreLast = (token);
        else if (i == 7) rangeLast = (token);
        else if (i == 8) scoreFirst = (token);
        else if (i == 9) rangeFirst = (token);
        else if (i == 10) {
          averageRange = (token);
          averageScore = afterDelimiter; // since the substr() function takes the string before the delimiter averageScore attribute cannot be get from this function

        }
      }

      row.erase(0, pos + delimiter.length());
      i++;
    }
    if (header == false) {
      arr[count][0] = departmentName;
      arr[count][1] = facultyName;
      arr[count][2] = uniName;
      arr[count][3] = discount;
      arr[count][4] = city;
      arr[count][5] = language;
      arr[count][6] = scoreLast;
      arr[count][7] = rangeLast;
      arr[count][8] = scoreFirst;
      arr[count][9] = rangeFirst;
      arr[count][10] = averageScore;
      arr[count][11] = averageRange;

      count++;
    }

    header = false;

  }
  inFile.close();
  bool end = false;
  char choice;

  while (!end) {
    print_menu();
    cin >> choice;
    end = perform_operation(choice, arr);
  }

  return 0;

}