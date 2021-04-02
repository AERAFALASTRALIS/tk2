/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <iostream>
#include <stdexcept>

class NasaError
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");

        std::string const &getComponent() const;
        char const *what() const throw();
    private:
        std::string _message;
        std::string _component;
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
};

#endif
