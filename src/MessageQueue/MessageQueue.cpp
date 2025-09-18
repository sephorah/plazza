/*
** EPITECH PROJECT, 2024
** MessageQueue
** File description:
** Plazza
*/

#include "MessageQueue/MessageQueue.hpp"

MessageQueue::MessageQueue() 
{
    key_t key;
    key = ftok("./files/msgfile", 65);
    if (key == -1)
        throw QueueException("MessageQueue error: failed to generate key.");

    _msgid = msgget(key, 0666 | IPC_CREAT);
    if (_msgid == -1)
        throw QueueException("MessageQueue error: msgget() failure.");
}

MessageQueue::~MessageQueue()
{
    msgctl(_msgid, IPC_RMID, NULL); 
}

int MessageQueue::sendMsg()
{
    if (msgsnd(_msgid, &_message, sizeof(_message), 0) == -1)
        throw QueueException("MessageQueue error: msgsnd() failure.");
    return SUCCESS;
}

int MessageQueue::receiveMsg()
{
    if (msgrcv(_msgid, &_message, sizeof(_message), 1, 0) == -1)
        throw QueueException("MessageQueue error: receiveMsg() failure.");
    return SUCCESS;
}


std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Pizza::IPizza> pizza)
{
    // std::string pizzaTypeStr;
    // std::string pizzaSizeStr;
    std::unordered_map<PizzaSize, std::string> sizes = {
        {PizzaSize::S, "S"}, {PizzaSize::M, "M"}, {PizzaSize::L, "L"},
        {PizzaSize::XL, "XL"}, {PizzaSize::XXL, "XXL"},
    };
    std::unordered_map<PizzaType, std::string> types = {
        {PizzaType::Regina, "Regina"}, {PizzaType::Margarita, "Margarita"},
        {PizzaType::Americana, "Americana"}, {PizzaType::Fantasia, "Fantasia"},
        {PizzaType::Monza, "Monza"}
    };
    
    os << types[pizza->getType()] << " "
       << sizes[pizza->getSize()]; 
    return (os);
}
