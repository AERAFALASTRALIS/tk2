/*
** EPITECH PROJECT, 2021
** logger
** File description:
** logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "AComponent.hpp"

namespace nts
{
  class Logger : public nts::AComponent
  {
  public:
    Logger(std::string = "Logger");
    ~Logger();

    void dump(void) const;
    std::vector<nts::Pin *>	getPins() const;
    void openGates();

    private:
      std::vector<AGate *>gates;
  };
}

#endif
