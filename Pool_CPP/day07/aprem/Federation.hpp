/*
** EPITECH PROJECT, 2021
** fede
** File description:
** fede
*/

#ifndef FEDERATION_H_
#define FEDERATION_H_

#include "WarpSystem.hpp"
#include <iostream>

namespace Federation
{
    namespace Starfleet
    {
        class Ship
        {
        public:
            Ship(int lenght, int width, std::string name, short maxWarp);
            ~Ship(void);
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
        private:
            int _length;
            int _widht;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
        };
    };

    class Ship
    {
    public:
        Ship(int length, int width, std::string name);
        ~Ship(void);
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
    private:
        int _length;
        int _widht;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
    };
};

#endif
