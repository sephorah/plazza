/*
** EPITECH PROJECT, 2024
** ThreadPool
** File description:
** Plazza
*/

#ifndef THREAD_POOL_HPP_
#define THREAD_POOL_HPP_
#include <cstdio>
#include <functional>
#include "ThreadPool/SafeQueue.hpp"
#include "Kitchen/Fridge.hpp"
#include "Pizza/IPizza.hpp"
#include "ThreadPool/Task.hpp"

namespace ThreadPool {
    template <typename T>
    class ThreadPool {
        public:
            ThreadPool(std::size_t nbThreads) : _nbThreads(nbThreads)
            {
                for (std::size_t i = 0; i < nbThreads; i++)
                    this->_threads.emplace_back(std::thread(&ThreadPool::workerJob, this));
            }

            ~ThreadPool()
            {
                Task stopTask(TaskType::Stop,
                    {});

                for (std::size_t i = 0; i < this->_nbThreads; i++) {
                    this->push(stopTask);
                }
                for (auto& thread : this->_threads) { 
                    thread.join(); 
                }
            }

            void workerJob() 
            {
                while (true) {
                    auto const task = this->_queue.pop();

                    // {
                    //     std::lock_guard<std::mutex> lock(_statusMutex);
                    //     _threadsStatus[threadIndex] = true; // busy
                    // }

                    switch (task._type) {
                        case TaskType::Execute:
                            task._task();
                            break;
                        case TaskType::Stop:
                            // {
                            //     std::lock_guard<std::mutex> lock(_statusMutex);
                            //     _threadsStatus[threadIndex] = false; // free
                            // }
                            return;
                    }

                    // {
                    //     std::lock_guard<std::mutex> lock(_statusMutex);
                    //     _threadsStatus[threadIndex] = false; // free
                    // }
                }
            }

            // std::size_t getNbBusyCooks() 
            // {
            //     // std::size_t nbBusyCooks = 0;
            //     // std::lock_guard<std::mutex> lock(_statusMutex);

            //     // for (bool status : _threadsStatus) {
            //     //     if (status)
            //     //         nbBusyCooks += 1;
            //     // }
            //     // return (nbBusyCooks);
            //     return 0;
            // }

            bool push(Task task)
            {
                this->_queue.push(task);
                return true;
            }

        private:
            SafeQueue<Task> _queue;
            std::vector<std::thread> _threads;
            T _sharedVar;
            std::size_t _nbThreads;
            // std::vector<bool> _threadsStatus;   
            std::mutex _statusMutex;
    };
}

// // class ThreadPool
// // {
// // public:
// //   ThreadPool(std::size_t n_threads)
// //   {
// //     for (std::size_t i = 0; i < n_threads; ++i)
// //     {
// //       _threads.push_back(make_thread_handler(_queue));
// //     }
// //   }

// //   ~ThreadPool()
// //   {
// //     // Task = {Execute/Stop, function, Ts}
// //     Task const stop_task{TaskType::Stop, {}, {}};
// //     for (std::size_t i = 0; i < _threads.size(); ++i)
// //     {
// //       push(stop_task);
// //     }
// //   }

// //   bool push(Task const& task)
// //   {
// //     _queue.push(task);
// //     return true;
// //   }
// // private:
// //   TsQueue<Task> _queue;
// //   std::vector<std::jthread> _threads;
// // }

#endif /* !THREAD_POOL_HPP_ */
