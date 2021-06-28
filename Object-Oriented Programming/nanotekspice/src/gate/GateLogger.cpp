/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateLogger.hpp"
#include "AComponent.hpp"

nts::GateLogger::GateLogger(std::vector<Pin *>bits, Pin *clock, Pin *inhibit)
{
    if (this->clock)
        this->clock->setGate(this);
    if (this->inhibit)
        this->inhibit->setGate(this);
    for (auto it = this->bits.begin(); it != this->bits.end(); ++it)
        (*it)->setGate(this);
}

nts::GateLogger::~GateLogger() {}

bool nts::GateLogger::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linkedZ;
    Pin *input_link;

    linkedZ = dynamic_cast<AComponent *>(this->output1->getLinked());
    if (pathLength && gate == this)
    	return (true);
    if (linkedZ) {
        input_link = linkedZ->getPins()[this->output1->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    return (false);
}

nts::Tristate nts::GateLogger::compute()
{
    nts::Tristate inhibit;
    nts::Tristate clock;
    IComponent *linkedInhibit;
    IComponent *linkedClock;
    char c = 0;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    for (auto it = this->bits.begin(); it != this->bits.end(); ++it) {
        IComponent *b = (*it)->getLinked();
        if (!b)
            return nts::UNDEFINED;
        c <<= 1;
        nts::Tristate t = b->compute((*it)->getPin_num());
        if (t == nts::UNDEFINED)
            return nts::UNDEFINED;
        c += t;
        (*it)->setState(t);
    }
    linkedInhibit = this->inhibit->getLinked();
    linkedClock = this->clock->getLinked();
    if (!linkedInhibit || !linkedClock)
        return (nts::UNDEFINED);
    inhibit = linkedInhibit->compute(this->inhibit->getPin_num());
    clock = linkedClock->compute(this->clock->getPin_num());
    this->inhibit->setState(inhibit);
    this->clock->setState(clock);
    if (inhibit == nts::FALSE && clock == nts::TRUE) {
        std::ofstream logFile("./log.bin", std::ios::out | std::ios::binary | std::ios::app);
        logFile << c;
    }
    return nts::UNDEFINED;
}
