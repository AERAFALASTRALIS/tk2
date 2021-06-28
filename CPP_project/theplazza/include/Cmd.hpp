/*
** EPITECH PROJECT, 2021
** cmd
** File description:
** cmd
*/

#ifndef CMD_HPP_
#define CMD_HPP_

#include "Reception.hpp"
#include "Parsing.hpp"
#include <iostream>

namespace Plazza {
    class Cmd {
    public:
        Cmd(Plazza::Parsing pars, Plazza::Reception room);
        ~Cmd();
        std::string getCommand() const;
        void launchTerm();
        void passCommand();
        void killKitchen();
    protected:
    private:
        std::string _command;
        Plazza::Parsing _pars;
        Plazza::Reception _room;
    };
};

#endif /* !CMD_HPP_ */
