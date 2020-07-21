//
// Created by Il Baia on 14/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"

TEST(GroupChat, getterAndSetter){
    User sysThomas("Thomas", 15, 'm');
    User alessia("Alessia", 18, 'f');
    std::vector<std::string> usersPrimaryKeys;
    usersPrimaryKeys.push_back(sysThomas.getPrimaryKey());
    usersPrimaryKeys.push_back(alessia.getPrimaryKey());
    GroupChat gc("Gruppo Normale", "semplicemente un gruppo", sysThomas.getPrimaryKey(), usersPrimaryKeys);

    ASSERT_EQ(gc.getAdminPrimaryKey(), sysThomas.getPrimaryKey());
    ASSERT_EQ(gc.getNameChat(), "Gruppo Normale");
    ASSERT_EQ(gc.getUsersPrimaryKeys(), usersPrimaryKeys);

    gc.setDescription("che bel gruppo");
    ASSERT_EQ(gc.getDescription(), "che bel gruppo");
}

TEST(GroupChat, methods){
    User sysThomas("Thomas", 15, 'm');
    User alessia("Alessia", 18, 'f');
    std::vector<std::string> usersPrimaryKeys;
    usersPrimaryKeys.push_back(sysThomas.getPrimaryKey());
    usersPrimaryKeys.push_back(alessia.getPrimaryKey());
    GroupChat gc("Gruppo Normale","semplicemente un gruppo", sysThomas.getPrimaryKey(),usersPrimaryKeys);
    std::shared_ptr<Message> message = std::make_shared<Message>("Cosa si organizza allora?", sysThomas.getPrimaryKey());

    gc.addMessage(message);
    ASSERT_EQ(gc.getLastMessage(), message);

    User esclusa("Fabiana", 37,'f');
    std::shared_ptr<Message> errorMessage = std::make_shared<Message>("Posso entrare nel gruppo?", esclusa.getPrimaryKey());
    ASSERT_THROW(gc.addMessage(errorMessage), ChatException);

    auto changedMessagge = std::make_shared<Message>("Salve ragazzi", sysThomas.getPrimaryKey());

    ASSERT_THROW(gc.removeMessage(changedMessagge), ChatException);

    ASSERT_NO_THROW(gc.removeMessage(message));
}