//
// Created by Il Baia on 14/07/2020.
//

#include "gtest/gtest.h"
#include "../Notification.h"
#include "../User.h"

User sysMarco("Marco", 15,'m');
User alessia("Alessia", 18, 'f');

TEST(Notification, enableNotification){
    std::shared_ptr<Chat> chat_ptr = std::make_shared<PrivateChat>(sysMarco.getPrimaryKey(), alessia.getPrimaryKey());
    Notification notification(chat_ptr, true);
    ASSERT_TRUE(notification.isEnable());
    notification.setEnable(false);
    ASSERT_FALSE(notification.isEnable());
}
