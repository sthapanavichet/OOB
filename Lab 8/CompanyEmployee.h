//
// Created by Sthapanavichet on 7/21/2023.
//

#ifndef LAB_8_COMPANYEMPLOYEE_H
#define LAB_8_COMPANYEMPLOYEE_H
#include <string>
#include "CompanyCommon.h"
class CompanyEmployee {
    static int numMember;
    StandardEmployee* List;
public:
    CompanyEmployee();
    bool AddPersonnel(int);
    bool FindPersonnel(std::string, StandardEmployee&);
    double CalculateSalary(std::string);
};
#endif //LAB_8_COMPANYEMPLOYEE_H
