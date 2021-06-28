/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateFlipFlop.hpp"
#include "AComponent.hpp"

nts::GateFlipFlop::GateFlipFlop(Pin *output1, Pin *output2, Pin *clockPin, Pin *reset, Pin *data, Pin *set) : AGate(output1), clock(clockPin), reset(reset), data(data), set(set), output2(output2)
{
    if (this->output2)
        this->output2->setGate(this);
    if (this->clock)
    	this->clock->setGate(this);
    if (this->reset)
    	this->reset->setGate(this);
    if (this->data)
    	this->data->setGate(this);
    if (this->set)
    	this->set->setGate(this);
}

nts::GateFlipFlop::~GateFlipFlop() {}

bool nts::GateFlipFlop::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linked1;
    AComponent *linked2;
    Pin *input_link;

    linked1 = dynamic_cast<AComponent *>(this->output1->getLinked());
    linked2 = dynamic_cast<AComponent *>(this->output2->getLinked());
    if (pathLength && gate == this)
        return (true);
    if (linked1) {
        input_link = linked1->getPins()[this->output1->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    if (linked2) {
        input_link = linked2->getPins()[this->output2->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    return (false);
}

nts::Tristate nts::GateFlipFlop::compute()
{
    nts::Tristate clockPin;
    nts::Tristate reset;
    nts::Tristate data;
    nts::Tristate set;
    IComponent *linkedClock;
    IComponent *linkedReset;
    IComponent *linkedData;
    IComponent *linkedSet;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linkedClock = this->clock->getLinked();
    linkedReset = this->reset->getLinked();
    linkedData = this->data->getLinked();
    linkedSet = this->set->getLinked();
    if (!linkedClock || !linkedReset || !linkedData || !linkedSet) {
        this->output1->setState(nts::UNDEFINED);
        this->output2->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    clockPin = linkedClock->compute(this->clock->getPin_num());
    reset = linkedReset->compute(this->reset->getPin_num());
    data = linkedData->compute(this->data->getPin_num());
    set = linkedSet->compute(this->set->getPin_num());
    this->clock->setState(clockPin);
    this->reset->setState(reset);
    this->data->setState(data);
    this->set->setState(set);
    if (clockPin == nts::UNDEFINED || reset == nts::UNDEFINED ||
        data == nts::UNDEFINED || set == nts::UNDEFINED ) {
        this->output1->setState(nts::UNDEFINED);
        this->output2->setState(nts::UNDEFINED);
    } else if (reset && set) {
        this->output1->setState(nts::TRUE);
        this->output2->setState(nts::TRUE);
    } else if (set || (!set && !reset && data && !clockPin)) {
        this->output1->setState(nts::TRUE);
        this->output2->setState(nts::FALSE);
    } else if (reset || (!set && !reset && !data && !clockPin)) {
        this->output1->setState(nts::FALSE);
        this->output2->setState(nts::TRUE);
    }
    return (this->output1->getState());
}
