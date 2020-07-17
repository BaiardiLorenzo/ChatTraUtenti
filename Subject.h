//
// Created by Il Baia on 07/07/2020.
//

#ifndef CHATTRAUTENTI_SUBJECT_H
#define CHATTRAUTENTI_SUBJECT_H


#include <memory>

class Subject {
public:
    virtual ~Subject(){}

    virtual void subscribe(std::shared_ptr<Observer> &observer) = 0;

    virtual void unsubscribe(std::shared_ptr<Observer> &observer) = 0;

    virtual void notify() = 0;
};


#endif //CHATTRAUTENTI_SUBJECT_H
