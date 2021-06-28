/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Assets3DHandler.hpp"

Assets3DHandler::Assets3DHandler(irr::scene::ISceneManager *smgr, std::map<Graphical::typeTexture, irr::video::ITexture *> textures,
                                 std::map<Graphical::typeMesh, irr::scene::IAnimatedMesh *> mesh)
{
    this->_smgr = smgr;
    this->_mesh = mesh;
    this->_textures = textures;
    this->_index = 0;
    this->fillPosRotTab();
}

Assets3DHandler::~Assets3DHandler()
{
}

bool Assets3DHandler::destroyById(unsigned id)
{
    std::list<MeshModel3D *>::iterator it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it)
    {
        if ((*it)->id == id)
        {
            (*it)->animMeshNode->remove();
            it = this->_assets3DList.erase(it);
            return (true);
        }
    }
    return (false);
}

void Assets3DHandler::destroyAllAsset()
{
    std::list<MeshModel3D *>::iterator it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it)
    {
        (*it)->animMeshNode->remove();
    }
    this->_assets3DList.clear();
}

void Assets3DHandler::destroyByListId(std::list<unsigned> listId)
{
    std::list<unsigned>::iterator	it;

    for (it = listId.begin(); it != listId.end(); ++it)
    {
        this->destroyById((*it));
    }
}

unsigned Assets3DHandler::createMeshModel3D(Graphical::typeObj type, irr::core::vector3df pos, irr::core::vector3df rot)
{
    MeshModel3D	*model = new MeshModel3D;

    if (type == Graphical::JOUEUR1) {
        model->animLoopList[AFK] = this->_mesh[Graphical::JOUEUR1_AFK];
        model->animLoopList[RUN] = this->_mesh[Graphical::JOUEUR1_RUN];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::JOUEUR1_JPG]);
        model->animMeshNode->setFrameLoop(0, 60);
        model->animMeshNode->setAnimationSpeed(30);
        model->texture = this->_textures[Graphical::JOUEUR1_JPG];
        model->animMeshNode->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
        model->state = 2;
    } else if (type == Graphical::JOUEUR2) {
        model->animLoopList[AFK] = this->_mesh[Graphical::JOUEUR2_AFK];
        model->animLoopList[RUN] = this->_mesh[Graphical::JOUEUR2_RUN];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::JOUEUR2_JPG]);
        model->animMeshNode->setFrameLoop(0, 60);
        model->animMeshNode->setAnimationSpeed(30);
        model->texture = this->_textures[Graphical::JOUEUR2_JPG];
        model->animMeshNode->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
        model->state = 2;
    } else if (type == Graphical::JOUEUR3) {
        model->animLoopList[AFK] = this->_mesh[Graphical::JOUEUR3_AFK];
        model->animLoopList[RUN] = this->_mesh[Graphical::JOUEUR3_RUN];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::JOUEUR3_JPG]);
        model->animMeshNode->setFrameLoop(0, 60);
        model->texture = this->_textures[Graphical::JOUEUR3_JPG];
        model->animMeshNode->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
        model->state = 2;
    } else if (type == Graphical::JOUEUR4) {
        model->animLoopList[AFK] = this->_mesh[Graphical::JOUEUR4_AFK];
        model->animLoopList[RUN] = this->_mesh[Graphical::JOUEUR4_RUN];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::JOUEUR4_JPG]);
        model->animMeshNode->setFrameLoop(0, 60);
        model->animMeshNode->setAnimationSpeed(30);
        model->texture = this->_textures[Graphical::JOUEUR4_JPG];
        model->animMeshNode->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
        model->state = 2;
    } else if (type == Graphical::STAGE1) {
        model->animLoopList[AFK] = this->_mesh[Graphical::STAGE];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::MAP]);
        model->texture = this->_textures[Graphical::MAP];
        model->state = 0;
        //model->animMeshNode->setScale(irr::core::vector3df(10.3f, 10.3f, 10.3f));
    } else if (type == Graphical::SOL1) {
        model->animLoopList[AFK] = this->_mesh[Graphical::GROUND];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::SOL]);
        model->texture = this->_textures[Graphical::SOL];
        model->state = 0;
        //model->animMeshNode->setScale(irr::core::vector3df(10.3f, 10.3f, 10.3f));
    } else if (type == Graphical::BOITE1) {
        model->animLoopList[AFK] = this->_mesh[Graphical::BOX];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::BOITE]);
        model->texture = this->_textures[Graphical::BOITE];
        model->state = 1;
        //model->animMeshNode->setScale(irr::core::vector3df(10.3f, 10.3f, 10.3f));
    } else if (type == Graphical::BOMBE1) {
        model->animLoopList[AFK] = this->_mesh[Graphical::BOMB];
        model->animMeshNode = this->_smgr->addAnimatedMeshSceneNode(model->animLoopList[AFK]);
        model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->animMeshNode->setMaterialTexture(0, this->_textures[Graphical::BOMBE]);
        model->texture = this->_textures[Graphical::BOMBE];
        model->state = 3;
        //model->animMeshNode->setScale(irr::core::vector3df(10.3f, 10.3f, 10.3f));
    } else
        return (-1);
    model->id = this->_index;
    // std::cout << model->id << std::endl;
    this->_index++;
    this->_assets3DList.push_back(model);
    this->setPositionbyId(pos, model->id);
    this->setRotationbyId(rot, model->id);
    return (model->id);
}

