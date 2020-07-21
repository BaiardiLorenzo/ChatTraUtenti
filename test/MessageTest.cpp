//
// Created by Il Baia on 13/07/2020.
//

#include "gtest/gtest.h"
#include "../Message.h"

TEST(Message, getterAndSetter){
    Message m("Ciao, come va?","Marco");
    ASSERT_EQ(m.getOwner(), "Marco");
    ASSERT_EQ(m.getText(), "Ciao, come va?");
    ASSERT_EQ(m.isRead(), false);
    m.readMessage();
    ASSERT_EQ(m.isRead(), true);
}
