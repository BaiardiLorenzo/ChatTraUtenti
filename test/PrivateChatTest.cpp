//
// Created by Il Baia on 13/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"

User sysMarco("Marco", 15,'m');
User alessia("Alessia", 18, 'f');

TEST(PrivateChat, GetterAndSetter){
    PrivateChat pc(sysMarco.getPrimaryKey(), alessia.getPrimaryKey());
    ASSERT_EQ(pc.getFirstUserPrimaryKey(), sysMarco.getPrimaryKey());
    ASSERT_EQ(pc.getSecondUserPrimaryKey(), alessia.getPrimaryKey());
}

TEST(PrivateChat, Methods){
    PrivateChat pc(sysMarco.getPrimaryKey(), alessia.getPrimaryKey());
    std::shared_ptr<Message> m_ptr = std::make_shared<Message>("Allora cosa mi racconti?", sysMarco.getPrimaryKey());
    pc.addMessage(m_ptr);
    ASSERT_EQ(pc.getLastMessage(), m_ptr);
}