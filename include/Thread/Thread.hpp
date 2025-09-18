/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Plazza
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_
#include <thread>

class IThread {
    public:
        virtual ~IThread() = default;
        virtual void job() = 0;
};

class Thread : IThread {
    public:
        Thread();
        ~Thread();
        void job();

    protected:
        std::thread _thread;
};

#endif /* !THREAD_HPP_ */
