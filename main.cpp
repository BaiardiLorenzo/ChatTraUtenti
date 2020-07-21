#include "User.h"
#include "MultimediaMessage.h"
#include "Notification.h"

int main() {

    //USERS
    User marco("Marco", 24, 'm');
    User alessia("Alessia", 19, 'f');
    User filippo("Filippo", 26, 'm');

    //----------CHAT PRIVATA------------------------------
    auto chatMarcoAlessia = marco.createPrivateChat(alessia);
    auto chatAlessiaMarco = alessia.findPrivateChat(marco);

    auto foo = std::make_shared<Message>("Ciao Francesca, come va?", "Marco", true);
    auto bar = std::make_shared<Message>("Tutto bene, te?", "Alessia");
    auto fooBar = std::make_shared<Message>("Anch'io tutto bene", "Marco", true);

    Notification messageNotifier(chatMarcoAlessia, true);
    messageNotifier.attach();
    try {
        chatMarcoAlessia->addMessage(foo);
        chatAlessiaMarco->addMessage(bar);
        chatAlessiaMarco->addMessage(fooBar);
    } catch (ChatException &e) {
        e.printError();
    }
    chatMarcoAlessia->readNewMessages();
    chatAlessiaMarco->readAllMessages();
    chatMarcoAlessia->readNewMessages();
    chatMarcoAlessia->readAllMessages();
    try{
        marco.removeChat(chatMarcoAlessia);
    }catch(ChatException &e){
        e.printError();
    }

    //----------CHAT DI GRUPPO------------------------------
    auto groupChat = marco.createGroupChat("Gruppo Studio", "gruppo per studiare", {&});
    auto fooG = std::make_shared<Message>("Quando si studia allora", "Alessia");
    auto barG = std::make_shared<Message>("Decidete voi", "Filippo");
    auto fooBarG = std::make_shared<Message>("Per me si puo fare domani", "Marco", true);
    auto mediaG = std::make_shared<MultimediaMessage>("Ecco il link della video Lezione", filippo.getPrimaryKey(), "www.google.com");

    Notification messageNotifierG(groupChat, true);
    messageNotifierG.attach();
    try {
        groupChat->addMessage(fooG);
        groupChat->addMessage(barG);
        groupChat->addMessage(fooBarG);
        groupChat->addMessage(mediaG);
    } catch (ChatException &e) {
        e.printError();
    }
    groupChat->readNewMessages();
}
