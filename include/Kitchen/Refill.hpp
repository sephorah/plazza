/*
** EPITECH PROJECT, 2024
** Refill.hpp
** File description:
** Plazza
*/

#ifndef REFILL_HPP_
#define REFILL_HPP_
#include "Thread/Thread.hpp"
#include "Kitchen/Fridge.hpp"

namespace Kitchen {
    class Refill : public Thread {
        public:
            Refill(std::shared_ptr<Fridge> fridge);
            ~Refill() = default;
            void job() final;

        private:
            std::shared_ptr<Fridge> _fridge;
    };
}

#endif /* !REFILL_HPP_ */
