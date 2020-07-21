//
// Created by Il Baia on 08/07/2020.
//

#ifndef CHATTRAUTENTI_PRIVATECHAT_H
#define CHATTRAUTENTI_PRIVATECHAT_H

#include <iostream>
#include <algorithm>

#include "Chat.h"
#include "ModifiedMessage.h"

class PrivateChat : public Chat{
public:
    PrivateChat(const std::string &me, const std::string &otherUser);

    ~PrivateChat() override;

    void addMessage(const std::shared_ptr<Message> &m) override;

    void removeMessage(std::shared_ptr<Message>& m) override;

    void readAllMessages() override;

    bool readNewMessages() override;

    const std::string &getFirstUserPrimaryKey() const {
        return firstUserPrimaryKey;
    }

    const std::string &getSecondUserPrimaryKey() const {
        return secondUserPrimaryKey;
    }

private:
    std::string firstUserPrimaryKey;
    std::string secondUserPrimaryKey;
};


#endif //CHATTRAUTENTI_PRIVATECHAT_H
