/*
** EPITECH PROJECT, 2021
** cmd
** File description:
** cmd
*/

#include "Reception.hpp"
#include "Parsing.hpp"
#include "Error.hpp"
#include "Pizza.hpp"
#include "Cmd.hpp"
#include "Log.hpp"
#include "my.h"

using Plazza::Cmd;
using Plazza::Parsing;
using Plazza::Reception;
using Plazza::Pizza;

static std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;

    while (getline(ss, tok, delimiter))
        internal.push_back(tok);
    return (internal);
}

Cmd::Cmd(Parsing pars, Reception room) : _command(""), _pars(pars), _room(room)
{
}

Cmd::~Cmd()
{
}

void Cmd::killKitchen()
{
}

void Cmd::launchTerm()
{
    Log log;
    std::vector<std::string> pizzaOrders;
    while (true) {
        std::getline(std::cin, _command);
        log.write("User[Input]: " + _command);
        if (_command == "exit" || _command == "quit")
            return (_room.killKitchens());
        if (!std::cin) {
            if (std::cin.eof())
                exit(0);
            exit(84);
        }
        try {
            if (!_pars.CheckCommand(_command))
                return;
            pizzaOrders = split(_command, ';');
            for (int i = 1; i < (int)pizzaOrders.size(); i++)
                pizzaOrders[i].erase(0, 1);
            for (int i = 0; i < (int)pizzaOrders.size(); i++)
                _room.createPizza(pizzaOrders[i]);
            _room.handleQueue();
        }
        catch(Plazza::Error& ex) {
            ex.what();
        }
    }
}

std::string Cmd::getCommand() const
{
    return (_command);
}
