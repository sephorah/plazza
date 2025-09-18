/*
** EPITECH PROJECT, 2024
** Kitchen (header)
** File description:
** Plazza
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_
#include <unordered_map>
#include <condition_variable>
#include <mutex>
#include <fstream>
#include <map>
#include "Reception/Reception.hpp"
#include "ThreadPool/ThreadPool.hpp"
#include "Parsing/ParseInput.hpp"
#include "Parsing/ParseArgs.hpp"
#include "Kitchen/Fridge.hpp"
#include "Kitchen/Refill.hpp"
#define FULL_KITCHEN 10
#define NEED_INGREDIENTS 15

namespace Kitchen {
    class Kitchen {
    private:
        ThreadPool::ThreadPool<std::shared_ptr<Fridge>> _cookPool;
        // bool _running;
        args_t _args;
        std::shared_ptr<Fridge> _kitchenFridge;
        Refill _refillThread;
        std::size_t _maxNbPizzas;
        std::size_t _currentNbPizzas;
        std::mutex _orderStatusMutex;

    public:
        Kitchen() = default;
        Kitchen(args_t& args);
        ~Kitchen();
        int addOrder(std::vector<std::shared_ptr<Pizza::IPizza>> orders);
        ThreadPool::Task createTask(std::shared_ptr<Pizza::IPizza> pizza);
        int writeToRecord(const std::string& str);
        void getState();
        std::size_t& getMaxNbPizzas();
        std::size_t& getCurrentNbPizzas();
        bool isOrderReady(std::vector<std::shared_ptr<Pizza::IPizza>> orders);
    };

    class KitchenException : public std::exception {
    private:
        std::string _message;
    public:
    KitchenException() : _message("") {}
    KitchenException(const std::string& msg) : _message(msg) {}
    virtual const char* what() const throw() {
        return _message.c_str();
    }
    };
}

#endif /* !KITCHEN_HPP_ */