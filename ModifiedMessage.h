//
// Created by Il Baia on 03/07/2020.
//

#ifndef CHATTRAUTENTI_MODIFIEDMESSAGE_H
#define CHATTRAUTENTI_MODIFIEDMESSAGE_H

#include <iostream>
#include <chrono>

#include "Message.h"

class ModifiedMessage : public Message{
public:
    explicit ModifiedMessage(const std::string &newText, const std::string &ownerPrimaryKey, const bool read = false);

    void readMessage() override;

private:
    std::string modified_timeS;
};


#endif //CHATTRAUTENTI_MODIFIEDMESSAGE_H
