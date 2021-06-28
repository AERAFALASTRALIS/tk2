/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateOutput.hpp"

nts::GateOutput::GateOutput(Pin *output) : AGate(output) {}

nts::GateOutput::~GateOutput() {}

bool nts::GateOutput::preventLoop(AGate *gate, int pathLength) const
{
    return (false);
}

nts::Tristate nts::GateOutput::compute()
{
    if (!this->open)
    	return (nts::UNDEFINED);
    this->open = false;
    return (this->output1->getState());
}
