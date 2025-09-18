/*
** EPITECH PROJECT, 2024
** ParseArgs
** File description:
** Plazza
*/

#include <fstream>
#include <cstring>
#include "Parsing/ParseArgs.hpp"
#include "Parsing/ParsingExceptions.hpp"

int Parsing::ParseArgs::dislayHelp(void)
{
    std::cout << "USAGE: ./plazza c n t" << std::endl;
    std::cout << "\tc\tmultiplier for the cooking time of the pizzas" << std::endl;
    std::cout << "\tn\tnumber of cooks per kitchen" << std::endl;
    std::cout << "\tt\ttime in milliseconds, used by the kitchen stock to replace ingredients" << std::endl;
    return (ERROR);
}

args_t Parsing::ParseArgs::checkArgs(int argc, const char *argv[])
{
    args_t args;

    if (argc != 4 || std::strcmp(argv[1], "-h") == 0 || std::strcmp(argv[1], "--help") == 0)
        throw Parsing::ParsingException();
    try {
        if (!std::atof(argv[1]) || !std::atof(argv[2]) || !std::atof(argv[3]))
            throw Parsing::ParsingException("one of the given arguments is incorrect, try again.");
        args.cookingTimeMultiplier = std::atof(argv[1]);
        args.cooksNumber = std::atoi(argv[2]);
        args.restockTime = std::atof(argv[3]);
    } catch (const Parsing::ParsingException& error) {
        std::cout << "Parsing::ParsingException:  " << error.what() << std::endl;
        throw Parsing::ParsingException();
    }
    return (args);
}

