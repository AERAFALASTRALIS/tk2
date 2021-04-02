/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** IEngine.hpp
*/

#ifndef IENGINE_HPP_
#define IENGINE_HPP_

class IEngine {
public:
    // Initialize class content in thread, if needed.
    virtual void init() = 0;
    // Action called refreshFrequency times per second.
    virtual void refresh() = 0;
    // Uninitialize class content, if needed. Called in the thread.
    virtual ~IEngine() {}
    // Tell if initialization has completed.
    virtual bool isReady() const = 0;
};

#endif /* IENGINE_HPP_ */
