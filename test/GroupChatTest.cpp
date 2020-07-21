//
// Created by Il Baia on 14/07/2020.
//

#include "gtest/gtest.h"
#include "../User.h"

TEST(GroupChat, getterAndSetter){
    User stefano("Stefano", 26, 'm');
    User marco("Marco", 14, 'm');
    User lapo("Lapo", 42, 'm');
    GroupChat gc("Gruppo di Test", "per provare se funziona tutto", stefano.getPrimaryKey(), {marco.getPrimaryKey(), lapo.getPrimaryKey()});

    ASSERT_EQ(gc.getAdminPrimaryKey(), stefano.getPrimaryKey());
    ASSERT_EQ(gc.getNameChat(), "Gruppo di Test");
    ASSERT_EQ(gc.getDescription(), "per provare se funziona tutto");
    gc.setDescription("dovrebbe funzionare tutto");
    ASSERT_EQ(gc.getDescription(), "dovrebbe funzionare tutto");
}

TEST(GroupChat, methods){
    User stefano("Stefano", 26, 'm');
    User marco("Marco", 14, 'm');
    User lapo("Lapo", 42, 'm');
    User lorenzo("Lorenzo", 20,'m');
    GroupChat gc("Gruppo di Test", "per provare se funziona tutto", stefano.getPrimaryKey(), {marco.getPrimaryKey(), lapo.getPrimaryKey()});

    auto message = std::make_shared<Message>("Abbiamo controllato tutto?", stefano.getPrimaryKey());
    auto errorMessage = std::make_shared<Message>("Posso entrare nel gruppo?", lorenzo.getPrimaryKey());
    auto removedMessage = std::make_shared<Message>("Credo che qualcosa non funzioni...", lapo.getPrimaryKey());
    gc.addMessage(message);

    ASSERT_EQ(gc.getLastMessage(), message);
    ASSERT_EQ(gc.getNewMessages(), 1);
    ASSERT_TRUE(gc.readNewMessages());
    ASSERT_FALSE(gc.readNewMessages());
    ASSERT_THROW(gc.addMessage(errorMessage), ChatException);
    ASSERT_THROW(gc.removeMessage(removedMessage), ChatException);
    ASSERT_NO_THROW(gc.removeMessage(message));
}