/*
** EPITECH PROJECT, 2024
** Process
** File description:
** Plazza
*/

#include "Process/Process.hpp"

Process::Process() {
  _pid = fork();
}

Process::~Process() 
{
    if (_pid > 0)
      kill(_pid, SIGKILL);
}

pid_t Process::getPid() const 
{
  if (_pid == -1)
    throw (ProcessException("Process error: fork failed."));
  return (_pid);
}