//
// Created by Il Baia on 08/07/2020.
//

#include "GroupChat.h"

GroupChat::GroupChat(const std::string &nameChat, const std::string &description, const std::string &adminPrimaryKey, const std::vector<std::string> &usersPrimaryKeys)
                            : Chat(nameChat), nameChat(nameChat), description(description), adminPrimaryKey(adminPrimaryKey), usersPrimaryKeys(usersPrimaryKeys){
}

GroupChat::~GroupChat() {

}

bool GroupChat::addMessage(const std::shared_ptr<Message> &m) {
    auto it = find(usersPrimaryKeys.begin(), usersPrimaryKeys.end(), m->getOwner());
    if(it != usersPrimaryKeys.end())
        if(!m->getText().empty()){
            messages.push_back(m);
            if(m->getOwner() != adminPrimaryKey)
                this->notify();
            return true;
        }
    return false;
}

bool GroupChat::changeMessage(std::shared_ptr<Message> &m, const std::string &newText) {
    auto it = std::find(messages.begin(),messages.end(), m);
    if(it != messages.end()){
        ModifiedMessage *mM = new ModifiedMessage(newText, (*it)->getOwner(), (*it)->isRead());
        std::shared_ptr<Message> m_ptr = std::make_shared<ModifiedMessage>(*mM);
        std::replace(messages.begin(), messages.end(), *it, m_ptr);
        return true;
    }
    return false;
}

bool GroupChat::removeMessage(std::shared_ptr<Message> &m) {
    bool erase = false;
    auto it = find(messages.begin(), messages.end(), m);
    if(it!=messages.end()){
        messages.erase(it);
        erase = true;
    }
    return erase;
}

void GroupChat::readAllMessages() {
    std::cout<<std::endl<<"CHAT DI GRUPPO: "<<nameChat<<std::endl;
    for(auto it: messages)
        it->readMessage();
    std::cout<<std::endl;
}

bool GroupChat::readNewMessages() {
    bool newMes = false;
    for(auto it: messages) {
        if(!it->isRead()){
            if(!newMes){
                std::cout<<std::endl<<"NUOVI MESSAGGI DAL GRUPPO: "<<nameChat<<std::endl;
                newMes = true;
            }
            it->readMessage();
        }
    }
    std::cout<<std::endl;
    return newMes;
}


