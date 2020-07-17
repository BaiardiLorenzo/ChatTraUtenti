cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp PrivateChatTest.cpp UserTest.cpp MessageTest.cpp GroupChatTest.cpp NotificationTest.cpp)
add_executable(runChatTests ${TEST_SOURCE_FILES} runAllTests.cpp)
target_link_libraries(runChatTests gtest gtest_main core)