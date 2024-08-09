//
// Created by Sthapanavichet on 6/16/2023.
//
#include "club.h"
#include <iostream>
#include <fstream>

Member Member::operator=(const Member& oldMember) {
    if(this != &oldMember) {
        this->id = oldMember.id;
        this->email = oldMember.email;
    }
    return *this;
}
Club::Club() {
    num_members_ = 0;
    members_ = nullptr;
}
Club::Club(const Club &oldClub) {
    this->num_members_ = oldClub.num_members_;
    this->members_.reset(new Member[num_members_]);
    for(int i = 0; i < num_members_; i++) {
        this->members_[i] = oldClub.members_[i];
    }
}

bool Club::add_member(const Member& newMember) {
    num_members_++;
    std::unique_ptr<Member[]> new_members_(new (std::nothrow) Member[num_members_]);
    if(new_members_ == nullptr) return false;
    for(int i = 0; i < num_members_-1; i++) {
        new_members_[i] = members_[i];
    }
    new_members_[num_members_-1] = newMember;
    members_ = move(new_members_);
    return true;
}

void Club::list_members() {
    for (int i = 0; i < num_members_; i++) {
        std::cout << "Member " << i+1 << std::endl;
        std::cout << "ID: " << members_[i].id << std::endl;
        std::cout << "Email: " << members_[i].email << std::endl;
    }
}

void Club::save_club(std::string name) {
    std::ofstream write_file;
    write_file.open(name, std::ios::out);
    if(write_file.is_open()) {
        write_file << num_members_ << std::endl;
        for(int i = 0; i < num_members_; i++) {
            write_file << members_[i].id << std::endl;
            write_file << members_[i].email << std::endl;
        }
    }
    else {
        std::cout << "Couldn't open file.";
    }
}

void Club::retrieve_club(std::string name) {
    std::ifstream read_file;
    read_file.open(name, std::ios::in);
    if(read_file.is_open()) {
        read_file >> num_members_;
        members_.reset(new Member[num_members_]);
        for(int i = 0; i < num_members_; i++) {
            read_file >> members_[i].id;
            read_file >> members_[i].email;
        }
    }
    else {
        std::cout << "Couldn't open file.";
    }
}

Club Club::operator=(const Club& oldClub) {
    if(this != &oldClub) {
        this->num_members_ = oldClub.num_members_;
        this->members_.reset(new Member[this->num_members_]);
        for (int i = 0; i < this->num_members_; i++) {
            this->members_[i] = oldClub.members_[i];
        }
    }
    return *this;
}

