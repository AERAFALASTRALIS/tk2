/*
** EPITECH PROJECT, 2021
** process
** File description:
** process
*/

#include "my.h"
#include "Error.hpp"
#include "Process.hpp"

using Plazza::Error;
using Tools::Process;
using Tools::IProcess;

Process::Process(ICooking &task) : _pid(0), _status(IProcess::WAITING), _text("kitchen")
{
    if ((_pid = fork()) == -1)
        throw Error(Error::Code::PROCESSCREATE, "Process: fork failed");
    if (_pid == 0) {
        task.cook(_text);
        exit(0);
        throw Error(Error::Code::PROCESSCREATE, "Process exit Failed");
    }
    else
        _status = IProcess::RUNNING;
}

Process::~Process()
{
    this->waitProcess();
}

void Process::waitProcess()
{
    if (_status == Process::RUNNING) {
        if (waitpid(_pid, NULL, 0) == -1)
            throw Error(Error::Code::PROCESSWAIT, "waitpid failed");
        _status = Process::WAITING;
    }
}
