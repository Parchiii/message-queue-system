#include "QueueManager.h"
#include "MessageQueue.h"
#include <iostream>
#include <ranges>

std::vector<std::string> QueueManager::list_queues() const{
    std::vector<std::string> lista_key = {};
    for(std::string key : QueueManager::Queues | std::views::keys){
        lista_key.push_back(key);
    }
    return lista_key;
}
bool QueueManager::create_queue(const std::string& name, size_t max_size){
    if(Queues.find(name) != Queues.end()){
        return false;
    }
    auto newQueue = Queues.try_emplace(name, std::make_unique<MessageQueue>(name, max_size) );

    return newQueue.second;
};
bool QueueManager::delete_queue(const std::string& name){
    auto queue = Queues.find(name);
    if(queue != Queues.end()){
        Queues.erase(queue);
        return true;
    }
    return false;
};
MessageQueue* QueueManager::get_queue(const std::string& name){
    auto queue = Queues.find(name);
    if (queue == Queues.end()){
        return nullptr;
    }
    return queue->second.get();
}

// Operaciones principales
bool QueueManager::publish(const std::string& queue_name, const std::string& message){
    auto queue = Queues.find(queue_name);
    if (queue == Queues.end()){
        std::cout << "cola no encontrada\n";
        return false;
    }
    queue->second->push(message);
    return true;
}
std::optional<Message> QueueManager::consume(const std::string& queue_name){
    auto queue = Queues.find(queue_name);
    if (queue == Queues.end()){
        std::cout <<"cola no encontrada";
        return std::nullopt;
    }
    return queue->second->pop();
}
