#pragma once

#include "MultiNode.h"
#include <string>

/* @Author
Student Name: Uğurcan Kurtuluş
Student ID : 150200082
Date: 4/22/2023 */

class MultiList{
private:
    Department* head;
    Department* tail;
public:
    MultiList();
    ~MultiList();
    void add_node(string, string, string, string, string, string, string, string, string, string, string, string);
    void add_uni_node(Department*,string, string, string, string, string, string, string, string, string, string, string);
    void add_dep_uni_node(Department*,string,string, string, string, string, string, string, string, string, string, string, string);    
    void select_department();
    void select_uni();
    void listDepartments();
};