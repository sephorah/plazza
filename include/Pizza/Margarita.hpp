/*
** EPITECH PROJECT, 2024
** Margarita.hpp
** File description:
** Plazza
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_
#include "Pizza/APizza.hpp"

namespace Pizza {
    class Margarita : public APizza {
        public:
            Margarita(PizzaSize size, float multiplier, int orderId);
            ~Margarita() = default;
            PizzaType getType() final;
    };
}

#endif /* !MARGARITA_HPP_ */
