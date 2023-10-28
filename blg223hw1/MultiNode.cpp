#include <iostream>
#include <string>
#include "MultiNode.h"
using namespace std;
/* @Author
Student Name: Uğurcan Kurtuluş
Student ID : 150200082
Date: 4/22/2023 */

University::University(string faculty, string uni, string discount, string city, string language, string score_last, string range_last, string score_first, string range_first, string average_range, string average_score) {
	this->faculty = faculty;
	this->uniName = uni;
	this->discount = discount;
	this->city = city;
	this->lang = language;
	this->score_last = score_last;
	this->range_last = range_last;
	this->score_first = score_first;
	this->range_first = range_first;
	this->average_range = average_range;
	this->average_score = average_score;
}
string University::get_uni() {
	return this->uniName;
}
void University::set_up(University* next) {
	this->next = next;
}
University* University::getNext() {
	return this->next;
}
void University::printDetails() { 
	cout << "Faculty: " << this->faculty << endl;
	cout << "Discount: " << this->discount << endl;
	cout << "City: " << this->city << endl;
	cout << "Language: " << this->lang << endl;
	cout << "Score Last: " << this->score_last << endl;
	cout << "Range Last: " << this->range_last << endl;
	cout << "Score First: " << this->score_first << endl;
	cout << "Range First: " << this->range_first << endl;
	cout << "Score Average: " << this->average_score << endl;
	cout << "Range Average: " << this->average_range << endl;
	cout << "----------------" << endl;
}
Department::Department(string department) { //Constructor of Department
	this->department = department;
}
Department::Department(string department, int num_of_uni) { //Second Constructor of Department, it will be used in add_dep_uni_function
	this->department = department;                              //when a new department input is taken.
	this->numOfUniversity = num_of_uni;
}
void Department::set_up(University* under) {
	this->under = under;
}
string Department::get_Department() {
	return this->department;
}
int Department::get_numOfUni() {
	return this->numOfUniversity;
}
Department* Department::getNext() {
	return this->next;
}
Department* Department::getPrev() {
	return this->prev;
}
void Department::set_next(Department *next) {
	this->next = next;
}
void Department::increase() {
	// increase the number of university
	numOfUniversity++;
}
void Department::set_prev(Department *prev) {
	this->prev = prev;
}
void Department::set_numOfUni(int num_of_uni) {
	this->numOfUniversity = num_of_uni;
}