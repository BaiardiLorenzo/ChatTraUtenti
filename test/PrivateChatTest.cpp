//
// Created by Il Baia on 13/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"


TEST(PrivateChat, GetterAndSetter){
    User sysLuigi("Luigi", 15,'m');
    User paola("Paola", 18, 'f');
    PrivateChat pc(sysLuigi.getPrimaryKey(), paola.getPrimaryKey());

    ASSERT_EQ(pc.getFirstUserPrimaryKey(), sysLuigi.getPrimaryKey());
    ASSERT_EQ(pc.getSecondUserPrimaryKey(), paola.getPrimaryKey());
}

TEST(PrivateChat, Methods){
    User sysLuigi("Luigi", 15,'m');
    User paola("Paola", 18, 'f');
    PrivateChat pc(sysLuigi.getPrimaryKey(), paola.getPrimaryKey());
    std::shared_ptr<Message> message = std::make_shared<Message>("Allora cosa mi racconti?", sysLuigi.getPrimaryKey());
    pc.addMessage(message);

    ASSERT_EQ(pc.getLastMessage(), message);

    User giacomo("Giacomo", 27,'m');
    std::shared_ptr<Message> errorMessage = std::make_shared<Message>("Posso entrare nel gruppo?", giacomo.getPrimaryKey());
    ASSERT_THROW(pc.addMessage(errorMessage), ChatException);

    auto removedMessage = std::make_shared<Message>("Buonasera", sysLuigi.getPrimaryKey());

    ASSERT_THROW(pc.removeMessage(removedMessage), ChatException);

    ASSERT_NO_THROW(pc.removeMessage(message));
}