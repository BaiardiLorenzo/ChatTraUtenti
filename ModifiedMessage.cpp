//
// Created by Il Baia on 03/07/2020.
//

#include "ModifiedMessage.h"

ModifiedMessage::ModifiedMessage(const std::string &newText, const std::string &ownerPrimaryKey, const bool read) : Message(newText, ownerPrimaryKey, read) {
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    modified_timeS = std::to_string(localTime->tm_hour)+"."+std::to_string(localTime->tm_min);
}

void ModifiedMessage::readMessage() {
    std::cout<<ownerPrimaryKey<<": "<<text<<"- modificato alle "<<modified_timeS<<std::endl;
}
