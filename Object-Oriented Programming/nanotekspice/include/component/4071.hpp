/*
** EPITECH PROJECT, 2021
** 4071
** File description:
** 4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "AComponent.hpp"

namespace nts
{
  class C4071 : public nts::AComponent
  {
  public:
    C4071(std::string = "4071");
    ~C4071();

    void dump(void) const;
    std::vector<nts::Pin *>	getPins() const;
    void openGates();

    private:
      std::vector<AGate *>gates;
  };
}

#endif
