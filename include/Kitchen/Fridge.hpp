/*
** EPITECH PROJECT, 2024
** Fridge
** File description:
** Plazza
*/

#ifndef FRIDGE_HPP_
#define FRIDGE_HPP_
#include <unordered_map>
#include <condition_variable>
#include <mutex>
#include <thread>
#define MAX_INGREDIENTS 5

namespace Pizza {
    enum IngredientType {
        Dough,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove,
        Pepperoni,
        None
    };
}

namespace Kitchen {
    class Fridge {
        public:
            Fridge(int refillTime);
            ~Fridge() = default;
            void fill();
            std::chrono::milliseconds getRefillTime() const;
            void takeIngredient(Pizza::IngredientType type);
            std::string getStatusFridge();

        private:
            std::chrono::milliseconds _refillTime;
            std::mutex _fridgeMutex;
            std::unordered_map<Pizza::IngredientType, std::string> _ingredients = {
                {Pizza::Dough, "Dough"},
                {Pizza::Tomato, "Tomato"},
                {Pizza::Gruyere, "Gruyere"},
                {Pizza::Ham, "Ham"},
                {Pizza::Mushrooms, "Mushrooms"},
                {Pizza::Steak, "Steak"},
                {Pizza::Eggplant, "Eggplant"},
                {Pizza::GoatCheese, "Goat cheese"},
                {Pizza::ChiefLove, "Chief love"},
                {Pizza::Pepperoni, "Pepperoni"}
            };

            std::unordered_map<Pizza::IngredientType, std::size_t> _fridge = {
                {Pizza::Dough, MAX_INGREDIENTS},
                {Pizza::Tomato, MAX_INGREDIENTS},
                {Pizza::Gruyere, MAX_INGREDIENTS},
                {Pizza::Ham, MAX_INGREDIENTS},
                {Pizza::Mushrooms, MAX_INGREDIENTS},
                {Pizza::Steak, MAX_INGREDIENTS},
                {Pizza::Eggplant, MAX_INGREDIENTS},
                {Pizza::GoatCheese, MAX_INGREDIENTS},
                {Pizza::ChiefLove, MAX_INGREDIENTS},
                {Pizza::Pepperoni, MAX_INGREDIENTS}
            };
            std::condition_variable _fridgeCondVar;
    };
}

#endif /* !FRIDGE_HPP_ */
