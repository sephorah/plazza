/*
** EPITECH PROJECT, 2024
** Refill.cpp
** File description:
** Plazza
*/

#include "Kitchen/Refill.hpp"
#include <iostream>

Kitchen::Refill::Refill(std::shared_ptr<Kitchen::Fridge> fridge) : _fridge(fridge)
{
}

void Kitchen::Refill::job()
{
    while (true) { //while kitchen is still up
        this->_fridge->fill();
        std::this_thread::sleep_for(this->_fridge->getRefillTime());
    }
}
