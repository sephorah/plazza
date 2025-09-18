/*
** EPITECH PROJECT, 2024
** main
** File description:
** plazza
*/

#include "Reception/Reception.hpp"
#include "ThreadPool/ThreadPool.hpp"
#include "Pizza/Americana.hpp"
#include "Pizza/Fantasia.hpp"
#include "Pizza/Margarita.hpp"
#include "Pizza/Regina.hpp"
#include "Pizza/PizzaFactory.hpp"
#include "Kitchen/Fridge.hpp"
#include "Kitchen/Refill.hpp"

int main(int argc, const char* argv[])
{
    Parsing::ParseArgs argsParser;
    Reception reception;
    args_t args;

    try {
        args = argsParser.checkArgs(argc, argv);
    } catch (const Parsing::ParsingException& error) {
        return (argsParser.dislayHelp());
    }
    try {
        reception.handleReception(args);
    } catch (const Reception::ReceptionException& error) {
        return ERROR;
    }
    return (SUCCESS);

    // int nbThreads = 3;
    // ThreadPool::ThreadPool<std::shared_ptr<Kitchen::Fridge>> pool(nbThreads);
    // int refillTime = 500;
    // std::shared_ptr<Kitchen::Fridge> fridge = std::make_shared<Kitchen::Fridge>(refillTime);
    // Pizza::PizzaFactory factory;
    // // std::vector<ThreadPool::Task<std::shared_ptr<Kitchen::Fridge>>> orders;
    // std::vector<std::shared_ptr<Pizza::IPizza>> pizzas;
    // float multiplier = 1;

    // pizzas.push_back(factory.createPizza(PizzaType::Americana, PizzaSize::M, multiplier));
    // pizzas.push_back(factory.createPizza(PizzaType::Americana, PizzaSize::M, multiplier));
    // pizzas.push_back(factory.createPizza(PizzaType::Margarita, PizzaSize::XL, multiplier));
    // pizzas.push_back(factory.createPizza(PizzaType::Fantasia, PizzaSize::M, multiplier));
    // pizzas.push_back(factory.createPizza(PizzaType::Regina, PizzaSize::M, multiplier));
    // pizzas.push_back(factory.createPizza(PizzaType::Regina, PizzaSize::M, multiplier));
    // pizzas.push_back(factory.createPizza(PizzaType::Fantasia, PizzaSize::M, multiplier));

    // Kitchen::Refill refillThread(fridge);

    // for (auto &pizza : pizzas) {
    //     ThreadPool::Task task(ThreadPool::TaskType::Execute,
    //     [pizza, fridge]() {
    //         // std::cout << "Pizza " << pizza->getType() << " " << pizza->getSize() << std::endl;
    //         std::cout << "[" << std::this_thread::get_id() << "] Cooking pizza " << pizza->getType() << " " << pizza->getSize() << " ..." << std::endl;
    //         pizza->cook(fridge);
    //         std::this_thread::sleep_for(pizza->getCookingTime());
    //         std::cout << "Pizza " << pizza->getType() << " " << pizza->getSize() << " cooked !" << std::endl;
    //     });
    //     pool.push(task);
    // }

    // ThreadPool::Task<std::shared_ptr<Kitchen::Fridge>> task(ThreadPool::TaskType::Execute,
    //     [](std::shared_ptr<Kitchen::Fridge> fridge) {
    //         task.
    //         std::this_thread::sleep_for(std::chrono::seconds{1});
    //     }, fridge);
    //     pool.push(task);
}
