/*
** EPITECH PROJECT, 2021
** parsing
** File description:
** parsing
*/

#include "Pizza.hpp"
#include "Error.hpp"
#include "Parsing.hpp"

using Plazza::Parsing;
using Plazza::Error;

static std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;
    while (getline(ss, tok, delimiter))
        internal.push_back(tok);
    return (internal);
}

static void printUsage()
{
    std::cout << "Usage : ./plazza [arg1] [arg2] [arg3]\n" << std::endl;
    std::cout << "\targ1: Multiplicator of cooking times" << std::endl;
    std::cout << "\targ2: Number of cooks by Kitchens" << std::endl;
    std::cout << "\targ3: Refresh time in milliseconde" << std::endl;
    exit(0);
}

Parsing::Parsing(int argc, char **argv)
{
    CheckMainArgs(argc, argv);
}

Parsing::~Parsing()
{
}

bool Parsing::IsNum(const char *str)
{
    for (int i = 0; str[i] != (const char)'\0'; i++) {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool Parsing::CheckMainArgs(int argc, char **argv)
{
    std::string arg;

    try {
        for (size_t i = 1; argv[i]; i++) {
            if ((arg = argv[i]) == "-help")
                printUsage();
        }
        if (argc < 4)
            throw Error(Error::Code::MAINARGSNB, "Too few arguments");
        if (argc > 4)
            throw Error(Error::Code::MAINARGSNB, "Too many arguments");
        for (size_t i = 2; argv[i]; i++) {
            if (!IsNum(argv[i]))
                throw Error(Error::Code::MAINARGSTYPE, "not correct");
        }
        if (!IsNum(argv[1])) {
            if (std::regex_match(argv[1], std::regex("([0][.][0-9]+)")))
                return (true);
            else
                throw Error(Error::Code::MAINARGSTYPE, "-help");
        }
    }
    catch(Plazza::Error& ex) {
        ex.what();
    }
    return (true);
}

static bool checkPizzaName(std::string pizzaName)
{
    if (pizzaName == "regina") 
        return (true);
    if (pizzaName == "margarita")
        return (true);
    if (pizzaName == "americana")
        return (true);
    if (pizzaName == "fantasia")
        return (true);
    return (false);
}

void Parsing::FillPizzaCmd(std::string command)
{
    _pizzaName = command.substr(0, command.find_first_of(" "));
    command = command.substr(command.find_first_of(" ") + 1, command.size());
    _pizzaSize = command.substr(0, command.find_first_of(" "));
    command = command.substr(command.find_first_of(" "), command.size());
    _pizzaNumber = command.substr(command.find_first_of(" ") + 1, command.size());
}

bool Parsing::CheckPizzaCmd(std::string command)
{
    FillPizzaCmd(command);
    if (std::regex_match(_pizzaName, std::regex("([A-Z][a-z])+"))) {
        throw Error(Error::Code::WRONGFORMAT, "this: TYPE SIZE NUMBER");
        return (false);
    }
    if (!checkPizzaName(_pizzaName)) {
        throw Error(Error::Code::UNDEFINEDPIZZA, "Pizza '" + _pizzaName + "' is undefined");
        return (false);
    }
    if (std::regex_match(_pizzaSize, std::regex("(\b[S]\b)|(\b[M]\b)|(\b[L]\b)|(\b[X][L]\b)|(\b[X][X][L]\b)"))) {
        throw Error(Error::Code::WRONGFORMAT, "this: TYPE SIZE NUMBER");
        return (false);
    }
    if (std::regex_match(_pizzaNumber, std::regex("(\b[x][0-9]+\b)"))) {
        throw Error(Error::Code::WRONGFORMAT, "this: TYPE SIZE NUMBER");
        return (false);
    }
    return (true);
}

bool Parsing::CheckCommand(std::string command)
{
    std::vector<std::string> pizzaCommands = split(command, ';');
    for (int i = 1; i < (int)pizzaCommands.size(); i++)
        pizzaCommands[i].erase(0, 1);
    for (int i = 0; i < (int)pizzaCommands.size(); i++) {
        if (std::regex_match(pizzaCommands[i], std::regex("([a-z]+)([ ])(([S])|([M])|([L])|([X][L])|([X][X][L]))([ ])([x][0-9]+)"))) {
            if (!CheckPizzaCmd(pizzaCommands[i]))
                return (false);
        } else {
            throw Error(Error::Code::UNDEFINEDCOMMAND, "the command '" + command + "' is undefined");
        }
    }
    return (true);
}

std::string Parsing::GetPizzaName() const
{
    return (_pizzaName);
}

std::string Parsing::GetPizzaSize() const
{
    return (_pizzaSize);
}

std::string Parsing::GetPizzaNumber() const
{
    return (_pizzaNumber);
}
