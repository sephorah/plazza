/*
** EPITECH PROJECT, 2024
** ParseInput (header)
** File description:
** Plazza
*/

#ifndef PARSEINPUT_HPP_
#define PARSEINPUT_HPP_
#define SUCCESS 0
#define ERROR 84

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include "Parsing/ParsingExceptions.hpp"
#include "Pizza/APizza.hpp"
#include "Kitchen/Fridge.hpp"
#include "Pizza/PizzaFactory.hpp"

namespace Parsing {
    class ParseInput {
        private:
            std::string _input;
            const std::vector<std::string> _validPizzas = {"regina", "margarita", "americana", "fantasia",
            "monza"};
            const std::vector<std::string> _validSizes = {"s", "m", "l", "xl", "xxl"};
            Pizza::PizzaFactory _factory;

        public:
            ParseInput() = default;
            ParseInput(std::string& input);
            ~ParseInput() = default;
            void setInput(const std::string& input);
            std::string& getInput(void);
            std::vector<std::shared_ptr<Pizza::IPizza>> getCommand(double multiplier);
            std::string myStrLower(const std::string& str);
            std::vector<std::string> splitString(std::string s, std::string delimiter);
            bool isValidOrder(std::vector<std::string> inputWords);
            // pizza_t& getPizzaInfos(std::string &inputPizza, pizza_t& pizza);
            // PizzaSize getPizzaSize(std::string &inputSize);
    };
}

#endif /* !PARSEINPUT_HPP_ */