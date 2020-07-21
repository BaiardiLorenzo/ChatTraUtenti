//
// Created by Il Baia on 03/07/2020.
//

#ifndef CHATTRAUTENTI_USER_H
#define CHATTRAUTENTI_USER_H


#include <string>
#include <memory>
#include <map>
#include <vector>

#include "Chat.h"
#include "PrivateChat.h"
#include "GroupChat.h"

class User {
public:
    static int numUsers;

    explicit User(const std::string &name, const int age, const char gender);

    ~User();

    std::shared_ptr<Chat> createPrivateChat(User &otherUser);

    std::shared_ptr<Chat> findPrivateChat(const User &u) const;

    std::shared_ptr<Chat> createGroupChat(const std::string &name, const std::string &description, const std::vector<User*> &participants);

    std::shared_ptr<Chat> findGroupChat(const std::string &chatPrimaryKey) const;

    void addChat(const std::string &chatPrimaryKey, std::shared_ptr<Chat> &chat_ptr);

    void removeChat(const std::shared_ptr<Chat> &c);

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        User::name = name;
    }

    int getAge() const {
        return age;
    }

    char getGender() const {
        return gender;
    }

    const std::string &getPrimaryKey() const {
        return primaryKey;
    }

    bool operator==(const User &right) const{
        return primaryKey == right.primaryKey;
    }

    bool operator!=(const User &right) const{
        return !(*this == right);
    }


private:
    std::string primaryKey;
    std::string name;
    int age;
    char gender;

    std::map<std::string, std::shared_ptr<Chat>> chats;
};


#endif //CHATTRAUTENTI_USER_H
