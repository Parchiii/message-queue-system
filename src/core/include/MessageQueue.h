#pragma once

#include "Message.h"
#include <string>
#include <optional>
#include <queue>

class MessageQueue {

private:
    const std::string queue_name;
    std::queue<Message> messages;
    size_t max_size;
public:

    MessageQueue (const std::string& name_input, size_t max_size_input = 1000);


    //agrega algo al final de la cola
    bool push(const std::string& new_msg);
    //saca al primero de la cola
    std::optional<Message> pop(int timeout_ms = 1000);

    //getters
    std::string getName() const;
    size_t getSize() const;
    bool checkEmpty() const;
};
