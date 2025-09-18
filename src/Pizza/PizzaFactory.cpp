/*
** EPITECH PROJECT, 2024
** Pizza
** File description:
** Plazza
*/

#include "Pizza/PizzaFactory.hpp"

Pizza::PizzaFactory::PizzaFactory() : _factory({})
{
    this->_factory.emplace(PizzaType::Americana, [](PizzaSize size, float multiplier, int orderId) { return std::make_shared<Pizza::Americana>(size, multiplier, orderId); });
    this->_factory.emplace(PizzaType::Fantasia, [](PizzaSize size, float multiplier, int orderId) { return std::make_shared<Pizza::Fantasia>(size, multiplier, orderId); });
    this->_factory.emplace(PizzaType::Margarita, [](PizzaSize size, float multiplier, int orderId) { return std::make_shared<Pizza::Margarita>(size, multiplier, orderId); });
    this->_factory.emplace(PizzaType::Regina, [](PizzaSize size, float multiplier, int orderId) { return std::make_shared<Pizza::Regina>(size, multiplier, orderId); });
    this->_factory.emplace(PizzaType::Monza, [](PizzaSize size, float multiplier, int orderId) { return std::make_shared<Pizza::Monza>(size, multiplier, orderId); });
}

std::shared_ptr<Pizza::IPizza> Pizza::PizzaFactory::createPizza(PizzaType type, PizzaSize size, float multiplier, int orderId)
{
    return this->_factory[type](size, multiplier, orderId);
}
