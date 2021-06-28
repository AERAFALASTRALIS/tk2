/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateNot.hpp"
#include "AComponent.hpp"

nts::GateNot::GateNot(Pin *output, Pin *input1) : AGate(output), input1(input1)
{
    if (this->input1)
        this->input1->setGate(this);
}

nts::GateNot::~GateNot() {}

bool nts::GateNot::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linked;
    Pin *input_link;

    linked = dynamic_cast<AComponent *>(this->output1->getLinked());
    if (pathLength && gate == this)
    	return (true);
    if (linked) {
        input_link = linked->getPins()[this->output1->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    return (false);
}

nts::Tristate nts::GateNot::compute()
{
    nts::Tristate input1;
    IComponent *linked1;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linked1 = this->input1->getLinked();
    if (!linked1) {
        this->output1->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    input1 = linked1->compute(this->input1->getPin_num());
    this->input1->setState(input1);
    if (input1 == nts::UNDEFINED)
    	this->output1->setState(nts::UNDEFINED);
    else if (!input1)
        this->output1->setState(nts::TRUE);
    else
    	this->output1->setState(nts::FALSE);
    return (this->output1->getState());
}
