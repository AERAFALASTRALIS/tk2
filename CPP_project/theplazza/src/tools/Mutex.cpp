/*
** EPITECH PROJECT, 2021
** mutex
** File description:
** mutex
*/

#include "Error.hpp"
#include "Mutex.hpp"

using Plazza::Error;
using Tools::Mutex;

Mutex::Mutex() : _mutex(new pthread_mutex_t), _status(Mutex::UNLOCK)
{
    if (pthread_mutex_init(_mutex, NULL) != 0)
        throw Error(Error::Code::MUTEXFAIL, "Mutex::init() : failed");
}

Mutex::~Mutex()
{
    if (_status == Mutex::LOCK)
        this->unlock();
    if (pthread_mutex_destroy(_mutex) != 0) {
        std::cerr << "[ERROR]: Mutex::destroy() : failed" << std::endl;
        exit(84);
    }
}

void Mutex::lock()
{
    if (pthread_mutex_lock(_mutex) != 0)
        throw Error(Error::Code::MUTEXLOCK, "Mutex::lock() : failed");
    _status = Mutex::LOCK;
}

void Mutex::unlock()
{
    if (pthread_mutex_unlock(_mutex) != 0)
        throw Error(Error::Code::MUTEXLOCK, "Mutex::unlock() : failed");
    _status = Mutex::UNLOCK;
}

void Mutex::trylock()
{
    bool lock = pthread_mutex_trylock(_mutex) == 0;
    _status = lock ? Mutex::LOCK : Mutex::UNLOCK;
}

pthread_mutex_t *Mutex::getMutex() const
{
    return (_mutex);
}
