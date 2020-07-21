//
// Created by Il Baia on 14/07/2020.
//

#include "gtest/gtest.h"
#include "../Notification.h"
#include "../User.h"


TEST(Notification, enableNotification){
    User sysMarco("Marco", 15,'m');
    User chiara("Alessia", 18, 'f');
    std::shared_ptr<Chat> chat = std::make_shared<PrivateChat>(sysMarco.getPrimaryKey(), chiara.getPrimaryKey());
    Notification notification(chat, true);

    ASSERT_TRUE(notification.isEnable());
    notification.setEnable(false);
    ASSERT_FALSE(notification.isEnable());
}
