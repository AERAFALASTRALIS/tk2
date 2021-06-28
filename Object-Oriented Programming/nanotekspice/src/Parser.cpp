/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser
*/

#include "Parser.hpp"

void nts::Parser::feed(std::string const& input)
{
    size_t idx = input.find_first_of("#");

    if (idx == std::string::npos) {
        if (input.size())
	    _file.push_back(input);
    } else {
        if (idx)
	    _file.push_back(input.substr(idx));
    }
}

std::vector<nts::IComponent *> nts::Parser::getComponentVector(void) const
{
    return _component_vector;
}

nts::IComponent *nts::Parser::createComponent(const std::string &type, const std::string &value)
{
    nts::cmpt_mthd_ptr const createComponentFuncPtr[COMPONENT_PTR_SIZE] = 
        {
            &Parser::createInput,
            &Parser::createOutput,
            &Parser::createClock,
            &Parser::createTrue,
            &Parser::createFalse,
            &Parser::create2716,
            &Parser::create4001,
            &Parser::create4008,
            &Parser::create4011,
            &Parser::create4013,
            &Parser::create4017,
            &Parser::create4030,
            &Parser::create4040,
            &Parser::create4069,
            &Parser::create4071,
            &Parser::create4081,
            &Parser::create4094,
            &Parser::create4514,
            &Parser::create4801,
        };

    std::string const createComponentType[COMPONENT_PTR_SIZE] =
        {
            "input",
            "output",
            "clock",
            "true",
            "false",
            "2716",
            "4001",
            "4008",
            "4011",
            "4013",
            "4017",
            "4030",
            "4040",
            "4069",
            "4071",
            "4081",
            "4094",
            "4514",
            "4801"
        };
    for (int i = 0; i < COMPONENT_PTR_SIZE; i++)
        if (createComponentType[i] == type)
            return (this->*createComponentFuncPtr[i])(value);
    return nullptr;
}

nts::IComponent	*nts::Parser::getComponentFromName(std::string name)
{
    for (auto it = _component_vector.begin(); it != _component_vector.end();
         it++)
        if (static_cast<nts::AComponent *>(*it)->getName() == name)
            return *it;
    return nullptr;
}

void nts::Parser::parseTree(nts::t_ast_node& root)
{
    nts::t_ast_node *chipsets = (*root.children)[0], *links = (*root.children)[1];
    _component_vector.clear();

    for (auto it = chipsets->children->begin(); it < chipsets->children->end();
         it++) {
        nts::IComponent *component = createComponent((*(*it)->children)[0]->lexeme, (*(*it)->children)[1]->lexeme);
        if (component == nullptr)
            throw std::invalid_argument(TC_T + (*(*it)->children)[0]->lexeme + ") is unknown");
        for (auto it2 = _component_vector.begin(); it2 != _component_vector.end();
             it2++)
	    if (static_cast<nts::AComponent *>(*it2)->getName() == (*(*it)->children)[1]->lexeme)
                throw std::invalid_argument(SC_N + (*(*it)->children)[1]->lexeme);
        _component_vector.push_back(component);
    }

    for (auto it = links->children->begin(); it < links->children->end();
         it++) {
        std::string namePin1 = (*(*it)->children)[0]->lexeme, namePin2 = (*(*it)->children)[1]->lexeme;
        size_t indexPin1 = namePin1.find(':'), indexPin2 = namePin2.find(':');
        if (indexPin1 == std::string::npos ||
            indexPin2 == std::string::npos)
	    throw std::invalid_argument(TC_E + (*it)->lexeme);
        nts::IComponent *component1 = getComponentFromName(namePin1.substr(0, indexPin1)), *component2 = getComponentFromName(namePin2.substr(0, indexPin2));
        if (component1 == nullptr || component2 == nullptr)
            throw std::invalid_argument("Unknow component name: " + (component1 == nullptr ? namePin1.substr(0, indexPin1) : namePin2.substr(0, indexPin2)));
        component1->setLink(std::stoi(namePin1.substr(indexPin1 + 1)), *component2, std::stoi(namePin2.substr(indexPin2 + 1)));
    }
}

nts::t_ast_node *nts::Parser::createTreeSection(std::string section) const
{
    std::vector<nts::t_ast_node *> *vec = new std::vector<nts::t_ast_node *>();
    auto it = _file.begin();
    for (; it < _file.end() && it->find("." + section + "s:") != 0; it++);
    if (it != _file.end())
        it++;
    for (; it < _file.end() && it->find(".") != 0; it++) {
        nts::t_ast_node *component = new nts::t_ast_node(), *string = new nts::t_ast_node();
        std::vector<nts::t_ast_node *> *section_element_vec = new std::vector<nts::t_ast_node *>();
        std::istringstream iss(*it);
        iss >> component->lexeme;
        component->type = nts::ASTNodeType::COMPONENT;
        component->value = "component";

        if (iss.peek() == EOF)
	    throw std::invalid_argument(TC_E + *it);
        iss >> string->lexeme;
        string->type = nts::ASTNodeType::STRING;
        string->value = "string";
        section_element_vec->push_back(component);
        section_element_vec->push_back(string);
        nts::t_ast_node *section_element = new nts::t_ast_node(section_element_vec);
        section_element->lexeme = *it;
        section_element->type = nts::ASTNodeType::COMPONENT;
        section_element->value = section;
        vec->push_back(section_element);
    }
    nts::t_ast_node *section_elements = new nts::t_ast_node(vec);
    section_elements->lexeme = "";
    section_elements->type = nts::ASTNodeType::SECTION;
    section_elements->value = section + "s";
    return section_elements;
}

nts::t_ast_node *nts::Parser::createTree(void) {
    std::vector<nts::t_ast_node *> *vec = new std::vector<nts::t_ast_node *>();
    nts::t_ast_node *chipsets = createTreeSection("chipset"), *links = createTreeSection("link");

    if (!chipsets->children->size() || !links->children->size())
        throw std::invalid_argument("Incomplete section");
    vec->push_back(chipsets);
    vec->push_back(links);
    nts::t_ast_node *ret = new nts::t_ast_node(vec);
    ret->lexeme = "";
    ret->type = nts::ASTNodeType::DEFAULT;
    ret->value = "tree";
    return ret;
}
