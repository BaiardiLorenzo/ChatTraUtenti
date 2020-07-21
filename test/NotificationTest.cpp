//
// Created by Il Baia on 14/07/2020.
//

#include "gtest/gtest.h"
#include "../Notification.h"
#include "../User.h"


TEST(Notification, enableNotification){
    User marco("Marco", 27,'m');
    User lorenzo("Lorenzo", 20, 'm');
    auto chat = marco.createPrivateChat(lorenzo);
    auto message = std::make_shared<Message>("Prova della notifica", lorenzo.getPrimaryKey());
    Notification notification(chat, true);
    ASSERT_TRUE(notification.isEnable());
    notification.attach();
    chat->addMessage(message);

}
