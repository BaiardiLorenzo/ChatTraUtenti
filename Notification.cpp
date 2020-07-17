//
// Created by Il Baia on 07/07/2020.
//

#include "Notification.h"

Notification::Notification(const std::shared_ptr<Chat> &subject, const bool enable)  : subject(subject), enable(enable){

}

Notification::~Notification() {
}

void Notification::attach() {
    std::shared_ptr<Observer> ptr = std::make_shared<Notification>(*this);
    subject->subscribe(ptr);
}

void Notification::detach(){
    std::shared_ptr<Observer> ptr = std::make_shared<Notification>(*this);
    subject->unsubscribe(ptr);
}

void Notification::update(){
    if(enable)
        this->send(subject->getLastMessage());
}

void Notification::send(const std::shared_ptr<Message> &m){
    std::cout<<"NOTIFICA da "<<m->getOwner()<<": "<<m->getText()<<" - alle "<<m->getTimeS()<<std::endl;
}




