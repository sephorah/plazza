/*
** EPITECH PROJECT, 2024
** SafeQueue
** File description:
** Plazza
*/

#ifndef SAFE_QUEUE_HPP_
#define SAFE_QUEUE_HPP_
#include <queue>
#include <memory>
#include <mutex>
#include <chrono>
#include <iostream>
#include <condition_variable>
#include <thread>

template <typename T>
class ISafeQueue {
    public:
        virtual ~ISafeQueue() = default;
        virtual void push(T const &value) = 0;
        virtual T pop() = 0;
};

template <typename T>
class SafeQueue : public ISafeQueue<T> {
    public:
        SafeQueue() = default;
        ~SafeQueue() = default;

        void push(T const &value) final
        {
            std::lock_guard<std::mutex> queueLock{this->_queueMutex};

            this->_queue.push(value);
            this->_queueCondVar.notify_one();
        }

        T pop() final
        {
            std::unique_lock<std::mutex> queueLock{this->_queueMutex};

            this->_queueCondVar.wait(queueLock, [&]{ return !_queue.empty(); });
            T value = this->_queue.front();
            this->_queue.pop();
            return value;
        }

    private:
        std::queue<T> _queue;
        std::mutex _queueMutex;
        std::condition_variable _queueCondVar;
};

#endif /* !SAFE_QUEUE_HPP_ */
