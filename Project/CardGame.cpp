//
// Created by Sthapanavichet on 7/27/2023.
//
#include "CardGame.h"
#include <iostream>]
#include <string.h>
using namespace std;
template<typename T>
CardGame<T>::CardGame(GameMode gameMode) {
    string name;
    int age;
    cout << "Enter the name of the Youth Player: ";
    getline(cin, name);
    cout << "Enter the youth's age: ";
    cin >> age;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Player[0] = new (std::nothrow) PlayerYouth<T>(name, age);

    cout << "Enter the name of the Adult Player";
    getline(cin, name);
    Player[1] = new (std::nothrow) PlayerAdult<T>(name);

    gameStatus = true;
}

template<typename T>
void CardGame<T>::run() {
    do {
        int bet;
        cout << "Enter the amount you both want to bet (MIN: $10, MAX: $300): $";
        cin >> bet;
        for (int i = 0; i < NUM; i++) {
            int num;
            cout << Player[i]->GetName() << ", how many dependent cards do you want?";
            cin >> num;
            Player[i]->SetDependentCards(num);

            cout << Player[i]->GetName() << ", how many attack cards do you want?";
            cin >> num;
            Player[i]->SetAttackCards(num);

            cout << Player[i]->GetName() << ", the sum of your cards is" << Player[i]->SumCards() << endl;

            char *ans;
            cout << "do you want to add a dependent card?[Y/N]: ";
            cin >> ans;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (strcmp(ans, "Y") or strcmp(ans, "y")) {
                Player[i]->AddDependentCards();
            }
            cout << Player[i]->GetName() << ", the sum of your cards is" << Player[i]->SumCards() << endl;

            cout << "do you want to add an attack card?[Y/N]: ";
            cin >> ans;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (strcmp(ans, "Y") or strcmp(ans, "y")) {
                Player[i]->AddAttackCards();
            }
            cout << Player[i]->GetName() << ", the sum of your cards is" << Player[i]->SumCards() << endl;
        }
        for(int i = 0; i < NUM; i++) {
            cout << Player[i]->GetName() << " has " << Player[i]->SumCards() << " points.";
        }
        if(Player[0]->SumCards() > 21) {
            cout << Player[0]->GetName() << " has a sum of " << Player[0]->SumCards() << ", which is over the limit." << endl;
            if(Player[1]->SumCards() > 21) {
                cout << Player[1]->GetName() << " has a sum of " << Player[1]->SumCards() << ", which is over the limit." << endl;
                cout << "Both players are over the limit and have been disqualified." << endl;
            }
            else {
                cout << Player[0]->GetName() << " has been disqualified for going over the limit. " << Player[1]->GetName() << " has won." <<endl;
                *Player[0] >> bet;
                *Player[1] << bet;
            }
        }
        else {
            if(Player[1]->SumCards() > 21) {
                cout << Player[1]->GetName() << " has a sum of " << Player[1]->SumCards() << ", which is over the limit." << endl;
                cout << Player[1]->GetName() << " has been disqualified for going over the limit. " << Player[0]->GetName() << " has won." <<endl;
                *Player[1] >> bet;
                *Player[0] << bet;
            }
            else {
                if(Player[1] > Player[0]) {
                    cout << Player[1]->GetName() << " has won." << endl;
                    *Player[0] >> bet;
                    *Player[1] << bet;
                }
                else if(Player[0] < Player[1]) {
                    cout << Player[0]->GetName() << " has won" << endl;
                    *Player[1] >> bet;
                    *Player[0] << bet;
                }
                else {
                    cout << "It's a draw." << endl;
                }
            }
        }
        for(int i = 0; i < NUM; i++) {
            cout << Player[i]->GetName() << " has $" << Player[i]->GetCash() << "." << endl;
        }
        if(Player[0]->GetCash() <= 0 or Player[1]->GetCash() <= 0) {
            cout << "The game is over." << endl;
            cout << "=================" << endl;
            gameStatus = false;
        }
    } while(gameStatus);
}