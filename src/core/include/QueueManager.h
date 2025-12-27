#pragma once

#include "MessageQueue.h"
#include <map>
#include <memory>


class QueueManager{

private:
    std::map<std::string, std::unique_ptr<MessageQueue>> Queues={};

public:
    std::vector<std::string> list_queues() const;
    bool create_queue(const std::string& name, size_t max_size = 10000);
    bool delete_queue(const std::string& name);
    MessageQueue* get_queue(const std::string& name);

    // Operaciones principales
    bool publish(const std::string& queue_name, const std::string& message);
    std::optional<Message> consume(const std::string& queue_name);
};
