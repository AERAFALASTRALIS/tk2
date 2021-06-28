/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateInput.hpp"

nts::GateInput::GateInput(Pin *output, Pin *input1) : AGate(output), input1(input1)
{
    if (this->input1)
        this->input1->setGate(this);
}

nts::GateInput::~GateInput() {}

bool nts::GateInput::preventLoop(AGate *gate, int pathLength) const
{
    return (false);
}

nts::Tristate nts::GateInput::compute()
{
    nts::Tristate input1;
    IComponent *linked1;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linked1 = this->input1->getLinked();
    if (!linked1)
        return (nts::UNDEFINED);
    input1 = linked1->compute(this->input1->getPin_num());
    this->input1->setState(input1);
    return (input1);
}
