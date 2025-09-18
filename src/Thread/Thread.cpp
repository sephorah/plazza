/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Plazza
*/

#include "Thread/Thread.hpp"

Thread::Thread() : _thread(std::thread(&Thread::job, this))
{
}

Thread::~Thread()
{
    _thread.join();
}

void Thread::job()
{}
