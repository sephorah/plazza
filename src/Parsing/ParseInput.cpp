/*
** EPITECH PROJECT, 2024
** ParseInput
** File description:
** Plazza
*/

#include "Parsing/ParseInput.hpp"

Parsing::ParseInput::ParseInput(std::string& input) : _input(input) {}

void Parsing::ParseInput::setInput(const std::string& input)
{
    _input = input;
}

std::string& Parsing::ParseInput::getInput(void)
{
    return (_input);
}

std::string Parsing::ParseInput::myStrLower(const std::string& str)
{
    std::string result;

    for (char ch : str)
        result += tolower(ch); 
  
    return (result); 
}

std::vector<std::string> Parsing::ParseInput::splitString(std::string s, std::string delimiter) 
{
    std::vector<std::string> result;
    char *dup = strdup(myStrLower(s).c_str());
    char *token = strtok(dup, delimiter.c_str());

    while (token != NULL) {
        result.push_back(std::string(token));
        token = strtok(NULL, delimiter.c_str());
    }
    free(dup);
    return (result);
}

bool Parsing::ParseInput::isValidOrder(std::vector<std::string> inputWords)
{
    for (const auto &validPizza : this->_validPizzas) {
        if (inputWords[0] == validPizza) {
            break;
        }
    }
    for (const auto &validSize : this->_validSizes) {
        if (inputWords[1] == validSize) {
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Pizza::IPizza>> Parsing::ParseInput::getCommand(double multiplier)
{
    // correct command line: regina XXL x2; fantasia M x3; margarita S x1
    static int orderId = 0;
    std::string inputCpy = _input;
    std::vector<std::string> inputArray = splitString(inputCpy, ";");
    std::vector<std::string> inputWords;
    std::vector<std::shared_ptr<Pizza::IPizza>> orderedPizzas;
    int orderedNb;
    
    orderId++;
    for (long unsigned int i = 0; i < inputArray.size(); i++) {
        std::shared_ptr<Pizza::IPizza> pizzaOrder;
        inputWords = splitString(inputArray[i], " ");
        if (!isValidOrder(inputWords)) {
            throw Parsing::ParsingException("Parsing error: Invalid order.");
            continue;
        }
        Pizza::PizzaArgs args;
        std::istringstream stream(inputArray[i]);
        stream >> args;
        std::string orderedNbStr = inputWords[2].substr(1, std::string::npos);
        orderedNb = std::stoi(orderedNbStr);
        for (int i = 0; i < orderedNb; i++) {
            std::shared_ptr<Pizza::IPizza> pizza = this->_factory.createPizza(
            args._type, args._size, multiplier, orderId);
            orderedPizzas.push_back(pizza);
        }
    }
    return (orderedPizzas);
}

// SERIALISATION VERSION START

// std::vector<std::shared_ptr<Pizza::IPizza>> Parsing::ParseInput::getCommand(double multiplier)
// {
//     // correct command line: regina XXL x2; fantasia M x3; margarita S x1
//     static int orderId = 0;
//     std::string inputCpy = _input;
//     std::vector<std::string> inputArray = splitString(inputCpy, ";");
//     std::vector<std::string> inputWords;
//     std::vector<std::shared_ptr<Pizza::IPizza>> orderedPizzas;
//     Pizza::PizzaFactory factory;
// 
//     
//     orderId++;
//     for (long unsigned int i = 0; i < inputArray.size(); i++) {
//         std::istringstream iss(inputArray[i]);
//         Pizza::PizzaArgs args;
//         
//         if (!(iss >> args))
//             throw Parsing::ParsingException("error: Parsing - Invalid order.");
// 
//         auto pizza = factory.createPizza(args._type, args._size, multiplier, orderId);
//         orderedPizzas.push_back(pizza);
// 
//         // std::cout << "orderedType = " << orderedPizzas[i]._type << std::endl;
//         // std::cout << "orderedSize = " << orderedPizzas[i]._size << std::endl;
//         // std::cout << "orderedNb = " << orderedPizzas[i]._nb << std::endl;
//         // std::cout << "orderId = " << orderedPizzas[i]._orderId << std::endl;
//     }
//     return (orderedPizzas);
// }
