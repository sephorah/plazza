/*
** EPITECH PROJECT, 2024
** Regina
** File description:
** Plazza
*/

#ifndef REGINA_HPP_
#define REGINA_HPP_
#include "Pizza/APizza.hpp"

namespace Pizza {
    class Regina : public APizza {
        public:
            Regina(PizzaSize size, float multiplier, int orderId);
            ~Regina() = default;
            PizzaType getType() final;
    };
}


#endif /* !REGINA_HPP_ */
