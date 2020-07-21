//
// Created by Il Baia on 20/07/2020.
//

#ifndef CHATTRAUTENTI_CHATEXCEPTION_H
#define CHATTRAUTENTI_CHATEXCEPTION_H

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class ChatException : public runtime_error{
public:
    ChatException(const string &chatPrimaryKey, const string &message);

    void printError();

    const string &getChatPrimaryKey() const {
        return chatPrimaryKey;
    }

private:
    string chatPrimaryKey;
};


#endif //CHATTRAUTENTI_CHATEXCEPTION_H
