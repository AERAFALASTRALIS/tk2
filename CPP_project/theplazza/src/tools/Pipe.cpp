/*
** EPITECH PROJECT, 2021
** pipe
** File description:
** pipe
*/

#include "my.h"
#include "Mutex.hpp"
#include "Pipe.hpp"
#include "ScopedLock.hpp"

using Tools::Pipe;
using Tools::Input;
using Tools::Output;
using Tools::ScopedLock;
using Tools::Mutex;
using Plazza::Error;

Pipe::Pipe(std::string const &path) : _path(path)
{
}

Pipe::~Pipe()
{
}

Input::Input(std::string const &path) : Pipe(path)
{
    Mutex mutex;
    mutex.lock();
    if (access(_path.c_str(), R_OK) == -1) {
        if (mkfifo(_path.c_str(), 0666) == -1) 
            throw Error(Error::Code::PIPEFAILURE, "failed named pipe1");
    }
    _file.open(_path);
    if (_file.fail())
        throw Error(Error::Code::PIPEFAILURE, "failed named pipe2");
    mutex.unlock();
}

Input::~Input()
{
    _file.close();
    unlink(_path.c_str());
}

Input &Input::operator>>(std::string &text)
{
    if (_file.good())
        std::getline(_file, text);
    return (*this);
}

void Input::read(std::string &text)
{
    if (_file.good())
        std::getline(_file, text);
}

Output::Output(std::string const &path) : Pipe(path)
{
    Mutex mutex;
    mutex.lock();
    if (access(_path.c_str(), W_OK) == -1) {
        if (mkfifo(_path.c_str(), 0666) == -1)
            throw Error(Error::Code::PIPEFAILURE, "failed named pipe3");
    }
    _file.open(_path);
    if (_file.fail())
        throw ;
    mutex.unlock();
}

Output::~Output()
{
    _file.close();
    unlink(_path.c_str());
}

Output &Output::operator<<(std::string const &text)
{
    if (_file.good())
        _file << text << std::endl;
    return (*this);
}

void Output::write(std::string const &text)
{
    if (_file.good())
        _file << text << std::endl;
}
