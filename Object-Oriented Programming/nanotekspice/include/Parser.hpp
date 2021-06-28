/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#define UI_A "Unknown input specified by argument :"
#define UI_L "Unknown input specified by command line :"
#define W_A "Wrong assignement: "
#define TC_T "The component type ("
#define SC_N "Several components share the same name: "
#define TC_E "The circuit file includes one or several lexical errors or syntactic errors: "


#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <sstream>

#include "IComponent.hpp"

#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"

#include "2716.hpp"
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4013.hpp"
#include "4017.hpp"
#include "4030.hpp"
#include "4040.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "4094.hpp"
#include "4514.hpp"
#include "4801.hpp"

#define CREATE_COMPONENT_PROTOTYPE(x) IComponent *create##x(std::string const &value) const { return new C##x(value); }

#define CREATE_BASIC_PROTOTYPE(x) IComponent *create##x(std::string const &value) const { return new x(value); }

#define COMPONENT_PTR_SIZE 20

namespace nts
{
    enum class ASTNodeType : int
    {
        DEFAULT = -1,
        NEWLINE = 0,
        SECTION,
        COMPONENT,
        LINK,
        LINK_END,
        STRING
    };

    typedef struct s_ast_node
    {
        s_ast_node(std::vector<struct s_ast_node*> *children=nullptr)
            : children(children) {}
        std::string lexeme;
        ASTNodeType type;
        std::string value;
        std::vector<struct s_ast_node*> *children;
    } t_ast_node;

    struct IParser
    {
        virtual void feed(std::string const& input) = 0;
        virtual void parseTree(t_ast_node& root) = 0;
        virtual t_ast_node *createTree(void) = 0;
        virtual ~IParser(void) {}
    };

    class Parser : public IParser
    {
    public:
        virtual void feed(std::string const& input);
        virtual void parseTree(t_ast_node& root);
        virtual t_ast_node *createTree(void);
        IComponent *createComponent(const std::string &type, const std::string &value);
        std::vector<nts::IComponent *> getComponentVector(void) const;
        Parser(void) {}
    private:
        t_ast_node *createTreeSection(std::string section) const;
        IComponent *getComponentFromName(std::string name);
        std::vector<std::string> _file;
        std::vector<nts::IComponent *> _component_vector;

        CREATE_BASIC_PROTOTYPE(Input);
        CREATE_BASIC_PROTOTYPE(Output);
        CREATE_BASIC_PROTOTYPE(Clock);
        CREATE_BASIC_PROTOTYPE(True);
        CREATE_BASIC_PROTOTYPE(False);
        CREATE_COMPONENT_PROTOTYPE(2716);
        CREATE_COMPONENT_PROTOTYPE(4001);
        CREATE_COMPONENT_PROTOTYPE(4008);
        CREATE_COMPONENT_PROTOTYPE(4011);
        CREATE_COMPONENT_PROTOTYPE(4013);
        CREATE_COMPONENT_PROTOTYPE(4017);
        CREATE_COMPONENT_PROTOTYPE(4030);
        CREATE_COMPONENT_PROTOTYPE(4040);
        CREATE_COMPONENT_PROTOTYPE(4069);
        CREATE_COMPONENT_PROTOTYPE(4071);
        CREATE_COMPONENT_PROTOTYPE(4081);
        CREATE_COMPONENT_PROTOTYPE(4094);
        CREATE_COMPONENT_PROTOTYPE(4514);
        CREATE_COMPONENT_PROTOTYPE(4801);
    };

    typedef IComponent *(Parser::*cmpt_mthd_ptr)(std::string const &value) const;
}

#endif
