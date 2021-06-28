/*
** EPITECH PROJECT, 2021
** iconfig
** File description:
** iconfig
*/

#ifndef ICOOKING_HPP_
#define ICOOKING_HPP_

class ICooking {
public:
    virtual ~ICooking() = default;
    virtual void cook(std::string &name) = 0;
};

#endif /* !ICOOKING_HPP_ */
