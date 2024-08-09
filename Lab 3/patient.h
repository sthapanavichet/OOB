//
// Created by Sthapanavichet on 5/26/2023.
//

#ifndef LAB_3_PATIENT_H
#define LAB_3_PATIENT_H
#define LENGTH 16
class Patient {
private:
    char first_name_[LENGTH];
    char last_name_[LENGTH];
    int age_;
    float weight_;
    float height_;
public:
    void display_data(void);
    void edit_data(void);
    float calculate_bmi(void);
    void status_bmi(void);
};
#endif //LAB_3_PATIENT_H
