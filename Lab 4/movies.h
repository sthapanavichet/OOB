//
// Created by Sthapanavichet on 6/2/2023.
//

#ifndef LAB_4_MOVIES_H
#define LAB_4_MOVIES_H
#define MAX_LENGTH 32
struct Movie {
    char title[MAX_LENGTH];
    float rating;
    Movie* next;
    Movie(char title_[MAX_LENGTH], float rating_);
};

class Movies {
private:
    static Movie* start_;
    static Movie* tail_;
    static int number_movies_;

public:
    Movies();
    ~Movies();
    bool add_movie();
    void display_movies();
};


#endif //LAB_4_MOVIES_H
