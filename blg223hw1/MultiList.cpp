#include <iostream>
#include <string>
#include "MultiList.h"
using namespace std;
/* @Author
Student Name: Uğurcan Kurtuluş
Student ID : 150200082
Date: 4/22/2023 */

MultiList::MultiList() {
	head = NULL;
	tail = NULL;
}
void MultiList::add_uni_node(Department *depPTR, string faculty, string uni, string discount, string city, string language, string score_last, string range_last, string score_first, string range_first, string range_average, string score_average) {
	
 // first we will create a new university object.
    University* new_university = new University(faculty, uni, discount, city, language, score_last, range_last, score_first, range_first, range_average, score_average);
	University* ptr = depPTR->getunder();
	University* ptr2 = NULL;

    // we will use an integer to check if the new_university will be added to the end of the list or not.
    // (0 means it will be added to the end of the list)
	int end_of_list_check = 0;

    //since the ptr equals to depptr->getunder if its null that means that department has no university object.
    // so we will basically set its up to new_university.
	if(ptr == NULL) {
		depPTR->set_up(new_university);
    //we will cover the situation that university is alphabetically supposed to add to the list before the head.
    //so now its the new head and previous heads' next is new_university.

	} else if(new_university->get_uni() < ptr->get_uni()) {
		new_university->set_up(ptr);
		depPTR->set_up(new_university);

    //now we will cover if it supposed to add into the middle or end, we will do that with end of the list check
    //if this while loop finds a university name alphabetically ahead of new_university, we will break the loop
    // and change end_of_list_check to 1, that means we will not add the new object to end.    
	} else {
		while(ptr->getNext() != NULL) {
			if(ptr->getNext()->get_uni() > new_university->get_uni()) {
				end_of_list_check = 1;
				break;
			}
			ptr = ptr->getNext();
		}
        // we will define a new pointer to hold the ptr's next address to not lose it.
		if(end_of_list_check == 1) {
			ptr2 = ptr->getNext();
		}
        // if we dont have ptr2 we will lose the ptr's next. 
		ptr->set_up(new_university);
		if(end_of_list_check == 0) {
            // since it's the end of the list, its' next will be NULL.
			new_university->set_up(NULL);
		} else {
			new_university->set_up(ptr2);
		}
	}
	depPTR->increase();
}
void MultiList::add_dep_uni_node(Department *preve, string department, string faculty, string uni, string discount, string city, string language, string score_last, string range_last, string score_first, string range_first, string range_average, string score_average) {
	Department* prev = preve;
    // first we will create a new department object and sets its under to null.
	Department* new_department = new Department(department, 0);
	new_department->set_up(NULL);
    // if in the add_node function add_dep_uni_node is called with null department pointer, that means
    // new_department will be the new head. 
	if(prev==NULL) {
		new_department->set_next(head);
		head->set_prev(new_department);
		head=new_department;

    // if prev is tail that means new_department will be the new tail and will be end of the list.    
	} else if(prev==tail) {
		tail->set_next(new_department);
		new_department->set_prev(tail);
		tail=new_department;
		new_department->set_next(NULL);
	} else {
        // otherwise we will put the new_department in the middle of list according to the prev pointer.
		Department* old_next= prev->getNext();
		new_department->set_next(old_next);
		new_department->set_prev(prev);
		prev->set_next(new_department);
		old_next->set_prev(new_department);
	}
    // we didn't cover the if the list is empty and new_department is the new tail and head because we did that
    // in the add_node function's inside. 

    // and after setting the department in the right place, we will call add_uni_node function.
	add_uni_node(new_department, faculty, uni, discount, city, language, score_last, range_last, score_first, range_first, range_average, score_average);
}
void MultiList::add_node(string department, string faculty, string uni, string discount, string city, string language, string score_last, string range_last, string score_first, string range_first, string range_average, string score_average) {
	Department* new_department = new Department(department);
	Department* p = head;
	Department* p2 = head;
	bool contains = false;
    // first we will check if department already exist or not.
	while(p2 != NULL && p2 != tail) { 
		if(p2->get_Department() == new_department->get_Department()) {
			contains = true;
			break;
		}
		p2=p2->getNext();
	}
	if(p2!=NULL && p2==tail) {
		if(p2->get_Department() == new_department->get_Department()) {
			contains = true;
		}
	}
    // if department exists, we simply call add_uni_function.
	if(contains) {
		add_uni_node(p2, faculty, uni, discount, city, language, score_last, range_last, score_first, range_first, range_average, score_average);
	} else {
        // if department doesn't exist, we first initialize it's number of university and under attributes.    
		new_department->set_numOfUni(0);
		new_department->set_up(NULL);
        // if head is NULL, new department will be head and tail of the list and we will call add_uni function.
		if(p == NULL) {
			head=new_department;
			tail=new_department;
			add_uni_node(new_department, faculty, uni, discount, city, language, score_last, range_last, score_first, range_first, range_average, score_average);
        // if new department comes before the first department, we will call add_dep_uni_node function
        // and sent pointer NULL.
        } else if(new_department->get_Department() < head->get_Department()) {
			p = NULL;
			add_dep_uni_node(p, department, faculty, uni, discount, city, language, score_last, range_last, score_first, range_first, range_average, score_average);
		//otherwise we will check every department to put the new department alphabetically.
        } else {
			while(p != NULL && p != tail) {
				if(p->getNext()->get_Department() > new_department->get_Department()) {
					break;
				}
				p=p->getNext();
			}
			add_dep_uni_node(p, department, faculty, uni, discount, city, language, score_last, range_last, score_first, range_first, range_average, score_average);
		}
	}
}
void MultiList::listDepartments() {
	Department* p = head;
    // we will traverse all the departments and print their attributes. 
	while(p->getNext() != nullptr) {
		cout << "Department: " << p->get_Department() << endl;
		cout << "Number of Universities of Department: " << p->get_numOfUni() << endl;
		cout << "---------------"<< endl;
		p = p->getNext();
	}
}
University* Department::getunder() {
	return this->under;
}
void MultiList::select_department() {
	// first calculating the department number.
	Department* counter_ptr = head;
	int department_counter = 0;
	while(counter_ptr != NULL){
		department_counter++;
		counter_ptr = counter_ptr->getNext();
	}
	
	cout << "To review a department, enter a number between 0 and the department number: ";
	int dep_num;	
	cin >> dep_num;
	// we'll check if the given input is lower than the department numbers' max.
	while(dep_num > department_counter-1){
	cout << "To review a department, enter a number between 0 and the department number: ";	
	cin >> dep_num;		
	}
	Department* ptr = head;
	if(dep_num == 0) {
		cout << "Department: " << ptr->get_Department() << endl;
	} else {
        // we will move forward in the list according to input and find the wanted department.
		for (int i = 0; i < dep_num; i++) {
			ptr = ptr->getNext();
		}
        // and print its attributes.
		cout << "Department: " << ptr->get_Department() << endl;
	}
        // then we will get its under to print the university attributes
        // we will traverse all universitys and print them. 
    University* ptr2 = ptr->getunder();
    for (int y = 0; y < ptr->get_numOfUni(); y++) {
		cout << y+1 << ": " << ptr2->get_uni() << endl;
		ptr2->printDetails();
		ptr2 = ptr2->getNext();
	}
}
void MultiList::select_uni() {
	cout << "To review a department, enter a number between 0 and the department number: ";
	int dep_num;
	cin >> dep_num;
	Department* ptr = head;

    // we will do the same thing we did in the select_department part.
	if(dep_num == 0) {
		cout << "Department: " << ptr->get_Department() << endl;
	} else {
		for (int i = 0; i < dep_num; i++) {
			ptr = ptr->getNext();
		}
		cout << "Department: " << ptr->get_Department() << endl;
	}

	cout << "To review a university of selected department, enter a number between 0 and the university number: ";
	int uni_num;
	cin >> uni_num;
	University* ptr2 = ptr->getunder();
    // we will start with the under and go forward according the input, when we find the
    // wanted university, we will print its details.
	if(uni_num == 0) {
		cout << "" << ptr2->get_uni() << endl;
	} else {
		for (int y = 0; y < uni_num; y++) {
			ptr2 = ptr2->getNext();
		}
		cout << "" << ptr2->get_uni() << endl;
		ptr2->printDetails();
	}
}
// we will start with the head and delete all the list members one by one.
MultiList::~MultiList() {
	Department* p = head;
	Department* n = head;
	while(n!=NULL) {
		n=p->getNext();
		delete p;
		p=n;
	}
}