/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateBin3ToDec8.hpp"
#include "AComponent.hpp"

nts::GateBin3ToDec8::GateBin3ToDec8(Pin *outputZ, std::vector<Pin *> outputs, Pin *inhibit, Pin *inputA, Pin *inputB, Pin *inputC, Pin *inputOE) : AGate(outputZ), outputs(outputs), inhibit(inhibit), inputA(inputA), inputB(inputB), inputC(inputC), inputOE(inputOE)
{
    if (this->inhibit)
        this->inhibit->setGate(this);
    if (this->inputA)
        this->inputA->setGate(this);
    if (this->inputB)
        this->inputB->setGate(this);
    if (this->inputC)
        this->inputC->setGate(this);
    if (this->inputOE)
        this->inputOE->setGate(this);
    for (auto it = this->outputs.begin(); it != this->outputs.end(); ++it)
        (*it)->setGate(this);
}

nts::GateBin3ToDec8::~GateBin3ToDec8() {}

bool nts::GateBin3ToDec8::preventLoop(AGate *gate, int pathLength) const
{
    AComponent *linkedOutput;
    AComponent *linkedZ;
    Pin	*input_link;

    linkedZ = dynamic_cast<AComponent *>(this->output1->getLinked());
    if (pathLength && gate == this)
    	return (true);
    if (linkedZ) {
        input_link = linkedZ->getPins()[this->output1->getPin_num() - 1];
        if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            return (true);
    }
    for (auto it = this->outputs.begin(); it != this->outputs.end(); ++it)
    {
        linkedOutput = dynamic_cast<AComponent *>((*it)->getLinked());
        if (linkedOutput) {
            input_link = linkedOutput->getPins()[(*it)->getPin_num() - 1];
            if (input_link->getGate()->preventLoop(gate, pathLength + 1))
            	return (true);
        }
    }
    return (false);
}

nts::Tristate nts::GateBin3ToDec8::compute()
{
    nts::Tristate inhibit;
    nts::Tristate inputA;
    nts::Tristate inputB;
    nts::Tristate inputC;
    nts::Tristate inputOE;
    IComponent *linkedInhibit;
    IComponent *linkedA;
    IComponent *linkedB;
    IComponent *linkedC;
    IComponent *linkedOE;
    int	convertDec;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linkedInhibit = this->inhibit->getLinked();
    linkedA = this->inputA->getLinked();
    linkedB = this->inputB->getLinked();
    linkedC = this->inputC->getLinked();
    linkedOE = this->inputOE->getLinked();
    if (!linkedInhibit || !linkedA || !linkedB || !linkedC || !linkedOE)
    {
        this->output1->setState(nts::UNDEFINED);
        for (auto it = this->outputs.begin(); it != this->outputs.end(); ++it)
            (*it)->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    inhibit = linkedInhibit->compute(this->inhibit->getPin_num());
    inputA = linkedA->compute(this->inputA->getPin_num());
    inputB = linkedB->compute(this->inputB->getPin_num());
    inputC = linkedC->compute(this->inputC->getPin_num());
    inputOE = linkedOE->compute(this->inputOE->getPin_num());
    this->inhibit->setState(inhibit);
    this->inputA->setState(inputA);
    this->inputB->setState(inputB);
    this->inputC->setState(inputC);
    this->inputOE->setState(inputOE);
    this->output1->setState(nts::UNDEFINED);
    convertDec = inputA + inputB * 2 + inputC * 4;
    for (auto it = this->outputs.begin(); it != this->outputs.end(); ++it)
        (*it)->setState(nts::FALSE);
    if (inhibit == nts::UNDEFINED || inputOE == nts::UNDEFINED ||
        inputA == nts::UNDEFINED || inputB == nts::UNDEFINED ||
        inputC == nts::UNDEFINED) {
        this->output1->setState(nts::UNDEFINED);
        for (auto it = this->outputs.begin(); it != this->outputs.end(); ++it)
            (*it)->setState(nts::UNDEFINED);
    } else if (inputOE)
	    this->output1->setState(nts::TRUE);
    else if (inhibit)
    	this->output1->setState(nts::FALSE);
    else
    	this->outputs[convertDec]->setState(nts::TRUE);
    return (this->output1->getState());
}
