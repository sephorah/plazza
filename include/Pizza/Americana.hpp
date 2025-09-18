/*
** EPITECH PROJECT, 2024
** Americana
** File description:
** Plazza
*/

#ifndef AMERICANA_HPP_
#define AMERICANA_HPP_
#include "Pizza/APizza.hpp"

namespace Pizza {
    class Americana : public APizza {
        public:
            Americana(PizzaSize size, float multiplier, int orderId);
            ~Americana() = default;
            PizzaType getType() final;
    };
}

#endif /* !AMERICANA_HPP_ */
