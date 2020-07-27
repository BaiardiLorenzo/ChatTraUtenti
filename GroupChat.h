//
// Created by Il Baia on 08/07/2020.
//

#ifndef CHATTRAUTENTI_GROUPCHAT_H
#define CHATTRAUTENTI_GROUPCHAT_H

#include <algorithm>
#include <set>

#include "Chat.h"

class GroupChat : public Chat{
public:
    GroupChat(const std::string &name, const std::string &description, const std::string &primaryKey, const std::set<std::string> &primaryKeysUsers);

    ~GroupChat() override;

    void addMessage(const std::shared_ptr<Message> &m) override;

    void removeMessage(std::shared_ptr<Message> &m) override;

    void readAllMessages() override;

    bool readNewMessages() override;

    const std::string &getNameChat() const {
        return nameChat;
    }

    void setNameChat(const std::string &nameChat) {
        GroupChat::nameChat = nameChat;
    }

    const std::string &getAdminPrimaryKey() const {
        return adminPrimaryKey;
    }

    void setAdminPrimaryKey(const std::string &adminPrimaryKey) {
        GroupChat::adminPrimaryKey = adminPrimaryKey;
    }

    const std::set<std::string> &getUsersPrimaryKeys() const {
        return usersPrimaryKeys;
    }

    void setUsersPrimaryKeys(const std::set<std::string> &usersPrimaryKeys) {
        GroupChat::usersPrimaryKeys = usersPrimaryKeys;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        GroupChat::description = description;
    }

private:
    std::string nameChat;
    std::string description;
    std::string adminPrimaryKey;

    std::set<std::string> usersPrimaryKeys;
};


#endif //CHATTRAUTENTI_GROUPCHAT_H
