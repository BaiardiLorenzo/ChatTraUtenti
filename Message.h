//
// Created by Il Baia on 03/07/2020.
//

#ifndef CHATTRAUTENTI_MESSAGE_H
#define CHATTRAUTENTI_MESSAGE_H


#include <string>
#include <ctime>
#include <iostream>

class Message {
public:
    explicit Message(const std::string &text, const std::string &ownerPrimaryKey, const bool read = false);

    ~Message();

    virtual void readMessage();

    const std::string &getText() const {
        return text;
    }

    const std::string &getTimeS() const {
        return timeS;
    }

    bool isRead() const {
        return read;
    }

    void setRead(bool read) {
        Message::read = read;
    }

    const std::string &getOwner() const {
        return ownerPrimaryKey;
    }

    bool operator==(const Message &right) const{
        return ownerPrimaryKey == right.ownerPrimaryKey && timeS == right.timeS && text == right.text;
    }

    bool operator!=(const Message &right) const{
        return !(*this == right);
    }

protected:
    std::string ownerPrimaryKey;
    std::string text;
    std::string timeS;
    bool read;
};


#endif //CHATTRAUTENTI_MESSAGE_H
