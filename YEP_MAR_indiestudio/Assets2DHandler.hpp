/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef ASSETS2DHANDLER_HPP_
#define ASSETS2DHANDLER_HPP_

#include "Graphical.hpp"
#include <list>

struct Asset2D
{
    unsigned id;
    float posX;
    float posY;
    Graphical::typeTexture type;
    irr::video::ITexture *img;
};

class Assets2DHandler
{
    public:
        Assets2DHandler(std::map<Graphical::typeTexture, irr::video::ITexture*> textures, irr::video::IVideoDriver *driver);
        ~Assets2DHandler();

        bool destroy2DAsset(unsigned id);
        unsigned create2DAsset(Graphical::typeTexture typeTexture, float posX, float posY);
        bool modify2DAsset(Graphical::typeTexture typeTexture, unsigned id, float posX = -1, float posY = -1);
        bool destroyAll2DAsset();
        bool displayAll2DAsset();
        bool displayById(unsigned id);
        unsigned long getSizeList();
        Asset2D *getAsset2DById(unsigned id);

    protected:
        irr::video::IVideoDriver *driver;
        std::map<Graphical::typeTexture, irr::video::ITexture*>	textures;
        std::list<Asset2D *> Asset2DList;
        unsigned index;
    private:
};

#endif //ASSETS2DHANDLER_HPP_
