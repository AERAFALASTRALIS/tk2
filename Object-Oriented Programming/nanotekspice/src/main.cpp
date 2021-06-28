/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <csignal>
#include <fstream>
#include "Parser.hpp"

sig_atomic_t signal_sigint = 0;

static std::vector<nts::IComponent *> _parseFile(std::string file)
{
    nts::Parser parser;
    std::ifstream infile(file);
    std::string line;
    while (std::getline(infile, line))
        parser.feed(line);
    nts::t_ast_node *root = parser.createTree();
    parser.parseTree(*root);
    return parser.getComponentVector();
}

static bool _compare_string_of_components(nts::AComponent *c1, nts::AComponent *c2)
{
    std::string s1 = c1->getName(), s2 = c2->getName();
    size_t len = std::max(s1.size(), s2.size()), i;

    for (i = 0; i < len; i++)
        if (s1[i] != s2[i])
            return s1[i] > s2[i];
    return i != s1.size();
}

static void _dislay(std::vector<nts::IComponent *> component_vector, size_t tick)
{
    std::cout << "tick: " << tick << std::endl;
    std::vector<nts::AComponent *> input_component;
    std::vector<nts::AComponent *> output_component;
    for (auto it = component_vector.begin(); it != component_vector.end();
         it++) {
        nts::Component_type type = static_cast<nts::AComponent *>(*it)->getType();
        if (type == nts::Component_type::BASIC_INPUT ||
            type == nts::Component_type::BASIC_CLOCK ||
            type == nts::Component_type::BASIC)
            input_component.push_back(static_cast<nts::AComponent *>(*it));
        else if (static_cast<nts::AComponent *>(*it)->getType() == nts::Component_type::BASIC_OUTPUT)
            output_component.push_back(static_cast<nts::Output *>(*it));
    }
    std::cout << "input(s):" << std::endl;
    sort(input_component.begin(), input_component.begin(), _compare_string_of_components);
    for (auto it = input_component.begin(); it != input_component.end();
         it++)
        (*it)->printState();
    std::cout << "output(s):" << std::endl;
    sort(output_component.begin(), output_component.begin(), _compare_string_of_components);
    for (auto it = output_component.begin(); it != output_component.end();
         it++)
        (*it)->printState();
}

static void _change_input(std::vector<nts::IComponent *> component_vector, std::string input, int state, std::string error)
{
    if (state != 0 && state != 1)
        throw std::invalid_argument(W_A + input + "=" + std::to_string(state));
    for (auto it = component_vector.begin(); it != component_vector.end();
         it++)
        if (static_cast<nts::AComponent *>(*it)->getName() == input)
            if (static_cast<nts::AComponent *>(*it)->getType() == nts::Component_type::BASIC_INPUT || static_cast<nts::AComponent *>(*it)->getType() == nts::Component_type::BASIC_CLOCK) {
                static_cast<nts::Input *>(*it)->setState(state ? nts::Tristate::TRUE : nts::Tristate::FALSE);
                return;
            }
    throw std::invalid_argument(error + input);
}

static void _simulate(std::vector<nts::IComponent *> component_vector)
{
    for (auto it = component_vector.begin(); it != component_vector.end();
         it++)
        if (static_cast<nts::AComponent *>(*it)->getType() == nts::Component_type::BASIC_OUTPUT)
            (*it)->compute(1);
    for (auto it = component_vector.begin(); it != component_vector.end();
         it++)
  	static_cast<nts::AComponent *>(*it)->openGates();
    for (auto it = component_vector.begin(); it != component_vector.end();
         it++)
        if (static_cast<nts::AComponent *>(*it)->getType() == nts::Component_type::BASIC_CLOCK)
            static_cast<nts::Clock *>(*it)->tick();
}

static void _loop(std::vector<nts::IComponent *> component_vector)
{
    signal_sigint = 0;
    while (!signal_sigint)
        _simulate(component_vector);
}

static void _dump(std::vector<nts::IComponent *> component_vector)
{
    for (auto it = component_vector.begin(); it != component_vector.end();
         it++)
        (*it)->dump();
}

static void _switch_signal_sigint(int param)
{
    signal_sigint = 1;
}

static void _can_change_input(std::vector<nts::IComponent *> component_vector, std::string line, std::string error)
{
    size_t index = line.find('=');
    if (index > 0 && index < line.length())
        _change_input(component_vector, line.substr(0, index), std::stoi(line.substr(index + 1)), error);
    else if (index == std::string::npos && line != "")
        std::cerr << "Unknown command" << std::endl;
    else
        throw std::invalid_argument(error + line);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 1;
    signal(SIGINT, _switch_signal_sigint);
    try
    {
        std::vector<nts::IComponent *> component_vector = _parseFile(av[1]);
        for (int i = 2; i < ac; i++)
            _can_change_input(component_vector, av[i], UI_A);
        std::string line;
        size_t tick = 0;
        std::cout << "> ";
        while (std::getline(std::cin, line)) {
            if (line == "exit")
                return 0;
            else if (line == "display")
                _dislay(component_vector, tick);
            else if (line == "simulate") {
                _simulate(component_vector);
                tick += 1;
            } else if (line == "loop")
                _loop(component_vector);
            else if (line == "dump")
                _dump(component_vector);
            else
                _can_change_input(component_vector, line, UI_L);
            std::cout << "> ";
        }
    }
    catch (std::invalid_argument const &err) {
        std::cerr << err.what()  << std::endl;
        return 84;
    }
    catch (std::out_of_range const &err) {
        std::cerr << err.what()  << std::endl;
        return 84;
    }
    return 0;
}
