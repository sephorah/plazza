/*
** EPITECH PROJECT, 2024
** Fantasia
** File description:
** Plazza
*/

#include "Pizza/Fantasia.hpp"

Pizza::Fantasia::Fantasia(PizzaSize size, float multiplier, int orderId) : APizza(size, orderId)
{
    this->_cookingTime = std::chrono::milliseconds(static_cast<int>(4000 * multiplier));
    this->_listIngredients.push_back(Dough);
    this->_listIngredients.push_back(Tomato);
    this->_listIngredients.push_back(Eggplant);
    this->_listIngredients.push_back(GoatCheese);
    this->_listIngredients.push_back(ChiefLove);
}

PizzaType Pizza::Fantasia::getType()
{
    return PizzaType::Fantasia;
}