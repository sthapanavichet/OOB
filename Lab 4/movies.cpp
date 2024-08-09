//
// Created by Sthapanavichet on 6/2/2023.
//
#include "movies.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

Movie::Movie(char title_[MAX_LENGTH], float rating_) {
    strcpy(title, title_);
    rating = rating_;
    next = nullptr;
}

int Movies::number_movies_ = 0;
Movie* Movies::start_ = nullptr;
Movie* Movies::tail_ = nullptr;

Movies::Movies() {
    cout << "Your movie catalog has been created" << endl;
}

Movies::~Movies() {
    for(int i = 0; i < Movies::number_movies_; i++) {
        Movie *current = Movies::start_;
        Movies::start_ = Movies::start_->next;
        delete current;
    }
}

bool Movies::add_movie() {
    char title_[MAX_LENGTH];
    float rating_;
    cout << "Enter the name of the movie: ";
    cin >> title_;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the rating of the movie: ";
    cin >> rating_;
    fflush(stdin);
    if(Movies::number_movies_ == 0) {
        Movies::start_ = new (nothrow) Movie(title_, rating_);
        if(start_ == nullptr) return false;
        Movies::tail_ = Movies::start_;
        Movies::number_movies_++;
        return true;
    }
    Movies::tail_->next = new (nothrow) Movie(title_, rating_);
    if(Movies::tail_->next == nullptr) return false;
    Movies::tail_ = Movies::tail_->next;
    Movies::number_movies_++;
    return true;
}

void Movies::display_movies() {
    Movie* current = Movies::start_;
    for(int i = 0; i < Movies::number_movies_; i++) {
        cout << "Movie " << i+1 << ":" << endl;
        cout << "Title: " << current->title << endl;
        cout << "Rating: " << setprecision(2) << fixed <<current->rating << endl;
        current = current->next;
    }
}

