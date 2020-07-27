//
// Created by Il Baia on 08/07/2020.
//

#include "GroupChat.h"

GroupChat::GroupChat(const std::string &nameChat, const std::string &description, const std::string &adminPrimaryKey, const std::set<std::string> &usersPrimaryKeys)
                            : Chat(nameChat), nameChat(nameChat), description(description), adminPrimaryKey(adminPrimaryKey), usersPrimaryKeys(usersPrimaryKeys){
}

GroupChat::~GroupChat() {

}

void GroupChat::addMessage(const std::shared_ptr<Message> &m) {
    auto it = usersPrimaryKeys.find(m->getOwner());
    if(it != usersPrimaryKeys.end() || m->getOwner() == adminPrimaryKey){
        if(!m->getText().empty()) {
            messages.push_back(m);
            if (m->getOwner() != adminPrimaryKey)
                this->notify();
        }
    } else{
        std::string message = "Messaggio non aggiunto, "+m->getOwner()+" non fa parte di questa Chat";
        throw ChatException(getPrimaryKey(), message);
    }
}

void GroupChat::removeMessage(std::shared_ptr<Message> &m) {
    auto it = find(messages.begin(), messages.end(), m);
    if(it!=messages.end()){
        messages.erase(it);
        std::cout<<"Il messaggio selezionato è stato cancellato"<<std::endl;
    }else{
        std::string message = "Messaggio non è stato trovato, non è stato eliminato dalla Chat";
        throw ChatException(getPrimaryKey(), message);
    }
}

void GroupChat::readAllMessages() {
    std::cout<<std::endl<<"CHAT DI GRUPPO: "<<nameChat<<std::endl;
    for(auto &it: messages)
        it->readMessage();
    std::cout<<std::endl;
}

bool GroupChat::readNewMessages() {
    bool newMes = false;
    for(auto &it: messages) {
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


