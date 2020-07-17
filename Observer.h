//
// Created by Il Baia on 07/07/2020.
//

#ifndef CHATTRAUTENTI_OBSERVER_H
#define CHATTRAUTENTI_OBSERVER_H


class Observer {
public:
    virtual ~Observer(){}

    virtual void attach() = 0;

    virtual void detach() = 0;

    virtual void update() = 0;

};


#endif //CHATTRAUTENTI_OBSERVER_H
