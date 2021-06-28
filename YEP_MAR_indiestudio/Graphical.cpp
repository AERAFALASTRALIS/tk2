/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Graphical.hpp"
#include "Input.hpp"
#include "Parametre.hpp"
#include "Assets3DHandler.hpp"
#include "Assets2DHandler.hpp"

Graphical::Graphical(Input *input)
{
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(Parametre::defaultScreenWidth,
                               Parametre::defaultScreenHeight), 32, false, true, true, input);
    driver = device->getVideoDriver();
    sceneManager = device->getSceneManager();
    this->device->setWindowCaption(NAME_WINDOW);
    this->actual_scene = 0;
    this->_input = input;
    this->_reload = true;
    this->fill_mesh();
    this->fill_texture();
    this->_asset2d = new Assets2DHandler(this->_texture, this->driver);
    this->_asset3d = new Assets3DHandler(this->sceneManager, this->_texture, this->_mesh);
}

Graphical::~Graphical()
{
    this->driver->drop();
}

void Graphical::end_scene()
{
    this->driver->endScene();
}

void Graphical::fill_mesh()
{
    this->_mesh[Graphical::typeMesh::STAGE] = this->sceneManager->getMesh("asset_graphical/mur.MD3");
    this->_mesh[Graphical::typeMesh::GROUND] = this->sceneManager->getMesh("asset_graphical/sol.MD3");
    this->_mesh[Graphical::typeMesh::BOX] = this->sceneManager->getMesh("asset_graphical/box.MD3");
    this->_mesh[Graphical::typeMesh::BOMB] = this->sceneManager->getMesh("asset_graphical/box.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR1_AFK] = this->sceneManager->getMesh("asset_graphical/Crash_idle.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR1_RUN] = this->sceneManager->getMesh("asset_graphical/Crash_run.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR2_AFK] = this->sceneManager->getMesh("asset_graphical/Crash_idle.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR2_RUN] = this->sceneManager->getMesh("asset_graphical/Crash_run.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR3_AFK] = this->sceneManager->getMesh("asset_graphical/Crash_idle.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR3_RUN] = this->sceneManager->getMesh("asset_graphical/Crash_run.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR4_AFK] = this->sceneManager->getMesh("asset_graphical/Crash_idle.MD3");
    this->_mesh[Graphical::typeMesh::JOUEUR4_RUN] = this->sceneManager->getMesh("asset_graphical/Crash_run.MD3");
}

void Graphical::fill_texture()
{
    this->_texture[Graphical::typeTexture::PAUSE_TITLE] = this->driver->getTexture("asset_graphical/pause.png");
    this->_texture[Graphical::typeTexture::MAP] = this->driver->getTexture("asset_graphical/mur.jpg");
    this->_texture[Graphical::typeTexture::SOL] = this->driver->getTexture("asset_graphical/sol2.jpg");
    this->_texture[Graphical::typeTexture::BOITE] = this->driver->getTexture("asset_graphical/box.jpg");
    this->_texture[Graphical::typeTexture::BOMBE] = this->driver->getTexture("asset_graphical/bombe.png");
    this->_texture[Graphical::typeTexture::JOUEUR1_JPG] = this->driver->getTexture("asset_graphical/Crash_texture.png");
    this->_texture[Graphical::typeTexture::JOUEUR2_JPG] = this->driver->getTexture("asset_graphical/Crash_texture3.png");
    this->_texture[Graphical::typeTexture::JOUEUR3_JPG] = this->driver->getTexture("asset_graphical/Crash_texture2.png");
    this->_texture[Graphical::typeTexture::JOUEUR4_JPG] = this->driver->getTexture("asset_graphical/Crash_texture4.png");
    this->_texture[Graphical::typeTexture::JOUEUR_BACKGROUND] = this->driver->getTexture("asset_graphical/player_back.png");
    this->_texture[Graphical::typeTexture::TOUCHE_J1_ZQSD] = this->driver->getTexture("asset_graphical/button_J1.png");
    this->_texture[Graphical::typeTexture::TOUCHE_J2_TFGH] = this->driver->getTexture("asset_graphical/button_J2.png");
    this->_texture[Graphical::typeTexture::TOUCHE_J3_IJKL] = this->driver->getTexture("asset_graphical/button_J3.png");
    this->_texture[Graphical::typeTexture::TOUCHE_J4_FLECH] = this->driver->getTexture("asset_graphical/button_J4.png");

    this->_texture[Graphical::typeTexture::SELECT_PLAYER_NAME_JOUEUR] = this->driver->getTexture("asset_graphical/player_name_joueur.png");
    this->_texture[Graphical::typeTexture::SELECT_PLAYER_NAME_ROBOT] = this->driver->getTexture("asset_graphical/player_name_robot.png");
    this->_texture[Graphical::typeTexture::SELECT_PLAYER_NAME_AFK] = this->driver->getTexture("asset_graphical/player_name_afk.png");
    this->_texture[Graphical::typeTexture::SELECT_FLECHE_LEFT] = this->driver->getTexture("asset_graphical/select_left.png");
    this->_texture[Graphical::typeTexture::SELECT_FLECHE_RIGHT] = this->driver->getTexture("asset_graphical/select_right.png");
    this->_texture[Graphical::typeTexture::SELECT_BUTTON_RETURN] = this->driver->getTexture("asset_graphical/retour_no_focus.png");
    this->_texture[Graphical::typeTexture::SELECT_BUTTON_RETURN_OVER] = this->driver->getTexture("asset_graphical/retour_focus.png");
    this->_texture[Graphical::typeTexture::SELECT_BUTTON_PLAY] = this->driver->getTexture("asset_graphical/go_no_focus.png");
    this->_texture[Graphical::typeTexture::SELECT_BUTTON_PLAY_OVER] = this->driver->getTexture("asset_graphical/go_focus.png");

    //this->_texture[Graphical::typeTexture::] = this->driver->getTexture("asset_graphical/select_left.png");

    this->_texture[Graphical::typeTexture::MAIN_MENU_BACKGROUD] = this->driver->getTexture("asset_graphical/background.jpg");
    this->_texture[Graphical::typeTexture::MAIN_MENU_TITLE] = this->driver->getTexture("asset_graphical/title.png");
    this->_texture[Graphical::typeTexture::MAIN_MENU_BUTTON_PLAY] = this->driver->getTexture("asset_graphical/jouer_no_focus.png");
    this->_texture[Graphical::typeTexture::MAIN_MENU_BUTTON_PLAY_OVER] = this->driver->getTexture("asset_graphical/jouer_focus.png");
    this->_texture[Graphical::typeTexture::MAIN_MENU_BUTTON_QUIT] = this->driver->getTexture("asset_graphical/quitter_no_focus.png");
    this->_texture[Graphical::typeTexture::MAIN_MENU_BUTTON_QUIT_OVER] = this->driver->getTexture("asset_graphical/quitter_focus.png");
}

void Graphical::drawAll()
{
    this->sceneManager->drawAll();
}

void Graphical::setreload(bool reload)
{
    this->_reload = reload;
}

irr::video::ITexture* Graphical::get_texture_by_typeTexture(typeTexture typeTexture)
{
    return (this->_texture[typeTexture]);
}

irr::core::dimension2du Graphical::get_driver_screen_size() const
{
    return (this->driver->getScreenSize());
}

Assets2DHandler *Graphical::get_asset2D()
{
    return (this->_asset2d);
}

Assets3DHandler *Graphical::get_asset3D()
{
    return (this->_asset3d);
}

bool Graphical::get_reload() const
{
    return (this->_reload);
}

Input *Graphical::get_input() const
{
    return (this->_input);
}

/*void Graphical::add_camera_in_scene_manager(irr::scene::ISceneManager* parent, irr::core::vector3df position, irr::core::vector3df lookat)
{
    parent->addCameraSceneNode(0, position, lookat);
}*/

void Graphical::add_camera_in_scene_manager(irr::core::vector3df position, irr::core::vector3df lookat)
{
    this->sceneManager->addCameraSceneNode(0, position, lookat);
}


void Graphical::set_actual_scene(short int aled)
{
    this->actual_scene = aled;
}

short int Graphical::get_actual_scene() const
{
    return (this->actual_scene);
}

irr::IrrlichtDevice* Graphical::getdevice() const
{
    return this->device;
}

void Graphical::setdevice(irr::IrrlichtDevice* _device)
{
    this->device = _device;
}

irr::video::IVideoDriver* Graphical::getdriver() const
{
    return this->driver;
}

void Graphical::setdriver(irr::video::IVideoDriver* _driver)
{
    this->driver = _driver;
}

irr::scene::ISceneManager* Graphical::getsceneManager() const
{
    return this->sceneManager;
}

void Graphical::setsceneManager(irr::scene::ISceneManager* _sceneManager)
{
    this->sceneManager = _sceneManager;
}
