//
// Created by Il Baia on 13/07/2020.
//

#include "gtest/gtest.h"
#include "../Message.h"

TEST(Message, getterAndSetter){
    Message m("Ciao, come va?","Luca");
    ASSERT_EQ(m.getOwner(), "Luca");
    ASSERT_EQ(m.getText(), "Ciao, come va?");
    ASSERT_EQ(m.isRead(), false);

    m.setRead(true);
    ASSERT_EQ(m.isRead(), true);
}
