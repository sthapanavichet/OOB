//
// Created by Sthapanavichet on 5/19/2023.
//
#include <iostream>
#include "database.h"
using namespace std;
bool create_list(Data& data, int size) {
    if(size <= 0) return false;
    data.list_students = new (nothrow) Student[size];
    if(data.list_students == nullptr) return false; // return false if memory allocation fails
    data.size = size;
    for(int i = 0; i < size; i++) {
        cout << "Enter first name: ";
        cin >> data.list_students[i].first_name;
        cout << "Enter last name: ";
        cin >> data.list_students[i].second_name;
        cout << "Enter GPA: ";
        cin >> data.list_students[i].gpa;
    }
    return true;
}

void list_students(Data& data) {
    cout << "Number of students in database is: " << data.size << endl;
    cout << "Number of size of database in bytes is: " << sizeof(data.size) + (sizeof(Student) * data.size) << endl;
    for(int i = 0; i < data.size; i++) {
        cout << "Student's first name is " << data.list_students[i].first_name << endl;
        cout << "Student's last name is " << data.list_students[i].second_name << endl;
        cout << "Student's GPA is " << data.list_students[i].gpa << endl;
    }
}

void free_memory(Data& data) {
    if(data.list_students == nullptr) return; // exit function if there's nothing to deallocate.
    delete[] data.list_students;
}
