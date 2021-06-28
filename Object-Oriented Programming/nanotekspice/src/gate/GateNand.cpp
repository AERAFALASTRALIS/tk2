/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateNand.hpp"
#include "AComponent.hpp"

nts::GateNand::GateNand(Pin *output, Pin *input1, Pin *input2) : AGate(output), input1(input1), input2(input2)
{
    if (this->input1)
        this->input1->setGate(this);
    if (this->input2)
    	this->input2->setGate(this);
}

nts::GateNand::~GateNand()
{
}

bool nts::GateNand::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linked;
    Pin *input_link;

    linked = dynamic_cast<AComponent *>(this->output1->getLinked());
    if (pathLength && gate == this)
    	return (true);
    else if (linked) {
        input_link = linked->getPins()[this->output1->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    return (false);
}

nts::Tristate nts::GateNand::compute()
{
    nts::Tristate input1;
    nts::Tristate input2;
    IComponent *linked1;
    IComponent *linked2;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linked1 = this->input1->getLinked();
    linked2 = this->input2->getLinked();
    if (!linked1 || !linked2) {
        this->output1->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    input1 = linked1->compute(this->input1->getPin_num());
    input2 = linked2->compute(this->input2->getPin_num());
    this->input1->setState(input1);
    this->input2->setState(input2);
    if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED)
    	this->output1->setState(nts::UNDEFINED);
    else if (input1 && input2)
        this->output1->setState(nts::FALSE);
    else
    	this->output1->setState(nts::TRUE);
    return (this->output1->getState());
}
