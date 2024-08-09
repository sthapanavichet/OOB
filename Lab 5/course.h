//
// Created by Sthapanavichet on 6/9/2023.
//

#ifndef LAB_5_COURSE_H
#define LAB_5_COURSE_H
#include "student.h"
#include <iostream>

class Node {
public:
    Student student_;
    Node* next_;
    Node(std::string, float);
};
struct student_list {
    Node* head;
    Node* tail;
};

class Course {
private:
    std::string code_, name_;
    student_list list_;
public:
    Course(std::string, std::string);
    void display_students();
    Course operator+(Node*);
};
#endif //LAB_5_COURSE_H
