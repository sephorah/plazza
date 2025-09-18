/*
** EPITECH PROJECT, 2024
** ParseArgs (header)
** File description:
** Plazza
*/

#ifndef PARSEARGS_HPP_
#define PARSEARGS_HPP_
#define SUCCESS 0
#define ERROR 84

struct args_t {
    double cookingTimeMultiplier;
    unsigned int cooksNumber;
    double restockTime;
};

namespace Parsing {
    class ParseArgs {
        public:
        ParseArgs() = default;
        ~ParseArgs() = default;
        args_t checkArgs(int argc, const char *argv[]);
        int dislayHelp(void);
    };
}

#endif /* !PARSEARGS_HPP_ */
