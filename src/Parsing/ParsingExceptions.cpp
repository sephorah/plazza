/*
** EPITECH PROJECT, 2024
** ParsingExceptions
** File description:
** Plazza
*/

#include "Parsing/ParsingExceptions.hpp"

Parsing::ParsingException::ParsingException() : _message("") {}

Parsing::ParsingException::ParsingException(const std::string& msg) : _message(msg) {}

const char *Parsing::ParsingException::what() const throw() 
{
    return (_message.c_str());
}
