/*
** EPITECH PROJECT, 2021
** acomponent
** File description:
** acomponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(std::string name, nts::Component_type type) : name(name), type(type) {}

nts::Tristate nts::AComponent::compute(size_t pin)
{
    if (!pin || pin > this->pins.size())
    	return (nts::UNDEFINED);
    else if (this->pins[pin - 1]->getType() == nts::INPUT) {
        if (this->pins[pin - 1]->getLinked()) {
            this->pins[pin - 1]->setState(
                this->pins[pin - 1]->getLinked()->compute(
                    this->pins[pin - 1]->getPin_num()));
        }
        return (this->pins[pin - 1]->getState());
    } else if (this->pins[pin - 1]->getType() == nts::OUTPUT &&
               this->pins[pin - 1]->getGate()) {
        this->pins[pin - 1]->getGate()->compute();
        return (this->pins[pin - 1]->getState());
    }
    return (nts::UNDEFINED);
}

void nts::AComponent::simulate(std::size_t tick) {}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::vector<nts::Pin *> targetPins;
    AGate *targetGate;
    AGate *thisGate;
    targetPins = dynamic_cast<AComponent&>(other).getPins();

    if (!pin || !otherPin)
        throw std::invalid_argument("The pin 0 doesn't exist");
    else if (pin > this->pins.size())
    	throw std::invalid_argument(TC_P);
    else if (this->pins[pin - 1]->getType() == nts::OTHER)
    	throw std::invalid_argument(TP_I);
    else if (otherPin > targetPins.size())
        throw std::invalid_argument(TC_X);
    else if (this->pins[pin - 1]->getType() ==
             targetPins[otherPin - 1]->getType())
        throw std::invalid_argument(CL_T);
    else if (targetPins[otherPin - 1]->getType() == nts::OTHER)
    	throw std::invalid_argument(TP_O);
    this->pins[pin - 1]->setLinked(&other);
    this->pins[pin - 1]->setPin_num(otherPin);
    if (this->pins[pin - 1]->getType() == nts::INPUT)
        this->pins[pin - 1]->setState(
    	    targetPins[otherPin - 1]->getState());
    else
        targetPins[otherPin - 1]->setState(
            this->pins[pin - 1]->getState());
    targetPins[otherPin - 1]->setLinked(this);
    targetPins[otherPin - 1]->setPin_num(pin);
    targetGate = targetPins[otherPin - 1]->getGate();
    thisGate = this->pins[pin - 1]->getGate();
    if (this->pins[pin - 1]->getType() == nts::OUTPUT &&
    	thisGate->preventLoop(thisGate, 0))
        throw std::invalid_argument(TL_L);
    else if (targetPins[otherPin - 1]->getType() == nts::OUTPUT &&
             targetGate->preventLoop(targetGate, 0))
        throw std::invalid_argument(TL_L);
}

void nts::AComponent::printState() const
{
    nts::Tristate const state = this->pins[0]->getState();
    std::cout << "  " << this->name << ": " << (state == nts::Tristate::UNDEFINED ? "U" : std::to_string(state)) << std::endl;
}

std::vector<nts::Pin *>	nts::AComponent::getPins() const
{
    return (this->pins);
}

void nts::AComponent::dump() const
{
    int pin_num;
    pin_num = 1;
    for (std::vector<nts::Pin *>::const_iterator it = this->pins.begin();
         it != this->pins.end(); ++it) {
        if ((*it)->getType() != nts::OTHER)
            std::cout << pin_num << ": " << (*it)->getState() << std::endl;
        pin_num += 1;
    }
}

std::string nts::AComponent::getName() const
{
    return (this->name);
}

nts::Component_type nts::AComponent::getType() const
{
    return (this->type);
}
