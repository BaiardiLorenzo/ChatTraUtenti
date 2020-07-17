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
