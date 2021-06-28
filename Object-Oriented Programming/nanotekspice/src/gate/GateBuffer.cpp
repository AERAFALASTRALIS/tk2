/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateBuffer.hpp"
#include "AComponent.hpp"

nts::GateBuffer::GateBuffer(Pin *output, Pin *input1, Pin *disableInput) : AGate(output), input1(input1), disableInput(disableInput)
{
    if (this->input1)
        this->input1->setGate(this);
    if (this->disableInput)
        this->disableInput->setGate(this);
}

nts::GateBuffer::~GateBuffer() {}

bool nts::GateBuffer::preventLoop(AGate *gate, int pathLength) const
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

nts::Tristate nts::GateBuffer::compute()
{
    nts::Tristate input1;
    nts::Tristate disableInput;
    IComponent *linked1;
    IComponent *linkedDisableInput;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linked1 = this->input1->getLinked();
    linkedDisableInput = this->disableInput->getLinked();
    if (!linked1 || !linkedDisableInput) {
        this->output1->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    input1 = linked1->compute(this->input1->getPin_num());
    disableInput = linkedDisableInput->compute(this->disableInput->getPin_num());
    this->input1->setState(input1);
    this->disableInput->setState(disableInput);
    if (input1 == nts::UNDEFINED || disableInput != nts::FALSE)
    	this->output1->setState(nts::UNDEFINED);
    else
        this->output1->setState(input1);
    return (this->output1->getState());
}
