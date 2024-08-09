//
// Created by Sthapanavichet on 6/9/2023.
//
#include "course.h"
#include <iomanip>
Node::Node(std::string name, float code) : student_(name, code) {
    next_ = nullptr;
    std::cout << "Node created" << std::endl;
}

Course::Course(std::string code, std::string name) {
    code_ = code;
    name_ = name;
    list_.head = nullptr;
    list_.tail = nullptr;
    std::cout << "Course created" << std::endl;
}

void Course::display_students() {
    Node* current = list_.head;
    while(current != nullptr) {
        std::cout << "Student's name: " << current->student_.name_ << std::endl;
        std::cout << "Student's gpa: "  <<std::setprecision(1) << std::fixed << current->student_.gpa_ << std::endl;
        current = current->next_;
    }
    std::cout << std::endl;
}

Course Course::operator+(Node* newNode) {
    if(list_.head == nullptr) {
        list_.head = newNode;
        list_.tail = newNode;
        return *this;
    }
    list_.tail->next_ = newNode;
    list_.tail = newNode;
    return *this;
}