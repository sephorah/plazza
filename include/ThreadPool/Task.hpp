/*
** EPITECH PROJECT, 2024
** Task.hpp
** File description:
** Plazza
*/

#ifndef TASK_HPP_
#define TASK_HPP_
#include <functional>
#include "Pizza/APizza.hpp"

namespace ThreadPool {
    enum TaskType { Execute, Stop };
    class Task {
        public:
            Task(TaskType type, std::function<void()> task) :
                _type(type), _task(task)
            {}
            ~Task() = default;
        
            TaskType _type;
            std::function<void()> _task;
    };
}

#endif /* !TsASK_HPP_ */
