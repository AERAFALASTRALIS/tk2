/*
** EPITECH PROJECT, 2021
** warm
** File description:
** warm
*/

#ifndef WARPSYSTEM_H_
#define WARPSYSTEM_H_

namespace WarpSystem
{
    class QuantumReactor
    {
    public:
        QuantumReactor(void);
        ~QuantumReactor(void);
        bool isStable(void);
        void setStability(bool value);
    private:
        bool _stability;
    };

    class Core
    {
    public:
        Core(QuantumReactor *coreReactor);
        ~Core(void);
        QuantumReactor *checkReactor();
    private:
        QuantumReactor *_coreReactor;
    };
};

#endif
