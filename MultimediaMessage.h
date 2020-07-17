//
// Created by Il Baia on 03/07/2020.
//

#ifndef CHATTRAUTENTI_MULTIMEDIAMESSAGE_H
#define CHATTRAUTENTI_MULTIMEDIAMESSAGE_H

#include <iostream>

#include "Message.h"

class MultimediaMessage : public Message{
public:
    explicit MultimediaMessage(const std::string &text, const std::string &owner, const std::string &linkMedia, const bool read = false);

    void readMessage() override;

protected:
    std::string linkMedia;
};


#endif //CHATTRAUTENTI_MULTIMEDIAMESSAGE_H
