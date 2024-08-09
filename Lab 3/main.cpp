//#include <iostream>
//#include "patient.h"
//
//int main(){
//
//    Patient patient;
//
//    patient.edit_data();
//    patient.display_data();
//
//    patient.calculate_bmi();
//    patient.status_bmi();
//
//    return 0;
//}

#include <iostream>

class Student {
public:
    int id;

    // Constructor
    Student(int studentId) : id(studentId) {}

    // Copy constructor
    Student(const Student& other) : id(other.id) {
        std::cout << "Copy constructor called" << std::endl;
    }
};

int main() {
    Student student(123);              // Create student object
    Student new_student = student;     // Copy initialization, copy constructor called

    return 0;
}