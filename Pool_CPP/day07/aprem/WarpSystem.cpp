/*
** EPITECH PROJECT, 2021
** warm
** File description:
** warm
*/

#include <iostream>
#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(void)
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor(void)
{

}

bool WarpSystem::QuantumReactor::isStable(void)
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool value)
{
    this->_stability = value;
}

WarpSystem::Core::Core(QuantumReactor*coreReactor)
{
    this->_coreReactor = coreReactor;
}

WarpSystem::Core::~Core(void)
{

}

WarpSystem::QuantumReactor*WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}
