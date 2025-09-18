/*
** EPITECH PROJECT, 2024
** Monza
** File description:
** Plazza
*/

#include "Pizza/Monza.hpp"

Pizza::Monza::Monza(PizzaSize size, float multiplier, int orderId) : APizza(size, orderId)
{
    this->_cookingTime = std::chrono::milliseconds(static_cast<int>(2500 * multiplier));
    this->_listIngredients.push_back(Dough);
    this->_listIngredients.push_back(Tomato);
    this->_listIngredients.push_back(Gruyere);
    this->_listIngredients.push_back(Pepperoni);
}

PizzaType Pizza::Monza::getType()
{
    return PizzaType::Monza;
}