//
// Created by Il Baia on 03/07/2020.
//

#ifndef CHATTRAUTENTI_CHAT_H
#define CHATTRAUTENTI_CHAT_H


#include <deque>
#include <vector>
#include <list>
#include <iostream>
#include <memory>

#include "Message.h"
#include "Observer.h"
#include "Subject.h"
#include "ChatException.h"


class Chat : public Subject{
public:
    explicit Chat(const std::string &primaryKey) : primaryKey(primaryKey){};

    ~Chat() override {};

    virtual void addMessage(const std::shared_ptr<Message> &m) = 0;

    virtual void removeMessage(std::shared_ptr<Message> &m) = 0;

    virtual void readAllMessages() = 0;

    virtual bool readNewMessages() = 0;

    int getNewMessages() const{
        int i=0;
        for(auto &it : messages){
            if(!it->isRead())
                i++;
        }
        return i;
    }
    
    const std::shared_ptr<Message> &getLastMessage() const{
        messages.back();
    }

    void subscribe(std::shared_ptr<Observer> &ob) override {
        observers.push_back(ob);
    }

    void unsubscribe(std::shared_ptr<Observer> &ob) override {
        observers.remove(ob);
    }

    void notify() override {
        for (auto ob: observers)
            ob->update();
    }

    const std::string &getPrimaryKey() const {
        return primaryKey;
    }

    const std::deque<std::shared_ptr<Message>> &getMessages() const {
        return messages;
    }

    bool operator==(const Chat &right) const{
        return primaryKey == right.primaryKey;
    }

    bool operator!=(const Chat &right) const{
        return !(*this == right);
    }

protected:
    std::string primaryKey;

    std::list<std::shared_ptr<Observer>> observers;
    std::deque<std::shared_ptr<Message>> messages;
};

#endif //CHATTRAUTENTI_CHAT_H
