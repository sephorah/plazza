/*
** EPITECH PROJECT, 2024
** IPizza
** File description:
** Plazza
*/

#ifndef IPIZZA_HPP_
#define IPIZZA_HPP_
#include <memory>
#include <istream>
#include "Kitchen/Fridge.hpp"

enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
    Monza = 10
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

namespace Pizza {
    struct PizzaArgs {
        PizzaType _type;
        PizzaSize _size;
        // std::size_t _quantity;
    };
    
    class IPizza {
        public:
            virtual ~IPizza() = default;
            virtual void cook(std::shared_ptr<Kitchen::Fridge> fridge) = 0;
            virtual PizzaType getType() = 0;
            virtual PizzaSize getSize() = 0;
            virtual std::chrono::milliseconds getCookingTime() = 0;
            virtual int getOrderId() = 0;
            // virtual int getQuantity() = 0;
            virtual bool isPizzaDone() = 0;
            // virtual PizzaType setType(PizzaType type) = 0;
            // virtual PizzaSize setSize(PizzaSize size) = 0;
            
    };
}

#endif /* !IPIZZA_HPP_ */
