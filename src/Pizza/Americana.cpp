/*
** EPITECH PROJECT, 2024
** Americana
** File description:
** Plazza
*/

#include "Pizza/Americana.hpp"

Pizza::Americana::Americana(PizzaSize size, float multiplier, int orderId) : APizza(size, orderId)
{
    this->_cookingTime = std::chrono::milliseconds(static_cast<int>(2000 * multiplier));
    this->_listIngredients.push_back(Dough);
    this->_listIngredients.push_back(Tomato);
    this->_listIngredients.push_back(Gruyere);
    this->_listIngredients.push_back(Steak);
}

PizzaType Pizza::Americana::getType()
{
    return PizzaType::Americana;
}