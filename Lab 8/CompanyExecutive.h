//
// Created by Sthapanavichet on 7/21/2023.
//

#ifndef LAB_8_COMPANYEXECUTIVE_H
#define LAB_8_COMPANYEXECUTIVE_H
#include "CompanyCommon.h"
class CompanyExecutive {
    static int numMember;
    ExecutiveEmployee* List;
public:
    CompanyExecutive();
    bool AddPersonnel(int);
    bool FindPersonnel(std::string, ExecutiveEmployee&);
    double CalculateSalary(std::string);
};
#endif //LAB_8_COMPANYEXECUTIVE_H
