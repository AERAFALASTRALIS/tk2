/*
** EPITECH PROJECT, 2021
** regina
** File description:
** regina
*/

#include "Pizza.hpp"

using Plazza::Pizza;
using Plazza::Regina;

Regina::Regina(PizzaSize size, double cookingMultiplier) : Pizza(Pizza::Regina, size, cookingMultiplier)
{
    _name = "Regina";
    _ingredient.push_back(Doe);
    _ingredient.push_back(Tomato);
    _ingredient.push_back(Gruyere);
    _cookingTime = cookingMultiplier;
}

Regina::~Regina()
{
}

Plazza::Pizza *Regina::newRegina(PizzaSize size, double cookingMultiplier)
{
    return new Regina(size, cookingMultiplier);
}
