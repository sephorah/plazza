/*
** EPITECH PROJECT, 2024
** Monza
** File description:
** Plazza
*/

#ifndef MONZA_HPP_
#define MONZA_HPP_
#include "Pizza/APizza.hpp"

namespace Pizza {
    class Monza : public APizza {
        public:
            Monza(PizzaSize size, float multiplier, int orderId);
            ~Monza() = default;
            PizzaType getType() final;
    };
}

#endif /* !MONZA_HPP_ */
