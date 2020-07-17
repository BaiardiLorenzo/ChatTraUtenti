//
// Created by Il Baia on 03/07/2020.
//

#include "User.h"

int User::numUsers = 0;

User::User(const std::string &name, const int age, const char gender) : name(name), age(age), gender(gender){
    numUsers++;
    //primaryKey = name+std::to_string(numUsers)+std::to_string(age)+gender;
    primaryKey = name;
}

User::~User() {
}

std::shared_ptr<Chat> User::createPrivateChat(User &otherUser) {
    std::shared_ptr<Chat> chat_ptr = std::make_shared<PrivateChat>(primaryKey, otherUser.primaryKey);
    chats.insert(std::make_pair(otherUser.getPrimaryKey(), chat_ptr));
    otherUser.addChat(primaryKey, chat_ptr);
    return chat_ptr;
}

std::shared_ptr<Chat> User::findPrivateChat(const User &u) const {
    auto it=chats.find(u.getName());
    return (it->second);
}

std::shared_ptr<Chat> User::createGroupChat(const std::string &name, const std::string &description, const std::vector<User*> &participants) {
    std::vector<std::string> primaryKeysUsers;
    for(auto it: participants)
        primaryKeysUsers.push_back(it->getPrimaryKey());
    std::shared_ptr<Chat> chat_ptr = std::make_shared<GroupChat>(name, description, primaryKey, primaryKeysUsers);
    chats.insert(std::make_pair(name, chat_ptr));
    for(auto it: participants)
        it->addChat(name, chat_ptr);
    return chat_ptr;
}

std::shared_ptr<Chat> User::findGroupChat(const std::string &chatPrimaryKey) const{
    auto it = chats.find(chatPrimaryKey);
    return it->second;
}

void User::addChat(const std::string &key, std::shared_ptr<Chat> &chat_ptr) {
    chats.insert(std::make_pair(key, chat_ptr));
}

bool User::removeChat(const std::shared_ptr<Chat> &c) {
    bool removed = false;
    auto it = chats.find(c->getPrimaryKey());
    if(it != chats.end()){
        removed = true;
        chats.erase(it);
    }
    return removed;
}




