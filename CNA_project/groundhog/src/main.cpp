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
    // double tmp = 0;
    std::string str;
    for (int i = 0; str.compare("STOP"); i++){
        std::cin >> str;
        // if std::stof(str) fail:
        // exemple - stof("aze")
        // error catched
        try{
            // if crtl+D pressed exit
            if (std::cin.eof())
                break;
            homies.fillTempV2(std::stof(str));
            

            if (homies.geV2Sisze() > period){
                homies.DoMeG();
                homies.DoMeR();
                // homies.removeFront();
            }
            if (homies.geV2Sisze() >= period){
                homies.DoMeS();
            }
            homies.display();


            // if (i <= (period - 1)){
            //     homies.addtmp(tmp);
            // }
            // if (i && i <= period)
            //     homies.addlistcalcul(tmp);
            
            
            // // We wait for the period argument
            // if (i > (period - 1)){
            //     if (i > period){
            //         homies.addtmp(homies.getLast());
            //         homies.addlistcalcul(tmp);
            //     }
            //     g = homies.DoMeG();
            //     r = homies.DoMeR();
            //     s = homies.DoMeS();
            //     homies.removeFront();
            // }
            // std::cout << "g=" << (g ? std::to_string(g) : "nan") << '\t';
            
        }
        catch(const std::invalid_argument& e)
        {
            // Error catched
        }  
    }
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