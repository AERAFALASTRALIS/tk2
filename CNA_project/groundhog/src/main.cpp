/*
** EPITECH PROJECT, 2020
** Project [WSL: Ubuntu-20.04]
** File description:
** main.cpp
*/

#include "../class/hog.hpp"

void help(void)
{
    std::cout << "SYNOPSIS\n\t./groundhog period\n\nDescription\n\tperiod\tthe number of days defining a period" << std::endl;
}

int doTheHog(int period)
{
    hog homies(period);
    std::string str;
    char *p;
    double aze = 0;

    for (int i = 0; 42; i++){
        std::getline(std::cin, str);
        if (!str.compare("STOP"))
            break;
        aze = strtod(str.data(), &p);
        if (std::cin.eof() || str.empty() || *p)
            return 84;
        homies.fillTempV2(aze);

        if (homies.geV2Sisze() > period){
            homies.DoMeG();
            homies.DoMeR();
        }
        if (homies.geV2Sisze() >= period)
            homies.DoMeS();
        homies.display();

    if (homies.geV2Sisze() < period)
        return 84;
    // The programm will print abnormal temp before exiting
    homies.printWeird();
    return 0;
}

int main(int ac, char **av)
{
    std::string str;
    int period = 0;
    switch (ac){
    case 1:
        return 84;
    case 2:
        str = av[1];
        if (!str.compare("-h") || !str.compare("--help")){
            help();
            return 0;
        }else{
            return (period = atoi(av[1])) ? doTheHog(period) : 84;
        }
    default:
        return 84;
    }
}
