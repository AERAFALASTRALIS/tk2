/*
** EPITECH PROJECT, 2021
** koala
** File description:
** koala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "KoalaAction.hpp"

class DomesticKoala {
public:
    DomesticKoala(KoalaAction&);
    DomesticKoala(const DomesticKoala&);
    ~DomesticKoala();
    DomesticKoala& operator=(const DomesticKoala&);
    typedef void (KoalaAction::*methodPointer_t)(std::string const&);
    const std::vector<methodPointer_t> *getActions() const;
    void learnAction(unsigned char command, methodPointer_t action);
    void unlearnAction(unsigned char command);
    void doAction(unsigned char command, const std::string& param);
    void setKoalaAction(KoalaAction&);
private:
    KoalaAction _action;
    std::vector<methodPointer_t> _theAct;
};

#endif
