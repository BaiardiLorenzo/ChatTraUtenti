//
// Created by Il Baia on 20/07/2020.
//

#include "ChatException.h"

ChatException::ChatException(const string &chatPrimaryKey, const string &message) : runtime_error(message.c_str()), chatPrimaryKey(chatPrimaryKey) {

}

void ChatException::printError() {
    cerr<<"Si è verificato un errore nella chat "<<chatPrimaryKey<<" "<<endl;
}