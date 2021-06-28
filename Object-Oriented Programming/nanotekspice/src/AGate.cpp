/*
** EPITECH PROJECT, 2021
** agate
** File description:
** agate
*/

#include "AGate.hpp"

nts::AGate::AGate(Pin *output1) : output1(output1), open(true)
{
    if (this->output1)
        this->output1->setGate(this);
}

void nts::AGate::setOutput(Pin *output1)
{
    this->output1 = output1;
}

void nts::AGate::toggle()
{
    this->open = true;
}
