/*
** EPITECH PROJECT, 2021
** log
** File description:
** log
*/

#ifndef LOG_HPP_
#define LOG_HPP_

#include <string>
#include <fstream>

class Log {
public:
    Log();
    Log(std::string str);
    ~Log();
    bool write(std::string str);
    bool clear();
protected:
private:
};

#endif /* !LOG_HPP_ */
