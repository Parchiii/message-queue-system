#include <iostream>
#include <string>
#include <queue>
#include "MessageQueue.h"

MessageQueue::MessageQueue (const std::string& name_input, size_t max_size_input) : queue_name(name_input), max_size(max_size_input){}

bool MessageQueue::push(const std::string& new_msg){
        try {
        // Verificar límite de tamaño primero
        if (messages.size() >= max_size) {
            throw std::runtime_error("Queue is full");
        }

        // Intentar crear el mensaje
        messages.push(Message(queue_name, new_msg));
        return true;

    } catch (const std::runtime_error& e) {
        // Error específico de lógica (cola llena)
        std::cerr << "Push failed (logic): " << e.what() << std::endl;
        return false;

    } catch (const std::bad_alloc& e) {
        // Error de memoria (muy raro con strings)
        std::cerr << "Push failed (memory): " << e.what() << std::endl;
        return false;

    } catch (const std::exception& e) {
        // Cualquier otro error estándar
        std::cerr << "Push failed (generic): " << e.what() << std::endl;
        return false;

    } catch (...) {
        // Error no estándar (muy raro)
        std::cerr << "Push failed (unknown error)" << std::endl;
        return false;
    }
    };
std::optional<Message> MessageQueue::pop(int timeout_ms){
    Message& front = messages.front();
    messages.pop();
    return front;
}
std::string MessageQueue::getName() const{return queue_name;};
size_t MessageQueue::getSize() const{return messages.size();};
bool MessageQueue::checkEmpty() const{return messages.empty();};
