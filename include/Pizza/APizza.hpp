/*
** EPITECH PROJECT, 2024
** APizza
** File description:
** Plazza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_
#include <vector>
#include <chrono>
#include "Pizza/IPizza.hpp"

namespace Pizza {
    std::istream& operator>>(std::istream& is, Pizza::PizzaArgs& args);
    std::istream& operator<<(std::istream& is, Pizza::PizzaArgs& args);
    class APizza : public IPizza {
        public:
            APizza(PizzaSize size, int orderId);
            virtual ~APizza() = default;
            void cook(std::shared_ptr<Kitchen::Fridge> fridge) final;
            PizzaSize getSize() final;
            std::chrono::milliseconds getCookingTime() final;
            int getOrderId() final;
            bool isPizzaDone() final;
            // int getQuantity() final;
            // PizzaType setType(PizzaType type) final
            // PizzaSize setSize(PizzaSize size) final;


        protected:
            std::vector<Pizza::IngredientType> _listIngredients;
            PizzaSize _size;
            std::chrono::milliseconds _cookingTime;
            bool _isDone;
            int _orderId;
            int _quantity;
    };
    
}


#endif /* !APIZZA_HPP_ */
