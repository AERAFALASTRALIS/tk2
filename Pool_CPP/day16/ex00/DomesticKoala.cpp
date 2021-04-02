/*
** EPITECH PROJECT, 2021
** koala
** File description:
** koala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction& action) : _action(action), _theAct(256)
{
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(DomesticKoala const& koala) : _action(koala._action), _theAct(koala._theAct)
{
}

DomesticKoala& DomesticKoala::operator=(DomesticKoala const& koala)
{
    this->_action = koala._action;
    this->_theAct = koala._theAct;
    return (*this);
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions() const
{
    return (&this->_theAct);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    this->_theAct[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    this->_theAct[command] = NULL;
}

void DomesticKoala::doAction(unsigned char command, std::string const& param)
{
    methodPointer_t func = this->_theAct[command];
    if (func)
        (this->_action.*func)(param);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
    this->_action = action;
}
