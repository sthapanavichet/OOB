//
// Created by Sthapanavichet on 7/21/2023.
//
#include "CompanyExecutive.h"

using namespace std;
int CompanyExecutive::numMember = 0;
CompanyExecutive::CompanyExecutive() {
    List = nullptr;
}

bool CompanyExecutive::AddPersonnel(int num) {
    if(numMember + num > MAX_SIZE) return false;
    ExecutiveEmployee* newList =  new (std::nothrow) ExecutiveEmployee[numMember + num];
    if(newList == nullptr) return false;
    for(int i = 0; i < numMember; i++) {
        newList[i] = List[i];
    }
    for(int i = 0; i < num; i++) {

        cout << "Enter the executive's name: ";
        getline(cin, newList[numMember+i].name);

        cout << "Enter the executive's position: ";
        getline(cin, newList[numMember+i].position);

        cout << "Enter the executive's base salary: ";
        cin >> newList[numMember+i].baseSalary;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the executive's annual stock option dividend: ";
        cin >> newList[numMember+i].stockOptionDividend;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the executive's annual perquisites: ";
        cin >> newList[numMember+i].perquisites;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    numMember += num;
    delete[] List;
    List = newList;
    return true;
}

bool CompanyExecutive::FindPersonnel(std::string name, ExecutiveEmployee& reference) {
    for(int i = 0; i < numMember; i++) {
        if(!(List[i].name.compare(name))) {
            reference.name = List[i].name;
            reference.position = List[i].position;
            reference.baseSalary = List[i].baseSalary;
            reference.stockOptionDividend = List[i].stockOptionDividend;
            reference.perquisites = List[i].perquisites;
            return true;
        };
    }
    return false;
}

double CompanyExecutive::CalculateSalary(std::string name) {
    for(int i = 0; i < numMember; i++) {
        if(!(List[i].name.compare(name))) {
            List[i].salary = List[i].baseSalary + List[i].stockOptionDividend + List[i].perquisites;
            return List[i].salary;
        }
    }
    return 0;
}