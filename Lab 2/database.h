//
// Created by Sthapanavichet on 5/19/2023.
//
#ifndef LAB_2_DATABASE_H
#define LAB_2_DATABASE_H
#define LENGTH 16
struct Student {
    char first_name[LENGTH];
    char second_name[LENGTH];
    float gpa = 0;
};
struct Data {
    int size = 0;
    Student* list_students = nullptr;
};
bool create_list(Data&, int);
void list_students(Data&);
void free_memory(Data&);
#endif //LAB_2_DATABASE_H
