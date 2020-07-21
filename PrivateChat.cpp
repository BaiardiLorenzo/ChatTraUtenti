//
// Created by Il Baia on 08/07/2020.
//
#include "PrivateChat.h"

PrivateChat::PrivateChat(const std::string &me, const std::string &otherUser): Chat(me+"-"+otherUser), firstUserPrimaryKey(me), secondUserPrimaryKey(otherUser){
}

PrivateChat::~PrivateChat() {

}

void PrivateChat::addMessage(const std::shared_ptr<Message> &m) {
    if(m->getOwner() == firstUserPrimaryKey || m->getOwner() == secondUserPrimaryKey){
        if(!m->getText().empty()){
            messages.push_back(m);
            if(m->getOwner() == secondUserPrimaryKey)
                this->notify();
        }
    } else {
        std::string message = "Messaggio non aggiunto, "+m->getOwner()+" non fa parte di questa Chat";
        throw ChatException(getPrimaryKey(), message);
    }
}

void PrivateChat::removeMessage(std::shared_ptr<Message> &m) {
    auto it = std::find(messages.begin(),messages.end(), m);
    if(it != messages.end()){
        messages.erase(it);
        std::cout<<"Il messaggio selezionato è stato cancellato"<<std::endl;
    }else{
        std::string message = "Messaggio non è stato trovato, non è stato eliminato dalla Chat";
        throw ChatException(getPrimaryKey(), message);
    }
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


