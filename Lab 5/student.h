//
// Created by Sthapanavichet on 6/9/2023.
//
#ifndef LAB_5_STUDENT_H
#define LAB_5_STUDENT_H
#include <string>

class Course;
class Student {
private:
    std::string name_;
    float gpa_;
public:
    Student(std::string, float);
    friend class Course;
};


#endif //LAB_5_STUDENT_H
