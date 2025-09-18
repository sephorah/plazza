/*
** EPITECH PROJECT, 2024
** Margarita
** File description:
** Plazza
*/

#include "Pizza/Margarita.hpp"

Pizza::Margarita::Margarita(PizzaSize size, float multiplier, int orderId) : APizza(size, orderId)
{
    this->_cookingTime = std::chrono::milliseconds(static_cast<int>(1000 * multiplier));
    this->_listIngredients.push_back(Dough);
    this->_listIngredients.push_back(Tomato);
    this->_listIngredients.push_back(Gruyere);
}

PizzaType Pizza::Margarita::getType()
{
    return PizzaType::Margarita;
}