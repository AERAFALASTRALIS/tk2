/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateSum.hpp"
#include "AComponent.hpp"

nts::GateSum::GateSum(Pin *output, Pin *input1, Pin *input2, Pin *carryIn, Pin *carryOut) : AGate(output), input1(input1), input2(input2), carryIn(carryIn), carryOut(carryOut)
{
    if (this->input1)
        this->input1->setGate(this);
    if (this->input2)
        this->input2->setGate(this);
    if (this->carryIn)
        this->carryIn->setGate(this);
    if (this->carryOut)
        this->carryOut->setGate(this);
}

nts::GateSum::~GateSum() {}

bool nts::GateSum::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linked;
    AComponent *linkedCarry;
    Pin *input_link;

    linked = dynamic_cast<AComponent *>(this->output1->getLinked());
    linkedCarry = dynamic_cast<AComponent *>(this->carryOut->getLinked());
    if (pathLength && gate == this)
    	return (true);
    if (linked) {
        input_link = linked->getPins()[this->output1->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    if (linkedCarry) {
        input_link = linkedCarry->getPins()[this->carryOut->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    return (false);
}

nts::Tristate nts::GateSum::compute()
{
    nts::Tristate input1;
    nts::Tristate input2;
    nts::Tristate carryIn;
    IComponent *linked1;
    IComponent *linked2;
    IComponent *linkedCarryIn;
    int sum;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linked1 = this->input1->getLinked();
    linked2 = this->input2->getLinked();
    linkedCarryIn = this->carryIn->getLinked();
    if (!linked1 || !linked2 || !linkedCarryIn) {
        this->output1->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    input1 = linked1->compute(this->input1->getPin_num());
    input2 = linked2->compute(this->input2->getPin_num());
    carryIn = linkedCarryIn->compute(this->carryIn->getPin_num());
    this->input1->setState(input1);
    this->input2->setState(input2);
    this->carryIn->setState(carryIn);
    sum = input1 + input2 + carryIn;
    if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED ||
        carryIn == nts::UNDEFINED) {
        this->carryOut->setState(nts::UNDEFINED);
        this->output1->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    this->carryOut->setState(sum % 2 == 0 ? nts::TRUE : nts::FALSE);
    this->output1->setState(sum % 2 != 0 ? nts::TRUE : nts::FALSE);
    return (this->output1->getState());
}
