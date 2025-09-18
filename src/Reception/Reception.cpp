/*
** EPITECH PROJECT, 2024
** Core
** File description:
** Plazza
*/

#include "Reception/Reception.hpp"

int Reception::handleReception(args_t& args) 
{
    std::vector<std::shared_ptr<Pizza::IPizza>> orderedPizzas;
    std::vector<std::shared_ptr<Pizza::IPizza>> remainingOrders;

    try {
        Process process;
        if (process.getPid() > 0) {
            MessageQueue message;
            message._message.msgType = 1;
            while (true) {
                std::string input;
                std::cout << "Please, enter your command: ";
                std::getline(std::cin, input);
                memset(message._message.msgText, 0, sizeof(message._message.msgText));          
                strcpy(message._message.msgText, input.c_str());
                message.sendMsg();
            }
        } else {
            Kitchen::Kitchen kitchen(args);
            MessageQueue message;
            while (true) {
                if (message.receiveMsg() == 0) {
                    std::string input = message._message.msgText;
                    if (input == "status") {
                        kitchen.getState();
                    } else {
                        try {
                            Parsing::ParseInput orderParser(input);
                            orderedPizzas = orderParser.getCommand(args.cookingTimeMultiplier);
                        } catch (const Parsing::ParsingException& error) {
                            std::cerr << error.what() << std::endl;
                        }
                        try {
                            kitchen.addOrder(orderedPizzas);
                        } catch (const Kitchen::KitchenException& error) {
                            std::cerr << error.what() << std::endl;
                        }
                    }
                }
            }
        }
    } catch (const Process::ProcessException& error) {
        std::cerr << error.what() << std::endl;
        throw Reception::ReceptionException("error: Reception - fork failure.");
    }
    return SUCCESS;
}
