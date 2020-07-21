//
// Created by Il Baia on 13/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"

TEST(User, getterAndSetter){
    User stefano("Stefano", 26, 'm');
    ASSERT_EQ(stefano.getName(), "Stefano");
    ASSERT_EQ(stefano.getAge(), 26);
    ASSERT_EQ(stefano.getGender(), 'm');
    stefano.setName("Stefanino");
    ASSERT_EQ(stefano.getName(), "Stefanino");
}

TEST(User, methods){
    User stefano("Stefano", 26, 'm');
    User marco("Marco", 14, 'm');
    User lapo("Lapo", 42, 'm');
    User lorenzo("Lorenzo", 20, 'm');

    auto chat = stefano.createPrivateChat(marco);
    ASSERT_TRUE( chat != nullptr);
    ASSERT_NO_THROW(marco.findPrivateChat(stefano));
    ASSERT_NO_THROW(stefano.removeChat(chat));
    ASSERT_THROW(lapo.findPrivateChat(marco), ChatException);
    ASSERT_THROW(lapo.removeChat(chat), ChatException);

    auto groupChat = marco.createGroupChat("Chat Professori","gruppo dei professori",{&stefano,&lapo});
    ASSERT_TRUE(groupChat != nullptr);
    ASSERT_NO_THROW(marco.findGroupChat("Chat Professori"));
    ASSERT_NO_THROW(stefano.findGroupChat("Chat Professori"));
    ASSERT_NO_THROW(lapo.findGroupChat("Chat Professori"));
    ASSERT_THROW(lorenzo.findGroupChat("Chat Professori"), ChatException);
    ASSERT_NO_THROW(marco.removeChat(groupChat));
    ASSERT_NO_THROW(stefano.removeChat(groupChat));
    ASSERT_THROW(lorenzo.removeChat(groupChat),ChatException);
}
