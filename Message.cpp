//
// Created by Il Baia on 10/07/2020.
//

#include "Message.h"

Message::Message(const std::string &text, const std::string &ownerPrimaryKey, const bool read) : text(text), ownerPrimaryKey(ownerPrimaryKey), read(read){
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime= localtime(&currentTime);
    timeS = std::to_string(localTime->tm_hour)+"."+std::to_string(localTime->tm_min);
}

Message::~Message() {

}

void Message::readMessage(){
    std::cout<<ownerPrimaryKey<<": "<<text<<" -Ore "<<timeS<<std::endl;
    if(!isRead())
        setRead(true);
}




