#pragma once

#include <string>
#include <chrono>

struct Message {
    uint64_t id;
    std::string queue_name;
    std::string body;
    std::chrono::system_clock::time_point created_at;

    // Constructor simple
    Message();
    Message (const std::string& queue, const std::string& content);
};
