#include "User.h"
#include "MultimediaMessage.h"
#include "Notification.h"

int main() {

    User systemUser("Marco",14,'m');
    User otherUser("Alessia",12,'f');

    //----------CHAT PRIVATA------------------------------

    std::shared_ptr<Chat> systemChatptr = systemUser.createPrivateChat(otherUser);
    std::shared_ptr<Chat> userChatptr = otherUser.findPrivateChat(systemUser);

    std::shared_ptr<Message> foo = std::make_shared<Message>("Ciao Francesca, come va?", "Marco", true);
    std::shared_ptr<Message> bar = std::make_shared<Message>("Tutto bene, te?", "Alessia");
    std::shared_ptr<Message> fooBar = std::make_shared<Message>("Anch'io tutto bene", "Marco", true);

    Notification messageNotifier(systemChatptr, true);

    messageNotifier.attach();

    try {
        systemChatptr->addMessage(foo);
        userChatptr->addMessage(bar);
        userChatptr->addMessage(fooBar);
    } catch (ChatException &e) {
        e.printError();
    }

    systemChatptr->readNewMessages();
    userChatptr->readAllMessages();

    systemChatptr->readNewMessages();

    systemChatptr->readAllMessages();

    systemUser.removeChat(systemChatptr);

    //----------CHAT DI GRUPPO------------------------------
    User thirdUser("Filippo", 26, 'm');

    std::vector<User*> utenti_del_gruppo;
    utenti_del_gruppo.push_back(&systemUser);
    utenti_del_gruppo.push_back(&otherUser);
    utenti_del_gruppo.push_back(&thirdUser);
    std::shared_ptr<Chat> gruppoStudio = systemUser.createGroupChat("Gruppo Studio","gruppo per studiare", utenti_del_gruppo);

    std::shared_ptr<Message> fooG = std::make_shared<Message>("Quando si studia allora", "Alessia");
    std::shared_ptr<Message> barG = std::make_shared<Message>("Decidete voi", "Filippo");
    std::shared_ptr<Message> fooBarG = std::make_shared<Message>("Per me si puo fare domani", "Marco", true);
    std::shared_ptr<Message> mediaG = std::make_shared<MultimediaMessage>("Ecco il link della video Lezione", thirdUser.getPrimaryKey(), "www.google.com");

    Notification messageNotifierG(gruppoStudio, true);

    messageNotifierG.attach();

    try {
        gruppoStudio->addMessage(fooG);
        gruppoStudio->addMessage(barG);
        gruppoStudio->addMessage(fooBarG);
        gruppoStudio->addMessage(mediaG);
    } catch (ChatException &e) {
        e.printError();
    }

    gruppoStudio->readNewMessages();
}
