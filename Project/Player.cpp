//
// Created by Sthapanavichet on 7/23/2023.
//
#include "Player.h"
#include <stdlib.h>
PlayerBase::PlayerBase() {
    name = "";
    cash = 1000;
    sumDependantCards = 0;
}

PlayerBase::PlayerBase(std::string name_) {
    name = name_;
    cash = 1000;
    sumDependantCards = 0;
}

PlayerBase::PlayerBase(const PlayerBase& oldPlayer) {
    this->name = oldPlayer.name;
    this->cash = oldPlayer.cash;
    this->sumDependantCards = oldPlayer.sumDependantCards;
}

void PlayerBase::SetName(std::string name_) {
    name = name_;
}

std::string PlayerBase::GetName(void) {
    return name;
}

void PlayerBase::AddCash(int num) {
    cash += num;
}

int PlayerBase::GetCash() {
    return cash;
}

void PlayerBase::SetDependentCards(int numCards) {
    sumDependantCards = 0;
    for(int i = 0; i < numCards; i++) {
        sumDependantCards += (rand() % 10 + 2) / 2;
        // rand() % 10 generates from 0-9 so if want 1-5, we + 2 to make it range from 2 - 11
        // and we divide it by 2 to get 1-5. because 1 / 2 is 0 and we want 1-5.
    }
}

void PlayerBase::AddDependentCards(void) {
    sumDependantCards += (rand() % 10 + 2) / 2;
}

int PlayerBase::SumDependentCards(void) {
    return sumDependantCards;
}

PlayerBase::~PlayerBase() {
    name = "";
    cash = 0;
    sumDependantCards = 0;
}

PlayerBase PlayerBase::operator=(const PlayerBase& oldPlayer) {
    this->name = oldPlayer.name;
    this->cash = oldPlayer.cash;
    this->sumDependantCards = oldPlayer.sumDependantCards;
    return *this;
}

bool PlayerBase::operator<(const PlayerBase& basePlayer) {
    if(this->sumDependantCards < basePlayer.sumDependantCards) return true;
    else return false;
}

bool PlayerBase::operator>(const PlayerBase& basePlayer) {
    if(this->sumDependantCards > basePlayer.sumDependantCards) return true;
    else return false;
}

bool PlayerBase::operator==(const PlayerBase & basePlayer) {
    if(this->sumDependantCards == basePlayer.sumDependantCards) return true;
    else return false;
}

PlayerBase& PlayerBase::operator<<(int cash_) {
    this->cash += cash_;
    return *this;
}

PlayerBase& PlayerBase::operator>>(int cash_) {
    this->cash -= cash_;
    return *this;
}