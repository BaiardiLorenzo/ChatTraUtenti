//
// Created by Il Baia on 13/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"


TEST(PrivateChat, GetterAndSetter){
    User stefano("Stefano", 26, 'm');
    User marco("Marco", 18, 'm');
    PrivateChat pc(stefano.getPrimaryKey(), marco.getPrimaryKey());

    ASSERT_EQ(pc.getFirstUserPrimaryKey(), stefano.getPrimaryKey());
    ASSERT_EQ(pc.getSecondUserPrimaryKey(), marco.getPrimaryKey());
}

TEST(PrivateChat, Methods){
    User stefano("Stefano", 26, 'm');
    User marco("Marco", 18, 'm');
    User lapo("Lapo", 42, 'm');
    PrivateChat pc(stefano.getPrimaryKey(), marco.getPrimaryKey());

    auto message = std::make_shared<Message>("Allora cosa mi racconti?", stefano.getPrimaryKey());
    auto errorMessage = std::make_shared<Message>("Posso entrare nel gruppo?", lapo.getPrimaryKey());
    auto removedMessage = std::make_shared<Message>("Buonasera", stefano.getPrimaryKey());
    pc.addMessage(message);

    ASSERT_EQ(pc.getLastMessage(), message);
    ASSERT_EQ(pc.getNewMessages(), 1);
    ASSERT_TRUE(pc.readNewMessages());
    ASSERT_FALSE(pc.readNewMessages());
    ASSERT_THROW(pc.addMessage(errorMessage), ChatException);
    ASSERT_THROW(pc.removeMessage(removedMessage), ChatException);
    ASSERT_NO_THROW(pc.removeMessage(message));
}