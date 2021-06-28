/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "GateBin4ToDec16.hpp"
#include "AComponent.hpp"

nts::GateBin4ToDec16::GateBin4ToDec16(Pin *outputZ, std::vector<Pin *> outputs, Pin *inhibit, Pin *inputA, Pin *inputB, Pin *inputC, Pin *inputD, Pin *strobe) : AGate(outputZ), outputs(outputs), inhibit(inhibit), inputA(inputA), inputB(inputB), inputC(inputC), inputD(inputD), strobe(strobe)
{
    if (this->inhibit)
        this->inhibit->setGate(this);
    if (this->inputA)
        this->inputA->setGate(this);
    if (this->inputB)
        this->inputB->setGate(this);
    if (this->inputC)
        this->inputC->setGate(this);
    if (this->inputD)
        this->inputD->setGate(this);
    if (this->strobe)
        this->strobe->setGate(this);
    for (auto it = this->outputs.begin();
         it != this->outputs.end(); ++it)
        (*it)->setGate(this);
}

nts::GateBin4ToDec16::~GateBin4ToDec16() {}

bool nts::GateBin4ToDec16::preventLoop(AGate *gate, int pathLength) const
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

nts::Tristate nts::GateBin4ToDec16::compute()
{
    nts::Tristate inhibit;
    nts::Tristate inputA;
    nts::Tristate inputB;
    nts::Tristate inputC;
    nts::Tristate inputD;
    nts::Tristate strobe;
    IComponent *linkedInhibit;
    IComponent *linkedA;
    IComponent *linkedB;
    IComponent *linkedC;
    IComponent *linkedD;
    IComponent *linkedStrobe;
    int	convertDec;

    if (!this->open)
        return (nts::UNDEFINED);
    this->open = false;
    linkedInhibit = this->inhibit->getLinked();
    linkedA = this->inputA->getLinked();
    linkedB = this->inputB->getLinked();
    linkedC = this->inputC->getLinked();
    linkedD = this->inputD->getLinked();
    linkedStrobe = this->strobe->getLinked();
    if (!linkedInhibit || !linkedA || !linkedB || !linkedC ||
        !linkedD || !linkedStrobe) {
        for (auto it = this->outputs.begin(); it != this->outputs.end();
             ++it)
            (*it)->setState(nts::UNDEFINED);
        return (nts::UNDEFINED);
    }
    inhibit = linkedInhibit->compute(this->inhibit->getPin_num());
    inputA = linkedA->compute(this->inputA->getPin_num());
    inputB = linkedB->compute(this->inputB->getPin_num());
    inputC = linkedC->compute(this->inputC->getPin_num());
    inputD = linkedD->compute(this->inputD->getPin_num());
    strobe = linkedStrobe->compute(this->strobe->getPin_num());
    this->inhibit->setState(inhibit);
    this->inputA->setState(inputA);
    this->inputB->setState(inputB);
    this->inputC->setState(inputC);
    this->inputD->setState(inputD);
    this->strobe->setState(strobe);
    convertDec = inputA + inputB * 2 + inputC * 4 + inputD * 8;
    for (auto it = this->outputs.begin(); it != this->outputs.end();
         ++it)
        (*it)->setState(nts::FALSE);
    if (inhibit == nts::UNDEFINED || strobe == nts::UNDEFINED ||
        inputA == nts::UNDEFINED || inputB == nts::UNDEFINED ||
        inputC == nts::UNDEFINED || inputD == nts::UNDEFINED ||
        strobe == nts::FALSE) {
        for (auto it = this->outputs.begin(); it != this->outputs.end();
             ++it)
            (*it)->setState(nts::UNDEFINED);
    }
    else if (!inhibit)
        this->outputs[convertDec]->setState(nts::TRUE);
    return (this->output1->getState());
}
