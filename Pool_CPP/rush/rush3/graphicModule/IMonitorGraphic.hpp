/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** IMonitorGraphic.hpp
*/

#ifndef IMONITORGRAPHIC_HPP_
#define IMONITORGRAPHIC_HPP_

#include "IMonitorDisplay.hpp"

namespace sf {
    class RenderWindow;
};

class IMonitorGraphic : public IMonitorDisplay {
public:
    virtual ~IMonitorGraphic() {}
    virtual void setTarget(sf::RenderWindow *target) = 0;
};

#endif /* IMONITORGRAPHIC_HPP_ */
