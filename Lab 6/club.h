//
// Created by Sthapanavichet on 6/16/2023.
//

#ifndef LAB_6_CLUB_H
#define LAB_6_CLUB_H
#include <string>
#include <memory>

struct Member {
    int id;
    std::string email;
    Member operator= (const Member&);
};

class Club {
private:
    int num_members_;
    std::unique_ptr<Member[]> members_;
public:
    Club();
    Club(const Club&);
    bool add_member(const Member&);
    void list_members();
    void save_club(std::string);
    void retrieve_club(std::string);
    Club operator= (const Club&);

};

#endif //LAB_6_CLUB_H
