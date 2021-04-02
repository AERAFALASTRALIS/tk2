/*
** EPITECH PROJECT, 2021
** skat
** File description:
** skat
*/

#ifndef SKAT_H_
#define SKAT_H_

#include <string>
#include <iostream>

class Skat
{
public:
    Skat(std::string const& name, int stimPaks);
    ~Skat();
    int& stimPaks();
    const std::string& name();
    void shareStimPaks(int number, int& stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
private :
	std::string const& _name;
    int _stimPaks;
    
};

#endif
