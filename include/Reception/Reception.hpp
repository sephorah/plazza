/*
** EPITECH PROJECT, 2024
** Core (header)
** File description:
** Plazza
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include "Process/Process.hpp"
#include "Kitchen/Kitchen.hpp"
#include "Parsing/ParseArgs.hpp"
#include "Parsing/ParseInput.hpp"
#include "MessageQueue/MessageQueue.hpp"

class Reception {
    public:
    Reception() = default;
    ~Reception() = default;
    int handleReception(args_t& args);

    class ReceptionException : public std::exception {
    private:
        std::string _message;
    public:
    ReceptionException() : _message("") {}
    ReceptionException(const std::string& msg) : _message(msg) {}
    virtual const char* what() const throw() {
        return _message.c_str();
    }
    };
};

#endif /* !RECEPTION_HPP_ */