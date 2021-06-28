/*
** EPITECH PROJECT, 2021
** Scoped
** File description:
** Scoped
*/

#include "ScopedLock.hpp"

using Tools::ScopedLock;

ScopedLock::ScopedLock(Mutex &mutex) : _mutex(mutex)
{
    _mutex.lock();
}

ScopedLock::~ScopedLock()
{
    _mutex.unlock();
}
