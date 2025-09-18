/*
** EPITECH PROJECT, 2024
** MessageQueue (header)
** File description:
** Plazza
*/

#ifndef MESSAGEQUEUE_HPP_
#define MESSAGEQUEUE_HPP_
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include "Parsing/ParseInput.hpp"
#include "Parsing/ParseArgs.hpp"
#define SUCCESS 0
#define ERROR 84

typedef struct msg_s {
    long msgType; 
    char msgText[1024]; 
} msg_t;

class MessageQueue {
    private:
        int _msgid;
    public:
        msg_t _message;
        MessageQueue();
        ~MessageQueue();
        int sendMsg();
        int receiveMsg();
    
    class QueueException : public std::exception {
    private:
        std::string _message;
    public:
    QueueException() : _message("") {}
    QueueException(const std::string& msg) : _message(msg) {}
    virtual const char* what() const throw() {
        return _message.c_str();
    }
    };
};

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Pizza::IPizza> pizza);

#endif /* !MESSAGEQUEUE_HPP_ */