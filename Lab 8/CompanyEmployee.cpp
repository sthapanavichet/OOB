//
// Created by Sthapanavichet on 7/21/2023.
//

#include "CompanyEmployee.h"

using namespace std;
int CompanyEmployee::numMember = 0;
CompanyEmployee::CompanyEmployee() {
    List = nullptr;
}

bool CompanyEmployee::AddPersonnel(int num) {
    if(numMember + num > MAX_SIZE) return false;
    StandardEmployee* newList =  new (std::nothrow) StandardEmployee[numMember + num];
    if(newList == nullptr) return false;
    for(int i = 0; i < numMember; i++) {
        newList[i] = List[i];
    }
    for(int i = 0; i < num; i++) {

        cout << "Enter the employee's name: ";
        getline(cin, newList[numMember+i].name);

        cout << "Enter the employee's position: ";
        getline(cin, newList[numMember+i].position);

        cout << "Enter the employee's base salary: ";
        cin >> newList[numMember+i].baseSalary;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the employee's annual profit sharing amount: ";
        cin >> newList[numMember+i].profitSharing;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the employee's annual performance bonus: ";
        cin >> newList[numMember+i].performanceBonus;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    numMember += num;
    delete[] List;
    List = newList;
    return true;
}

bool CompanyEmployee::FindPersonnel(std::string name, StandardEmployee& reference) {
    for(int i = 0; i < numMember; i++) {
        if(!(List[i].name.compare(name))) {
            reference.name = List[i].name;
            reference.position = List[i].position;
            reference.baseSalary = List[i].baseSalary;
            reference.profitSharing = List[i].profitSharing;
            reference.performanceBonus = List[i].performanceBonus;
            return true;
        };
    }
    return false;
}

double CompanyEmployee::CalculateSalary(std::string name) {
    for(int i = 0; i < numMember; i++) {
        if(!(List[i].name.compare(name))) {
            List[i].salary = List[i].baseSalary + List[i].profitSharing + List[i].performanceBonus;
            return List[i].salary;
        }
    }
    return 0;
}