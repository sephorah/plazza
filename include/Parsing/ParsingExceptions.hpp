/*
** EPITECH PROJECT, 2024
** ParsingExceptions (header)
** File description:
** Plazza
*/

#ifndef PARSINGEXCEPTIONS_HPP_
#define PARSINGEXCEPTIONS_HPP_
#include <iostream>

namespace Parsing {
    class ParsingException : public std::exception {
        private:
        std::string _message;
        
        public:
        ParsingException();
        ParsingException(const std::string& msg);
        virtual const char* what() const throw();
    };
};

#endif /* !PARSINGEXCEPTIONS_HPP_ */
