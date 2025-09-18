/*
** EPITECH PROJECT, 2024
** Regina
** File description:
** Plazza
*/

#include "Pizza/Regina.hpp"

Pizza::Regina::Regina(PizzaSize size, float multiplier, int orderId) : APizza(size, orderId)
{
    this->_cookingTime = std::chrono::milliseconds(static_cast<int>(2000 * multiplier));
    this->_listIngredients.push_back(Dough);
    this->_listIngredients.push_back(Tomato);
    this->_listIngredients.push_back(Gruyere);
    this->_listIngredients.push_back(Ham);
    this->_listIngredients.push_back(Mushrooms);
}

PizzaType Pizza::Regina::getType()
{
    return PizzaType::Regina;
}
