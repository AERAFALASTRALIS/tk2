/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef ASSETS3DHANDLER_HPP
#define ASSETS3DHANDLER_HPP_

#include "Graphical.hpp"
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <math.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>

enum anim
{
    AFK,
    RUN,
    NONE
};

struct  MeshModel3D
{
    unsigned id;
    std::map<anim, irr::scene::IAnimatedMesh *> animLoopList;
    irr::scene::IAnimatedMeshSceneNode *animMeshNode;
    irr::video::ITexture *texture;
    int state; // 0 = non desctructible | 1 = cassable | 2 = joueur | 3 = bombes
};

class Assets3DHandler
{
    public:

        Assets3DHandler(irr::scene::ISceneManager *smgr, std::map<Graphical::typeTexture, irr::video::ITexture*> textures, std::map<Graphical::typeMesh, irr::scene::IAnimatedMesh*> mesh);
        ~Assets3DHandler();

        bool destroyById(unsigned id);
        void destroyAllAsset();
        void destroyByListId(std::list<unsigned> listId);
        unsigned createMeshModel3D(Graphical::typeObj type, irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), irr::core::vector3df rot = irr::core::vector3df(0, 0, 0));
        irr::core::vector3df getPositionById(unsigned id);
        int getStateById(unsigned id);
        int getHpById(unsigned id);
        void setHpById(unsigned id);
        int getNbBoomById(unsigned id);
        void setPositionbyId(irr::core::vector3df pos, unsigned id);
        void setRotationbyId(irr::core::vector3df pos, unsigned id);
        irr::core::vector3df getBasicMenuPosbyId(int id);
        irr::core::vector3df getBasicMenuRotbyId(int id);
        MeshModel3D	*getModelById(unsigned id);
        bool modifyMesh(Graphical::typeObj type, unsigned id);
        void changeTexture(unsigned id, Graphical::typeTexture texture);
        void changeAnimationById(unsigned id, anim anim);
        bool displayAll3DAsset();
        int getIndex();
    protected:
        void fillPosRotTab();
        std::vector<irr::core::vector3df> _menuPosTab;
        std::vector<irr::core::vector3df> _menuRotTab;
        irr::scene::ISceneManager *_smgr;
        std::map<Graphical::typeTexture, irr::video::ITexture*> _textures;
        std::map<Graphical::typeMesh, irr::scene::IAnimatedMesh*> _mesh;
        std::list<MeshModel3D *> _assets3DList;
        unsigned _index;
};

#endif //ASSETS3DHANDLER_HPP_
