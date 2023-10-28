#pragma once
#include <string>
using namespace std;

/* @Author
Student Name: Uğurcan Kurtuluş
Student ID : 150200082
Date: 4/22/2023 */

class University{
private:
    string faculty;
    string discount;
    string city;
    string uniName;
    string lang;
    string score_last;
    string range_last;
    string score_first;
    string range_first;
    string average_range;
    string average_score;

public:
    University* next;
    University(string, string, string, string, string, string, string, string, string, string, string);
    University* getNext();
    void set_up(University*);
    string get_uni();
    void printDetails();
};

class Department{
private:
    string department;
    int numOfUniversity;
    
public:

    Department* next;
    Department* prev;
    University* under;
    Department(string);
    Department(string department, int num_of_uni);
    Department* getNext();
    Department* getPrev();
    string get_Department();
    int get_numOfUni();
    void set_numOfUni(int);
    University* getunder();
    void increase();
    void set_next(Department* );
    void set_up(University*);
    void set_prev(Department*);
};