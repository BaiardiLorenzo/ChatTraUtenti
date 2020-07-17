cmake_minimum_required(VERSION 3.9)
project(ChatTraUtenti)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES User.cpp User.h Message.h Message.cpp Chat.h ModifiedMessage.cpp ModifiedMessage.h MultimediaMessage.cpp MultimediaMessage.h Subject.h Observer.h Notification.cpp Notification.h GroupChat.cpp GroupChat.h PrivateChat.cpp PrivateChat.h)
add_executable(ChatTraUtenti main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ChatTraUtenti core)