irr::core::vector3df Assets3DHandler::getPositionById(unsigned id)
{
    std::list<MeshModel3D *>::iterator	it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id) {
            return ((*it)->animMeshNode->getPosition());
        }
    }
}

int Assets3DHandler::getStateById(unsigned id)
{
    std::list<MeshModel3D *>::iterator	it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id) {
            return ((*it)->state);
        }
    }
}

int Assets3DHandler::getIndex()
{
    int i = this->_index;
    return (i);
}

void Assets3DHandler::setPositionbyId(irr::core::vector3df pos, unsigned id)
{
    std::list<MeshModel3D *>::iterator	it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id) {
            (*it)->animMeshNode->setPosition(pos);
            break;
        }
    }
}

void Assets3DHandler::setRotationbyId(irr::core::vector3df pos, unsigned id)
{
    std::list<MeshModel3D *>::iterator	it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id) {
            (*it)->animMeshNode->setRotation(pos);
            break;
        }
    }
}

void Assets3DHandler::fillPosRotTab()
{
    this->_menuPosTab.push_back(irr::core::vector3df(-215, 10, -5)); // ICI
    this->_menuPosTab.push_back(irr::core::vector3df(-70, 10, -5));
    this->_menuPosTab.push_back(irr::core::vector3df(70, 10, -5));
    this->_menuPosTab.push_back(irr::core::vector3df(215, 10, -5));

    this->_menuRotTab.push_back(irr::core::vector3df(0, -30, 0));
    this->_menuRotTab.push_back(irr::core::vector3df(0, -10, 0));
    this->_menuRotTab.push_back(irr::core::vector3df(0, 10, 0));
    this->_menuRotTab.push_back(irr::core::vector3df(0, 30, 0));
}

irr::core::vector3df Assets3DHandler::getBasicMenuPosbyId(int id)
{
    int	i = 0;
    std::vector<irr::core::vector3df>::iterator	it;

    for (it = this->_menuPosTab.begin(); it != this->_menuPosTab.end(); ++it) {
        if (i == id)
            return((*it));
        i += 1;
    }
    return (irr::core::vector3df(0, 0, 0));
}

irr::core::vector3df Assets3DHandler::getBasicMenuRotbyId(int id)
{
    int i = 0;
    std::vector<irr::core::vector3df>::iterator	it;

    for (it = this->_menuRotTab.begin(); it != this->_menuRotTab.end(); ++it) {
        if (i == id)
            return((*it));
        i += 1;
    }
    return (irr::core::vector3df(0, 0, 0));
}

MeshModel3D* Assets3DHandler::getModelById(unsigned id)
{
    std::list<MeshModel3D *>::iterator it;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id)
            return ((*it));
    }
}

bool Assets3DHandler::modifyMesh(Graphical::typeObj type, unsigned id)
{
    std::list<MeshModel3D *>::iterator it;
    MeshModel3D *model;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id) {
            model = this->getModelById(this->createMeshModel3D(type, (*it)->animMeshNode->getPosition(), (*it)->animMeshNode->getRotation()));
            this->destroyById(id);
            model->id = id;
            return (true);
        }
    }
    return (false);
}

void Assets3DHandler::changeTexture(unsigned id, Graphical::typeTexture texture)
{
    std::list<MeshModel3D *>::iterator it;
    MeshModel3D *model;

    for (it = this->_assets3DList.begin(); it != this->_assets3DList.end(); ++it) {
        if ((*it)->id == id) {
            model = this->getModelById(id);
            model->animMeshNode->setMaterialTexture(0, this->_textures[texture]);
            model->texture = this->_textures[texture];
            return;
        }
    }
}

void Assets3DHandler::changeAnimationById(unsigned id, anim anim)
{
    MeshModel3D	*model = this->getModelById(id);

    if (model->animMeshNode->getMesh() != model->animLoopList[anim]) {
        model->animMeshNode->setMesh(model->animLoopList[anim]);
        model->animMeshNode->setMaterialTexture(0, model->texture);
    }
}
