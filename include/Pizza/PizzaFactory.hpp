/*
** EPITECH PROJECT, 2024
** PizzaFactory
** File description:
** Plazza
*/

#ifndef PIZZA_FACTORY_HPP_
#define PIZZA_FACTORY_HPP_
#include <memory>
#include <functional>
#include "Pizza/IPizza.hpp"
#include "Pizza/Americana.hpp"
#include "Pizza/Fantasia.hpp"
#include "Pizza/Margarita.hpp"
#include "Pizza/Regina.hpp"
#include "Pizza/Monza.hpp"

namespace Pizza {
    class PizzaFactory {
        public:
            PizzaFactory();
            ~PizzaFactory() = default;
            std::shared_ptr<Pizza::IPizza> createPizza(PizzaType type, PizzaSize size, float multiplier, int orderId);

            private:
                std::unordered_map<PizzaType, std::function<std::shared_ptr<Pizza::IPizza>(PizzaSize size, float multiplier, int orderId)>> _factory;
    };
}

#endif /* !PIZZA_FACTORY_HPP_ */
