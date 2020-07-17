//
// Created by Il Baia on 03/07/2020.
//

#include "MultimediaMessage.h"

MultimediaMessage::MultimediaMessage(const std::string &text, const std::string &ownerPrimaryKey, const std::string &linkMedia, const bool read) : Message(text, ownerPrimaryKey, read), linkMedia(linkMedia){

}

void MultimediaMessage::readMessage() {
    std::cout<<ownerPrimaryKey<<": Media-"<<linkMedia<<" :: "<<text<<" -Ore "<<timeS<<std::endl;
}


