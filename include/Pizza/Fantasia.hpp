/*
** EPITECH PROJECT, 2024
** Fantasia
** File description:
** Plazza
*/

#ifndef FANTASIA_HPP_
#define FANTASIA_HPP_
#include "Pizza/APizza.hpp"

namespace Pizza {
    class Fantasia : public APizza {
        public:
            Fantasia(PizzaSize size, float multiplier, int orderId);
            ~Fantasia() = default;
            PizzaType getType() final;
    };
}

#endif /* !FANTASIA_HPP_ */
