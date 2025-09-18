/*
** EPITECH PROJECT, 2024
** Process (header)
** File description:
** Plazza
*/

#include <iostream>
#include <unistd.h>
#include <signal.h>

class Process {
    private:
      pid_t _pid;

    public:
        Process();
        ~Process();
        pid_t getPid() const;
    
    class ProcessException : public std::exception {
    private:
        std::string _message;
    public:
    ProcessException() : _message("") {}
    ProcessException(const std::string& msg) : _message(msg) {}
    virtual const char* what() const throw() {
        return _message.c_str();
    }
    };
};