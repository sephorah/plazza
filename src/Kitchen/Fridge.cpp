/*
** EPITECH PROJECT, 2024
** Fridge.cpp
** File description:
** Plazza
*/

#include "Kitchen/Fridge.hpp"
#include <iostream>
#include "Pizza/IPizza.hpp"

Kitchen::Fridge::Fridge(int refillTime) : _refillTime(std::chrono::milliseconds(refillTime))
{}

void Kitchen::Fridge::fill()
{
    std::unique_lock<std::mutex> fridgeLock{this->_fridgeMutex};
    bool refill = false;

    for (const auto &[type, nb] : this->_fridge) {
        if (this->_fridge[type] < MAX_INGREDIENTS) {
            this->_fridge[type] += 1;
            refill = true;
        }
    }
    if (refill) {
       std::cout << "[Fridge] Refilled!" << std::endl;
    }
}

std::chrono::milliseconds Kitchen::Fridge::getRefillTime() const
{
    return this->_refillTime;
}

void Kitchen::Fridge::takeIngredient(Pizza::IngredientType type)
{
    std::unique_lock<std::mutex> fridgeLock{this->_fridgeMutex};

    // std::cout << "Waiting for ingredient " << this->_ingredients[type] << "..." << std::endl;
    this->_fridgeCondVar.wait(fridgeLock,
        [&]{ return (this->_fridge[type] > 0); });
    // std::cout << "Stopped waiting for ingredient " << this->_ingredients[type] << std::endl;
    this->_fridge[type] -= 1;
}

std::string Kitchen::Fridge::getStatusFridge()
{
    std::string str;

    for (auto &[ingredient, quantity] : this->_fridge) {
        str += this->_ingredients[ingredient] + ": " + std::to_string(quantity) + "\n";
    }
    return str;
}