#include <string>
#include "Message.h"


Message::Message(const std::string& queue, const std::string& content) : queue_name(queue), body(content) {
        static uint64_t counter = 0;
        id = ++counter;
        created_at = std::chrono::system_clock::now();
    }
