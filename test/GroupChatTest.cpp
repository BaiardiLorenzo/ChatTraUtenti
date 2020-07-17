//
// Created by Il Baia on 14/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"

User sysMarco("Marco", 15,'m');
User alessia("Alessia", 18, 'f');
std::vector<std::string> usersPrimaryKeys;

TEST(GroupChat, getterAndSetter){
    usersPrimaryKeys.push_back(sysMarco.getPrimaryKey());
    usersPrimaryKeys.push_back(alessia.getPrimaryKey());
    GroupChat gc("Gruppo Normale","semplicemente un gruppo", sysMarco.getPrimaryKey(),usersPrimaryKeys);
    ASSERT_EQ(gc.getAdminPrimaryKey(), sysMarco.getPrimaryKey());
    ASSERT_EQ(gc.getNameChat(), "Gruppo Normale");
    ASSERT_EQ(gc.getUsersPrimaryKeys(), usersPrimaryKeys);
    gc.setDescription("che bel gruppo");
    ASSERT_EQ(gc.getDescription(), "che bel gruppo");
}

TEST(GroupChat, methods){
    usersPrimaryKeys.push_back(sysMarco.getPrimaryKey());
    usersPrimaryKeys.push_back(alessia.getPrimaryKey());
    GroupChat gc("Gruppo Normale","semplicemente un gruppo", sysMarco.getPrimaryKey(),usersPrimaryKeys);
    std::shared_ptr<Message> m_ptr = std::make_shared<Message>("Cosa si organizza allora?", sysMarco.getPrimaryKey());

    ASSERT_EQ(gc.getLastMessage(), m_ptr);
}