//
// Created by Sthapanavichet on 7/21/2023.
//

//CompanyCommon.h - structures and functions for the company database

#ifndef _COMPANYBASE_H_
#define _COMPANYBASE_H_

#include <iostream>
#include <string>

struct StandardEmployee {
    std::string name;
    std::string position;
    double baseSalary;
    double profitSharing;
    double performanceBonus;
    double salary;
};

struct ExecutiveEmployee {
    std::string name;
    std::string position;
    double baseSalary;
    double stockOptionDividend;
    double perquisites;//Executive perquisites or "perks" constitute additional compensation for senior executives which are not available to other salaried employees.
    double salary;
};

const int MAX_SIZE = 1000;

template<typename T>
bool AddPersonnel(T& database, int num) {
    return database.AddPersonnel(num);
}
template<typename T, typename C>
bool FindPersonnel(T& database, std::string name, C& reference) {
    return database.FindPersonnel(name, reference);
}
template<typename T>
double CalculateSalary(T& database, std::string name) {
    return database.CalculateSalary(name);
}
//Implement the functions AddPeronnel(), FindPersonnel() and CalculateSalary() here.
//These should work for either type of database.


#endif// _COMPANYBASE_H_

