//
// Created by Il Baia on 07/07/2020.
//

#ifndef CHATTRAUTENTI_NOTIFICATION_H
#define CHATTRAUTENTI_NOTIFICATION_H

#include <memory>

#include "Observer.h"
#include "Chat.h"

class Notification : public Observer{
public:
    explicit Notification(const std::shared_ptr<Chat> &subject, const bool enable);

    ~Notification() override;

    void attach() override;

    void detach() override;

    void update() override;

    void send(const std::shared_ptr<Message> &m);

    bool isEnable() const {
        return enable;
    }

    void setEnable(bool activated) {
        Notification::enable = activated;
    }

private:
    bool enable;
    std::shared_ptr<Chat> subject;
};


#endif //CHATTRAUTENTI_NOTIFICATION_H
