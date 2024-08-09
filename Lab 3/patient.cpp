//
// Created by Sthapanavichet on 5/26/2023.
//
#include <iostream>
#include "patient.h"
using namespace std;
void Patient:: display_data(void) {
    cout << "Patient name: " << first_name_ << " " << last_name_ << endl;
    cout << "Age: " << age_ << " years old" << endl;
    cout << "Height: " << height_ << " m" << endl;
    cout << "Weight: " << weight_ << " kg" << endl;
}

void Patient::edit_data(void) {
    cout << "Enter patient's first name: ";
    cin >> first_name_;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case user entered more than 16 chars
    cout <<  "Enter patient's last name: ";
    cin >> last_name_;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case user entered more than 16 chars
    cout << "Enter patient's age: ";
    cin >> age_;
    cout << "Enter patient's weight: ";
    cin >> weight_;
    cout << "Enter patient's height: ";
    cin >> height_;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
float Patient::calculate_bmi(void) {
    return this->weight_ / (this->height_ * this->height_);
}
void Patient::status_bmi(void) {
    float bmi = this->calculate_bmi();
    if(bmi > 30) cout << "Your BMI status is: obese";
    else if(bmi > 25) cout << "Your BMI status is: overweight";
    else if(bmi > 18.5) cout << "Your BMI status is: normal";
    else cout << "Your BMI status is: underweight";
}