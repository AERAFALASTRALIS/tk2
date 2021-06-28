/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateCounter.hpp"
#include "AComponent.hpp"

nts::GateCounter::GateCounter(Pin *output, std::vector<Pin *> outputs, Pin *clock, Pin *reset) : AGate(output), outputs(outputs), clock(clock), reset(reset)
{
    if (this->clock)
        this->clock->setGate(this);
    if (this->reset)
        this->reset->setGate(this);
    for (auto it = this->outputs.begin(); it != this->outputs.end(); ++it)
        (*it)->setGate(this);
}

nts::GateCounter::~GateCounter() {}

bool nts::GateCounter::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linkedOutput;
    Pin *input_link;

    if (pathLength && gate == this)
    	return (true);
    for (auto it = this->outputs.begin(); it != this->outputs.end();
         ++it) {
        linkedOutput = dynamic_cast<AComponent *>((*it)->getLinked());
        if (linkedOutput) {
            input_link = linkedOutput->getPins()[(*it)->getPin_num() - 1];
            if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            	return (true);
        }
    }
    return (false);
}

nts::Tristate nts::GateCounter::compute()
{
    nts::Tristate clockPin;
    nts::Tristate reset;
    IComponent *linkedClock;
    IComponent *linkedReset;
    bool undef;
    bool setNext;
    bool allDown;

    if (!this->open)
    	return (nts::UNDEFINED);
    this->open = false;
    linkedClock = this->clock->getLinked();
    linkedReset = this->reset->getLinked();
    if (!linkedClock || !linkedReset) {
        for (auto it = this->outputs.begin(); it != this->outputs.end();
             ++it)
            (*it)->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    clockPin = linkedClock->compute(this->clock->getPin_num());
    reset = linkedReset->compute(this->reset->getPin_num());
    this->clock->setState(clockPin);
    this->reset->setState(reset);
    undef = false;
    for (auto it = this->outputs.begin(); it != this->outputs.end();
         ++it)
        if ((*it)->getState() == nts::UNDEFINED)
            undef = true;
    if (clockPin == nts::UNDEFINED || reset == nts::UNDEFINED ||
        (undef && reset != nts::TRUE)) {
        for (auto it = this->outputs.begin(); it != this->outputs.end();
             ++it)
            (*it)->setState(nts::UNDEFINED);
    } else if (reset) {
        for (auto it = this->outputs.begin(); it != this->outputs.end();
             ++it)
            (*it)->setState(nts::FALSE);
    } else if (clockPin) {
        setNext = false;
        allDown = true;
        for (auto it = this->outputs.begin(); it != this->outputs.end();
             ++it) {
            if (setNext) {
                (*it)->setState(nts::TRUE);
                setNext = false;
            } else if ((*it)->getState() == nts::TRUE) {
                (*it)->setState(nts::FALSE);
            	setNext = true;
                allDown = false;
            }
        }
        if (setNext || allDown)
            this->output1->setState(nts::TRUE);
    }
    return (this->output1->getState());
}
