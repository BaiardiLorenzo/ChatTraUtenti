//
// Created by Il Baia on 08/07/2020.
//
#include "PrivateChat.h"

PrivateChat::PrivateChat(const std::string &me, const std::string &otherUser): Chat(me+"-"+otherUser), firstUserPrimaryKey(me), secondUserPrimaryKey(otherUser){
}

PrivateChat::~PrivateChat() {

}

bool PrivateChat::addMessage(const std::shared_ptr<Message> &m) {
    if(m->getOwner() == firstUserPrimaryKey || m->getOwner() == secondUserPrimaryKey)
        if(!m->getText().empty()){
            messages.push_back(m);
            if(m->getOwner() == secondUserPrimaryKey)
                this->notify();
            return true;
        }
    return false;
}

bool PrivateChat::changeMessage(std::shared_ptr<Message> &m, const std::string &newText) {
    auto it = std::find(messages.begin(),messages.end(), m);
    if(it != messages.end()){
        ModifiedMessage *mM = new ModifiedMessage(newText, (*it)->getOwner(), (*it)->isRead());
        std::shared_ptr<Message> m_ptr = std::make_shared<ModifiedMessage>(*mM);
        std::replace(messages.begin(), messages.end(), *it, m_ptr);
        return true;
    }
    return false;
}

bool PrivateChat::removeMessage(std::shared_ptr<Message> &m) {
    bool erase = false;
    auto it = std::find(messages.begin(),messages.end(), m);
    if(it != messages.end()){
        messages.erase(it);
        erase = true;
    }
    return erase;
}

void PrivateChat::readAllMessages() {
    std::cout<<std::endl<<"CHAT PRIVATA: "<<secondUserPrimaryKey<<std::endl;
    for(auto it: messages)
        it->readMessage();
    std::cout<<std::endl;
}

bool PrivateChat::readNewMessages(){
    bool newMes = false;
    for(auto it: messages) {
        if(!it->isRead()){
            if(!newMes) {
                std::cout<<std::endl <<"NUOVI MESSAGGI DALLA CHAT: "<<secondUserPrimaryKey<<std::endl;
                newMes = true;
            }
            it->readMessage();
        }
    }
    std::cout<<std::endl;
    return newMes;
}


